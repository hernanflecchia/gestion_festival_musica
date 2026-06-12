#include <stdio.h>
#include <stdlib.h>
#include "interfaz/menus.h"
#include "logica/gestor_archivos.h"
#include "logica/colecciones.h"

int main() {
    // ==========================================
    // INICIALIZACIÓN
    // ==========================================
    // Inicializamos los arreglos dinámicos y cargamos del disco
    ColeccionArtistas colArtistas = inicializarColeccionArtistas();
    cargarArtistasDesdeArchivo(&colArtistas);
    ColeccionEscenarios colEscenarios = inicializarColeccionEscenarios();
    ColeccionPresentaciones colPresentaciones = inicializarColeccionPresentaciones();
    
    // 1. Verificamos y creamos el archivo de usuarios si es necesario
    inicializarArchivoUsuarios();

    int opcionInicio;
    Usuarios usuarioLogueado;

    // ==========================================
    // EJECUCIÓN (Bucle principal)
    // ==========================================
    do {
        opcionInicio = mostrarMenuInicio();

        switch(opcionInicio) {
            case 1:
                Usuarios intento = pedirCredencialesUsuario("\n--- INICIO DE SESION ---");
                usuarioLogueado = validarLogin(intento);
                if (usuarioLogueado.rol == 1) {
                    menuAdmin(usuarioLogueado, &colArtistas, &colEscenarios, &colPresentaciones);
                } 
                else if (usuarioLogueado.rol == 0) {
                    // menuUsuario(usuarioLogueado); // (Para cuando lo programes)
                    printf("\nBienvenido Usuario Normal. (Menu en construccion)\n");
                } 
                else {
                    // Entra acá si el rol es -1 (el centinela)
                    printf("\nError: Nombre de usuario o contraseña incorrectos.\n");
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
                printf("\nOpción inválida. Intente de nuevo.\n");
        }
    } while (opcionInicio != 3);

    // ==========================================
    // 3. LIMPIEZA Y CIERRE
    // ==========================================
    // Vaciamos el Heap llamando a tu TDA antes de apagar el programa
    liberarColeccionArtistas(&colArtistas);
    liberarColeccionEscenarios(&colEscenarios);
    liberarColeccionPresentaciones(&colPresentaciones);

    return 0;
}