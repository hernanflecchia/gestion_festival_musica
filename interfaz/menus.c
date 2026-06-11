#include <stdio.h>
#include "scanner.h"
#include "../dominio/usuario.h"
#include "../dominio/artista.h"
#include "../logica/colecciones.h"
#include "../logica/gestor_archivos.h"

int mostrarMenuInicio(void) {
    printf("        INICIO  \n\n");
    printf("    1. Iniciar sesion \n");
    printf("    2. Crear usuario \n");
    printf("    3. Salir \n");

    return scanInt();
}

Usuarios pedirCredencialesUsuario(const char* titulo) {
    Usuarios usuario;

    printf("%s\n", titulo); 
    printf("Ingrese nombre de usuario: ");
    scanString(usuario.nombre, DIM_USUARIO_NOMBRE);
    printf("Ingrese contraseña: ");
    scanString(usuario.contrasenia, DIM_USUARIO_CONTRASENIA);

    return usuario;
}

Artista pedirDatosNuevoArtista(void) {
    Artista nuevo;
    printf("\n--- ALTA DE ARTISTA ---\n");
    printf("Ingrese el nombre del artista: ");
    scanString(nuevo.nombre, 50);
    printf("Ingrese el genero musical: ");
    scanString(nuevo.genero, 30);
    return nuevo;
}

int mostrarMenuArtistas(void) {
    printf("\n--- GESTION DE ARTISTAS ---\n");
    printf("1. Dar de alta nuevo Artista\n");
    printf("2. Modificar Artista existente\n");
    printf("3. Dar de baja (Eliminar) Artista\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}

void menuAdmin(Usuarios usuario, ColeccionArtistas* cArt, ColeccionEscenarios* cEsc, ColeccionPresentaciones* cPres) {
    int opcionPrincipal;
    int opcionSubMenu;

    do {
        printf("\n=== PANEL DE ADMINISTRADOR ===\n");
        printf("Bienvenido/a, %s\n", usuario.nombre);
        printf("1. Gestionar Artistas\n");
        printf("2. Gestionar Escenarios\n");
        printf("3. Gestionar Presentaciones\n");
        printf("4. Ver Listados y Reportes\n");
        printf("0. Cerrar Sesion\n");
        printf("Elija una opcion: ");
        opcionPrincipal = scanInt();

        switch(opcionPrincipal) {
            case 1:
                do {
                    opcionSubMenu = mostrarMenuArtistas();
                    
                    switch(opcionSubMenu) {
                        case 1:
                        {
                            Artista nuevoArtista = pedirDatosNuevoArtista();
                            // Intentamos agregarlo a la memoria dinámica
                            if (agregarArtista(cArt, nuevoArtista) == 1) {
                                // Si la memoria RAM lo aceptó, lo mapeamos al formato de archivo
                                ArtistaArchivo nuevoArch = transformarAArtistaArchivo(nuevoArtista);
                                // Finalmente lo guardamos en el disco
                                if (guardarArtistaEnArchivo(nuevoArch) == 1) {
                                    printf("\n[Exito] Artista agregado y guardado correctamente.\n");
                                } else {
                                    printf("\n[Error] El artista esta en memoria pero fallo el guardado en disco.\n");
                                }
                                
                            } else {
                                printf("\n[Error] No se pudo agregar al artista por falta de memoria.\n");
                            }
                            break;
                        }
                        case 2:
                            int indice;
                            printf("\nIngrese el indice del artista a modificar: ");
                            scanf("%d", &indice);
                            
                            // 1. Buscamos el artista original para ver si existe (usando tu funcion validada)
                            Artista aModificar = obtenerArtista(cArt, indice);
                            
                            if (aModificar.id != -1) {
                                // 2. Pedimos los datos nuevos (podes reciclar tu funcion de pedirDatos)
                                printf("\nNuevo nombre: ");
                                fflush(stdin);
                                gets(aModificar.nombre);
                                printf("Nuevo genero: ");
                                fflush(stdin);
                                gets(aModificar.genero);
                                
                                // 3. Actualizamos la memoria RAM
                                if (actualizarArtista(cArt, indice, aModificar) == 1) {
                                    
                                    // 4. Mapeamos y actualizamos el Disco
                                    ArtistaArchivo archModificado = transformarAArtistaArchivo(aModificar);
                                    
                                    if (modificarArtistaEnArchivo(archModificado) == 1) {
                                        printf("\n[Exito] Artista modificado en memoria y disco.\n");
                                    } else {
                                        printf("\n[Error] Modificado en memoria pero no en disco.\n");
                                    }
                                }
                            } else {
                                printf("\n[Error] Indice invalido. No existe el artista.\n");
                            }
                            break;
                        case 3:
                            // Pedir ID, buscarlo y cambiarle el valido a 'N' en el archivo
                            printf("\n(En construccion...)\n");
                            break;
                        case 0:
                            // Simplemente vuelve al menú principal
                            break;
                        default:
                            printf("\nOpcion invalida.\n");
                    }
                } while(opcionSubMenu != 0);
                break;

            case 2:
                // Aca armarías el do-while para ESCENARIOS
                printf("\n(Menu Escenarios en construccion...)\n");
                break;
                
            case 3:
                // Aca armarías el do-while para PRESENTACIONES
                printf("\n(Menu Presentaciones en construccion...)\n");
                break;

            case 0:
                printf("\nCerrando sesion de %s...\n", usuario.nombre);
                break;

            default:
                printf("\nOpcion invalida.\n");
        }
    } while(opcionPrincipal != 0);
}

int pedirIdGenerico(const char* nombreEntidad) {
    printf("\nIngrese el ID del %s: ", nombreEntidad);
    return scanInt();
}