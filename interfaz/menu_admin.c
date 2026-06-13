#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "menu_artistas.h"
#include "menu_escenarios.h"
#include "menu_presentaciones.h"
#include "../dominio/usuario.h"
#include "../dominio/artista.h"
#include "../dominio/escenario.h"
#include "../logica/coleccion_artistas.h"
#include "../logica/coleccion_escenarios.h"
#include "../logica/coleccion_presentaciones.h"
#include "../logica/gestor_archivo_artistas.h"
#include "../logica/gestor_archivo_escenarios.h"
#include "../logica/gestor_archivo_presentaciones.h"

void menuAdmin(Usuarios usuario, ColeccionArtistas* cArt, ColeccionEscenarios* cEsc, ColeccionPresentaciones* cPres) {
    int opcionPrincipal;
    int opcionSubMenu;
    int idBuscado;
    int indice;

    do {
        system("clear");
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
                            nuevoArtista.id = obtenerSiguienteIdArtista(cArt);
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
                            printf("\n--- MODIFICAR ARTISTA ---\n");
                            printf("Para modificar un artista, primero ingrese su ID.\n");
                            idBuscado = scanInt();
                            indice = buscarIndiceArtistaPorId(cArt, idBuscado);
                            if (indice != -1) {
                                Artista aModificar = obtenerArtista(cArt, indice);
                                aModificar = pedirDatosModificadosArtista(aModificar);                             
                                if (actualizarArtista(cArt, indice, aModificar) == 1) {
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
                            printf("\n--- ELIMINAR ARTISTA ---\n");
                            printf("Para eliminar un artista, primero ingrese su ID.\n");
                            idBuscado = scanInt();
                            indice = buscarIndiceArtistaPorId(cArt, idBuscado);
                            if (indice != -1) {
                                eliminarArtistaDeMemoria(cArt, indice);
                                if (bajaLogicaArtistaEnArchivo(idBuscado) == 1) {
                                    printf("\n[Exito] Artista borrado de la memoria y del disco correctamente.\n");
                                    // Borrar en cascada
                                    int cantMemoria = eliminarPresentacionesDeMemoriaPorArtista(cPres, idBuscado);
                                    int cantDisco = bajaLogicaPresentacionesEnArchivoPorArtista(idBuscado);
                                    // Verificamos si hubo presentaciones afectadas
                                    if (cantMemoria > 0 || cantDisco > 0) {
                                        printf("[Exito] Se borraron %d presentaciones en Memoria y %d en disco asociadas a este artista.\n", cantMemoria, cantDisco);
                                    } else {
                                        printf("[Info] El artista no tenia presentaciones programadas activas.\n");
                                    }
                                } else {
                                    printf("\n[Error] Se borró de memoria pero falló la escritura en el archivo.\n");
                                }
                            } else {
                                printf("\n[Error] El ID ingresado no existe o ya fue dado de baja previamente.\n");
                            }
                            break;
                        case 4:
                            printf("\n--- LISTADO DE ARTISTAS ---\n");
                            int cantidad = obtenerCantidadArtistas(cArt);
                            if (cantidad == 0) {
                                printf("No hay artistas cargados en el sistema.\n");
                            } else {
                                mostrarListadoArtistas(cArt);
                            }
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
                do {
                    opcionSubMenu = mostrarMenuEscenarios();
                    switch(opcionSubMenu) {
                        case 1:
                        {
                            Escenario nuevoEscenario = pedirDatosNuevoEscenario();
                            nuevoEscenario.id = obtenerSiguienteIdEscenario(cEsc);
                            // Intentamos agregarlo a la memoria dinámica
                            if (agregarEscenario(cEsc, nuevoEscenario) == 1) {
                                // Si la memoria RAM lo aceptó, lo mapeamos al formato de archivo
                                EscenarioArchivo nuevoArch = transformarAEscenarioArchivo(nuevoEscenario);
                                // Finalmente lo guardamos en el disco
                                if (guardarEscenarioEnArchivo(nuevoArch) == 1) {
                                    printf("\n[Exito] Escenario agregado y guardado correctamente.\n");
                                } else {
                                    printf("\n[Error] El escenario esta en memoria pero fallo el guardado en disco.\n");
                                }
                                
                            } else {
                                printf("\n[Error] No se pudo agregar al escenario por falta de memoria.\n");
                            }
                            break;
                        }
                        case 2:
                            printf("\n--- MODIFICAR ESCENARIO ---\n");
                            printf("Para modificar un escenario, primero ingrese su ID.\n");
                            idBuscado = scanInt();
                            indice = buscarIndiceEscenarioPorId(cEsc, idBuscado);
                            if (indice != -1) {
                                Escenario aModificar = obtenerEscenario(cEsc, indice);
                                aModificar = pedirDatosModificadosEscenario(aModificar);                             
                                if (actualizarEscenario(cEsc, indice, aModificar) == 1) {
                                    EscenarioArchivo archModificado = transformarAEscenarioArchivo(aModificar);
                                    if (modificarEscenarioEnArchivo(archModificado) == 1) {
                                        printf("\n[Exito] Escenario modificado en memoria y disco.\n");
                                    } else {
                                        printf("\n[Error] Modificado en memoria pero no en disco.\n");
                                    }
                                }
                            } else {
                                printf("\n[Error] Indice invalido. No existe el escenario.\n");
                            }
                            break;
                        case 3:
                            printf("\n--- ELIMINAR ESCENARIO ---\n");
                            printf("Para eliminar un escenario, primero ingrese su ID.\n");
                            idBuscado = scanInt();
                            indice = buscarIndiceEscenarioPorId(cEsc, idBuscado);
                            if (indice != -1) {
                                eliminarEscenarioDeMemoria(cEsc, indice);
                                if (bajaLogicaEscenarioEnArchivo(idBuscado) == 1) {
                                    printf("\n[Exito] Escenario borrado de la memoria y del disco correctamente.\n");
                                    // Borrar en cascada
                                    int cantMemoria = eliminarPresentacionesDeMemoriaPorEscenario(cPres, idBuscado);
                                    int cantDisco = bajaLogicaPresentacionesEnArchivoPorEscenario(idBuscado);
                                    // Verificamos si hubo presentaciones afectadas
                                    if (cantMemoria > 0 || cantDisco > 0) {
                                        printf("[Exito] Se borraron %d presentaciones en Memoria y %d en disco asociadas a este escenario.\n", cantMemoria, cantDisco);
                                    } else {
                                        printf("[Info] El escenario no tenia presentaciones programadas activas.\n");
                                    }
                                } else {
                                    printf("\n[Error] Se borró de memoria pero falló la escritura en el archivo.\n");
                                }
                            } else {
                                printf("\n[Error] El ID ingresado no existe o ya fue dado de baja previamente.\n");
                            }
                            break;
                        case 4:
                            printf("\n--- LISTADO DE ESCENARIOS ---\n");
                            int cantidad = obtenerCantidadEscenarios(cEsc);
                            if (cantidad == 0) {
                                printf("No hay escenarios cargados en el sistema.\n");
                            } else {
                                mostrarListadoEscenarios(cEsc);
                            }
                            break;
                        case 0:
                            // Simplemente vuelve al menú principal
                            break;
                        default:
                            printf("\nOpcion invalida.\n");
                    }
                } while(opcionSubMenu != 0);
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