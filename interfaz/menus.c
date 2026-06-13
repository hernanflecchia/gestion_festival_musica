#include <stdio.h>
#include "scanner.h"
#include "../dominio/usuario.h"
#include "../dominio/artista.h"
#include "../dominio/escenario.h"
#include "../logica/coleccion_artistas.h"
#include "../logica/coleccion_escenarios.h"
#include "../logica/coleccion_presentaciones.h"
#include "../logica/gestor_archivo_artistas.h"
#include "../logica/gestor_archivo_escenarios.h"
#include "../logica/gestor_archivo_presentaciones.h"

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

int pedirIdGenerico(const char* nombreEntidad) {
    printf("\nIngrese el ID del %s: ", nombreEntidad);
    return scanInt();
}

Artista pedirDatosNuevoArtista(void) {
    Artista nuevo;
    printf("\n--- ALTA DE ARTISTA ---\n");
    printf("Ingrese el nombre del artista: ");
    scanString(nuevo.nombre, DIM_ARTISTA_NOMBRE);
    printf("Ingrese el genero musical: ");
    scanString(nuevo.genero, DIM_GENERO);
    return nuevo;
}

Artista pedirDatosModificadosArtista(Artista artistaExistente) {
    printf("\n--- MODIFICANDO ARTISTA ---\n");
    printf("Modificando los datos del ID: %d\n", artistaExistente.id);
    printf("Nuevo nombre (anterior: %s): ", artistaExistente.nombre);
    scanString(artistaExistente.nombre, DIM_ARTISTA_NOMBRE);
    printf("Nuevo genero (anterior: %s): ", artistaExistente.genero);
    scanString(artistaExistente.genero, DIM_GENERO);
    return artistaExistente;
}

int mostrarMenuArtistas(void) {
    printf("\n--- GESTION DE ARTISTAS ---\n");
    printf("1. Dar de alta nuevo Artista\n");
    printf("2. Modificar Artista existente\n");
    printf("3. Dar de baja (Eliminar) Artista\n");
    printf("4. Listar Artistas por pantalla\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}

Escenario pedirDatosNuevoEscenario(void) {
    Escenario nuevo;
    printf("\n--- ALTA DE ESCENARIO ---\n");
    printf("Ingrese el nombre del escenario: ");
    scanString(nuevo.nombre, DIM_ESCENARIO_NOMBRE);
    return nuevo;
}

Escenario pedirDatosModificadosEscenario(Escenario escenarioExistente) {
    printf("\n--- MODIFICANDO ESCENARIO ---\n");
    printf("Modificando los datos del ID: %d\n", escenarioExistente.id);
    printf("Nuevo nombre (anterior: %s): ", escenarioExistente.nombre);
    scanString(escenarioExistente.nombre, DIM_ESCENARIO_NOMBRE);
    return escenarioExistente;
}

int mostrarMenuEscenarios(void) {
    printf("\n--- GESTION DE ESCENARIOS ---\n");
    printf("1. Dar de alta nuevo Escenario\n");
    printf("2. Modificar Escenario existente\n");
    printf("3. Dar de baja (Eliminar) Escenario\n");
    printf("4. Listar Escenarios por pantalla\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}

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
                // TODO: Ordenar alfabeticamente
                // TODO: Imprimir el arreglo
                break;
                
            case 3:
                printf("\n--- CRONOGRAMA COMPLETO ---\n");
                // TODO: Mostrar todas las presentaciones
                break;
                
            case 4:
                // Reutilizás tu funcion generica!
                idBuscado = pedirIdGenerico("Artista para ver sus presentaciones");
                printf("\n--- PRESENTACIONES DEL ARTISTA ---\n");
                // TODO: Recorrer el arreglo de presentaciones e imprimir solo las que coincidan
                break;
                
            case 5:
                idBuscado = pedirIdGenerico("Escenario para ver sus presentaciones");
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

void menuAdmin(Usuarios usuario, ColeccionArtistas* cArt, ColeccionEscenarios* cEsc, ColeccionPresentaciones* cPres) {
    int opcionPrincipal;
    int opcionSubMenu;
    int idBuscado;
    int indice;

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
                            idBuscado = pedirIdGenerico("Artista a modificar");
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
                            idBuscado = pedirIdGenerico("Artista a dar de baja");
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
                                for (int i = 0; i < cantidad; i++) {
                                    Artista unArtista = obtenerArtista(cArt, i);
                                    // Verificamos que no sea el valor centinela de error (-1)
                                    if (unArtista.id != -1) {
                                        mostrarArtistaAdmin(unArtista);
                                    }
                                }
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
                            idBuscado = pedirIdGenerico("Escenario a modificar");
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
                            idBuscado = pedirIdGenerico("Escenario a dar de baja");
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
                                for (int i = 0; i < cantidad; i++) {
                                    Escenario unEscenario = obtenerEscenario(cEsc, i);
                                    // Verificamos que no sea el valor centinela de error (-1)
                                    if (unEscenario.id != -1) {
                                        mostrarEscenarioAdmin(unEscenario);
                                    }
                                }
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