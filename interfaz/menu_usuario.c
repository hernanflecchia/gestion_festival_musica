#include <stdio.h>
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

void menuUsuario(ColeccionArtistas* cArt, ColeccionEscenarios* cEsc, ColeccionPresentaciones* cPres) {
    int opcion;
    int idBuscado;
    int cantidad;

    do {
        printf("\nBienvenido Usuario Normal.\n");
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
                } else {
                    ordenarColeccionArtistasAlfabeticamente(cArt);
                    for (int i = 0; i < cantidad; i++) {
                        Artista artistas = obtenerArtista(cArt, i);
                        if (artistas.id != -1) {
                            mostrarArtistaUsuario(artistas);
                        }
                    }
                    printf("¿Desea exportar los artistas a un TSV? (s/n)\n");
                    if (confirmar('s')) {
                        if (exportarArtistasATexto("artistas.tsv", cArt)) {
                            printf("[Exito] El listado fue guardado en 'artistas.tsv'.\n");
                        } else {
                            printf("[Error] No se pudo crear el archivo de exportacion.\n");
                        }
                    }
                }
                break;
                
            case 2:
                printf("\n--- LISTADO DE ESCENARIOS ---\n");
                cantidad = obtenerCantidadEscenarios(cEsc);
                if (cantidad == 0) {
                    printf("No hay escenarios cargados en el sistema.\n");
                } else {
                    ordenarColeccionEscenariosAlfabeticamente(cEsc);
                    for (int i = 0; i < cantidad; i++) {
                        Escenario escenarios = obtenerEscenario(cEsc, i);
                        if (escenarios.id != -1) {
                            mostrarEscenarioUsuario(escenarios);
                        }
                    }
                    printf("¿Desea exportar los escenarios a un TSV? (s/n)\n");
                    if (confirmar('s')) {
                        if (exportarEscenariosATexto("escenarios.tsv", cEsc)) {
                            printf("[Exito] El listado fue guardado en 'escenarios.tsv'.\n");
                        } else {
                            printf("[Error] No se pudo crear el archivo de exportacion.\n");
                        }
                    }
                }
                break;
                
            case 3:
                printf("\n--- CRONOGRAMA COMPLETO ---\n");
                // TODO: Mostrar todas las presentaciones
                break;
                
            case 4:
                // Reutilizás tu funcion generica!
                printf("\n--- PRESENTACIONES DEL ARTISTA ---\n");
                // TODO: Recorrer el arreglo de presentaciones e imprimir solo las que coincidan
                break;
                
            case 5:
                printf("\n--- PRESENTACIONES EN EL ESCENARIO ---\n");
                // TODO: Recorrer el arreglo e imprimir coincidencias
                break;
                
            case 0:
                printf("\nVolviendo al menu principal...\n");
                break;
                
            default:
                printf("\n[Error] Opcion invalida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 0);
}