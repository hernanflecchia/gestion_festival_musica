#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "menu_artistas.h"
#include "menu_escenarios.h"
#include "menu_presentaciones.h"
#include "../dominio/usuario.h"
#include "../logica/coleccion_artistas.h"
#include "../logica/coleccion_escenarios.h"
#include "../logica/coleccion_presentaciones.h"
#include "../logica/gestor_archivo_artistas.h"
#include "../logica/gestor_archivo_escenarios.h"
#include "../logica/gestor_archivo_presentaciones.h"

void menuUsuario(Usuarios usuario, ColeccionArtistas* cArt, ColeccionEscenarios* cEsc, ColeccionPresentaciones* cPres) {
    int opcion;
    int idBuscado;
    int cantidad;

    do {
        system("clear");
        printf("Bienvenido/a, %s\n", usuario.nombre);
        printf("\n========================================\n");
        printf("         FESTIVAL - MENU DE USUARIO       \n");
        printf("========================================\n");
        printf("1. Ver listado de todos los Artistas\n");
        printf("2. Ver listado de todos los Escenarios\n");
        printf("3. Ver cronograma completo (Todas las Presentaciones)\n");
        printf("4. Filtrar presentaciones por Artista\n");
        printf("5. Filtrar presentaciones por Escenario\n");
        printf("0. Volver al menu principal\n");
        printf("Elija una opcion: ");
        
        opcion = scanInt();
        
        switch (opcion) {
            case 1:
                printf("\n--- LISTADO DE ARTISTAS ---\n");
                cantidad = obtenerCantidadArtistas(cArt);
                if (cantidad == 0) {
                    printf("No hay artistas cargados en el sistema.\n");
                    printf("\nPresione Enter para continuar...");
                    getchar();
                } else {
                    ordenarColeccionArtistasAlfabeticamente(cArt);
                    mostrarListadoArtistas(cArt, false);
                    printf("¿Desea exportar los artistas a un TSV? (s/n)\n");
                    if (confirmar('s')) {
                        if (exportarArtistasATexto("artistas.tsv", cArt, false)) {
                            printf("[Exito] El listado fue guardado en 'artistas.tsv'.\n");
                        } else {
                            printf("[Error] No se pudo crear el archivo de exportacion.\n");
                        }
                        printf("\nPresione Enter para continuar...");
                        getchar();
                    }
                }
                break;
                
            case 2:
                printf("\n--- LISTADO DE ESCENARIOS ---\n");
                cantidad = obtenerCantidadEscenarios(cEsc);
                if (cantidad == 0) {
                    printf("No hay escenarios cargados en el sistema.\n");
                    printf("\nPresione Enter para continuar...");
                    getchar();
                } else {
                    ordenarColeccionEscenariosAlfabeticamente(cEsc);
                    mostrarListadoEscenarios(cEsc, false);
                    printf("¿Desea exportar los escenarios a un TSV? (s/n)\n");
                    if (confirmar('s')) {
                        if (exportarEscenariosATexto("escenarios.tsv", cEsc, false)) {
                            printf("[Exito] El listado fue guardado en 'escenarios.tsv'.\n");
                        } else {
                            printf("[Error] No se pudo crear el archivo de exportacion.\n");
                        }
                        printf("\nPresione Enter para continuar...");
                        getchar();
                    }
                }
                break;
                
            case 3:
                printf("\n--- CRONOGRAMA COMPLETO ---\n");
                cantidad = obtenerCantidadPresentaciones(cPres);
                if (cantidad == 0) {
                    printf("No hay presentaciones cargadas en el sistema.\n");
                    printf("\nPresione Enter para continuar...");
                    getchar();
                } else {
                    ordenarColeccionPresentacionesAlfabeticamente(cPres, cArt);
                    mostrarListadoPresentaciones(cPres, cArt, cEsc, false);
                    printf("¿Desea exportar las presentaciones a un TSV? (s/n)\n");
                    if (confirmar('s')) {
                        if (exportarPresentacionesATexto("presentaciones.tsv", cPres, cArt, cEsc, false)) {
                            printf("[Exito] El listado fue guardado en 'presentaciones.tsv'.\n");
                        } else {
                            printf("[Error] No se pudo crear el archivo de exportacion.\n");
                        }
                        printf("\nPresione Enter para continuar...");
                        getchar();
                    }
                }
                break;
                
            case 4:
                printf("\n--- PRESENTACIONES DEL ARTISTA ---\n");
                printf("Ingrese el id del artista: ");
                int idBuscado = scanInt();
                ordenarColeccionPresentacionesAlfabeticamente(cPres, cArt);
                int cantidad = mostrarListadoPresentacionesPorArtista(idBuscado, cPres, cArt, cEsc, false);
                if (cantidad != 0) {
                    printf("¿Desea exportar las presentaciones a un TSV? (s/n)\n");
                    if (confirmar('s')) {
                        ColeccionPresentaciones filtradas = filtrarPresentacionesPorArtista(cPres, idBuscado, cantidad);
                        if (exportarPresentacionesATexto("presentaciones_por_artista.tsv", &filtradas, cArt, cEsc, false)) {
                            printf("[Exito] El listado fue guardado en 'presentaciones_por_artista.tsv'.\n");
                        } else {
                            printf("[Error] No se pudo crear el archivo de exportacion.\n");
                        }
                        if (filtradas.arreglo != NULL) {
                            free(filtradas.arreglo);
                        }
                        printf("\nPresione Enter para continuar...");
                        getchar();
                    }
                } else {
                    printf("No se encontraron presentaciones para el artista con ID %d.\n", idBuscado);
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;
                
            case 5:
                printf("\n--- PRESENTACIONES EN EL ESCENARIO ---\n");
                printf("Ingrese el id del escenario: ");
                idBuscado = scanInt();
                ordenarColeccionPresentacionesAlfabeticamente(cPres, cArt);
                cantidad = mostrarListadoPresentacionesPorEscenario(idBuscado, cPres, cArt, cEsc, false);
                if (cantidad != 0) {
                    printf("¿Desea exportar las presentaciones a un TSV? (s/n)\n");
                    if (confirmar('s')) {
                        ColeccionPresentaciones filtradas = filtrarPresentacionesPorEscenario(cPres, idBuscado, cantidad);
                        if (exportarPresentacionesATexto("presentaciones_por_escenario.tsv", &filtradas, cArt, cEsc, false)) {
                            printf("[Exito] El listado fue guardado en 'presentaciones_por_escenario.tsv'.\n");
                        } else {
                            printf("[Error] No se pudo crear el archivo de exportacion.\n");
                        }
                        printf("\nPresione Enter para continuar...");
                        getchar();
                    }
                } else {
                    printf("No se encontraron presentaciones para el escenario con ID %d.\n", idBuscado);
                    printf("\nPresione Enter para continuar...");
                    getchar();
                }
                break;
                
            case 0:
                printf("\nVolviendo al menu principal...\n");
                break;
                
            default:
                printf("\n[Error] Opcion invalida. Intente nuevamente.\n");
                printf("\nPresione Enter para continuar...");
                getchar();
                break;
        }
    } while (opcion != 0);
}
