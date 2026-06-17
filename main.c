#include <stdio.h>
#include <stdlib.h>
#include "interfaz/menu_inicio.h"
#include "interfaz/menu_usuario.h"
#include "interfaz/menu_admin.h"
#include "logica/gestor_archivo_usuarios.h"
#include "logica/gestor_archivo_artistas.h"
#include "logica/gestor_archivo_escenarios.h"
#include "logica/gestor_archivo_presentaciones.h"
#include "logica/coleccion_artistas.h"
#include "logica/coleccion_escenarios.h"
#include "logica/coleccion_presentaciones.h"

int main() {
    // Verificamos y creamos el archivo de usuarios si es necesario
    inicializarArchivoUsuarios();
    // =========================================
    // Comentar o descomentar esta seccion si se quiere o no inicializar con datos de prueba
    inicializarArchivoArtistas();
    inicializarArchivoEscenarios();
    inicializarArchivoPresentaciones();
    // =========================================
    int opcionInicio;
    Usuarios usuarioLogueado;

    // =========================================
    // EJECUCIÓN (Bucle principal)
    // =========================================
    do {
        opcionInicio = mostrarMenuInicio();

        switch(opcionInicio) {
            case 1:
                Usuarios intento = pedirCredencialesUsuario("\n--- INICIO DE SESION ---");
                usuarioLogueado = validarLogin(intento);
                if (usuarioLogueado.rol == 1 || usuarioLogueado.rol == 0) {
                    // Inicializamos los arreglos dinámicos y cargamos del disco
                    ColeccionArtistas colArtistas = inicializarColeccionArtistas();
                    cargarArtistasDesdeArchivo(&colArtistas);
                    ColeccionEscenarios colEscenarios = inicializarColeccionEscenarios();
                    cargarEscenariosDesdeArchivo(&colEscenarios);
                    ColeccionPresentaciones colPresentaciones = inicializarColeccionPresentaciones();
                    cargarPresentacionesDesdeArchivo(&colPresentaciones);
                    if (usuarioLogueado.rol == 1) {
                        menuAdmin(usuarioLogueado, &colArtistas, &colEscenarios, &colPresentaciones);
                    } 
                    else if (usuarioLogueado.rol == 0) {
                        menuUsuario(usuarioLogueado, &colArtistas, &colEscenarios, &colPresentaciones);
                    }
                    // Vaciamos las colecciones y liberamos memoria antes de volver al menú de inicio
                    liberarColeccionArtistas(&colArtistas);
                    liberarColeccionEscenarios(&colEscenarios);
                    liberarColeccionPresentaciones(&colPresentaciones);
                } 
                else {
                    // Entra acá si el rol es -1 (el centinela)
                    printf("\nError: Nombre de usuario o contraseña incorrectos.\n");
                    printf("\nPresione Enter para volver al menu...");
                    getchar();
                }
                break;
            case 2:
                Usuarios nuevo = pedirCredencialesUsuario("\n--- REGISTRO DE NUEVO USUARIO ---");
                if (guardarUsuario(nuevo) == 1) {
                    printf("\n[Exito] Usuario '%s' creado correctamente. Ya puede iniciar sesion.\n", nuevo.nombre);
                } else {
                    printf("\n[Error Critico] No se pudo acceder al archivo de usuarios.\n");
                }
                break;
            case 3:
                printf("\nGuardando configuraciones y cerrando el sistema...\n");
                break;
            default:
                if(opcionInicio != 3){
                    printf("\nOpcion invalida. Intente de nuevo.\n");
                }
        }
    } while (opcionInicio != 3);

    return 0;
}
