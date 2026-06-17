#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "gestor_archivo_presentaciones.h"
#include "../dominio/tipos_seguros.h"
#include "coleccion_artistas.h"
#include "coleccion_escenarios.h"

PresentacionArchivo transformarAPresentacionArchivo(Presentacion presentacionMemoria) {
    PresentacionArchivo presentacionDisco;

    presentacionDisco.id = presentacionMemoria.id;
    presentacionDisco.idArtista = presentacionMemoria.idArtista;
    presentacionDisco.idEscenario = presentacionMemoria.idEscenario;
    presentacionDisco.inicio.horas = presentacionMemoria.inicio.horas;
    presentacionDisco.inicio.minutos = presentacionMemoria.inicio.minutos;
    presentacionDisco.duracion.horas = presentacionMemoria.duracion.horas;
    presentacionDisco.duracion.minutos = presentacionMemoria.duracion.minutos;
    presentacionDisco.valido = 'S';

    return presentacionDisco;
}

void inicializarArchivoPresentaciones(void) {
    PresentacionArchivo presentacionesDePrueba[] = {
        {1, 1, 1, {18, 0}, {2, 0}, 'S'},
        {2, 2, 2, {20, 0}, {1, 30}, 'S'},
        {3, 3, 3, {19, 30}, {1, 0}, 'S'},
        {4, 4, 1, {21, 0}, {2, 0}, 'S'},
        {5, 5, 2, {22, 30}, {1, 30}, 'S'},
        {6, 2, 4, {22, 30}, {1, 30}, 'S'},
        {7, 7, 2, {18, 30}, {1, 00}, 'S'},
        {8, 2, 5, {18, 30}, {1, 00}, 'S'},
        {9, 8, 5, {22, 30}, {1, 30}, 'S'},
        {10, 10, 3, {22, 30}, {1, 30}, 'S'},
        {11, 9, 2, {17, 00}, {1, 00}, 'S'},
        {12, 1, 3, {16, 00}, {1, 00}, 'S'},
        {13, 5, 1, {16, 30}, {1, 00}, 'S'},
        {14, 6, 4, {18, 00}, {1, 30}, 'S'},
        {15, 9, 4, {20, 00}, {1, 00}, 'S'}
    };
    FILE* archPresentaciones = fopen(ARCHIVO_PRESENTACIONES, "rb");
    
    if (archPresentaciones == NULL) {
        archPresentaciones = fopen(ARCHIVO_PRESENTACIONES, "wb");
        if (archPresentaciones != NULL) {
            int cantidadDePrueba = sizeof(presentacionesDePrueba) / sizeof(presentacionesDePrueba[0]);
            fwrite(presentacionesDePrueba, sizeof(PresentacionArchivo), cantidadDePrueba, archPresentaciones); 
            fclose(archPresentaciones);
            printf("[Sistema] Primer inicio detectado: Archivo de prueba de presentaciones creado con exito.\n\n");
        }
    } else {
        fclose(archPresentaciones); 
    }
}

int guardarPresentacionEnArchivo(PresentacionArchivo nueva) {
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "ab");

    if (arch!= NULL) {
        fwrite(&nueva, sizeof(PresentacionArchivo), 1, arch);
        fclose(arch);

        return 1;
    }

    return 0;
}

Presentacion transformarAPresentacionMemoria(PresentacionArchivo presentacionDisco) {
    Presentacion presentacionMemoria;

    presentacionMemoria.id = presentacionDisco.id;
    presentacionMemoria.idArtista = presentacionDisco.idArtista;
    presentacionMemoria.idEscenario = presentacionDisco.idEscenario;
    presentacionMemoria.inicio = crearHorario(presentacionDisco.inicio.horas, presentacionDisco.inicio.minutos);
    presentacionMemoria.duracion = crearDuracion(presentacionDisco.duracion.horas, presentacionDisco.duracion.minutos);

    return presentacionMemoria;
}

void cargarPresentacionesDesdeArchivo(ColeccionPresentaciones* coleccion) {
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "rb");

    if (arch != NULL) {
        PresentacionArchivo presentacionLeido;
        int agregado;

        while (fread(&presentacionLeido, sizeof(PresentacionArchivo), 1, arch)) {
            if (presentacionLeido.valido == 'S') {
                Presentacion presentacionMemoria = transformarAPresentacionMemoria(presentacionLeido);
                agregado = agregarPresentacion(coleccion, presentacionMemoria);
                if (agregado == 0) {
                    printf("[Error] No hay memoria disponible para ampliar el arreglo.\n");
                    fclose(arch);
                    return;
                }
            }
        }
        fclose(arch);
    }
}

int modificarPresentacionEnArchivo(PresentacionArchivo modificado) {
    int exito = 0;
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "r+b"); 
    
    if (arch != NULL) {
        PresentacionArchivo leido;
        
        while (fread(&leido, sizeof(PresentacionArchivo), 1, arch)) { 
            if (leido.id == modificado.id) {
                fseek(arch, -1 * sizeof(PresentacionArchivo), SEEK_CUR); 
                fwrite(&modificado, sizeof(PresentacionArchivo), 1, arch);
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int bajaLogicaPresentacionEnArchivo(int idBorrar) {
    int exito = 0;
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "r+b"); 
    
    if (arch != NULL) {
        PresentacionArchivo leida;
        while (fread(&leida, sizeof(PresentacionArchivo), 1, arch)) { 
            
            if (leida.id == idBorrar && leida.valido == 'S') {
                leida.valido = 'N';
                fseek(arch, -1 * sizeof(PresentacionArchivo), SEEK_CUR); 
                fwrite(&leida, sizeof(PresentacionArchivo), 1, arch);
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int exportarPresentacionesATexto(const char* nombreArchivoTxt, ColeccionPresentaciones* coleccion, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, bool esAdmin) {
    
    FILE* archTxt = fopen(nombreArchivoTxt, "w");
    
    if (archTxt != NULL) {
        
        if (esAdmin) {
            fprintf(archTxt, "id\tartista\tescenario\tinicio\tduracion\n");
        } else {
            fprintf(archTxt, "artista\tescenario\tinicio\tduracion\n");
        }
        
        for (int i = 0; i < coleccion->validos; i++) {
            
            if (coleccion->arreglo[i].id != -1) {
                
                int indiceArt = buscarIndiceArtistaPorId(colArtistas, coleccion->arreglo[i].idArtista);
                Artista artista = obtenerArtista(colArtistas, indiceArt); 

                int indiceEsc = buscarIndiceEscenarioPorId(colEscenarios, coleccion->arreglo[i].idEscenario);
                Escenario escenario = obtenerEscenario(colEscenarios, indiceEsc);

                if (esAdmin) {
                    fprintf(archTxt, "%d\t%s\t%s\t%02d:%02d\t%02d:%02d\n", 
                        coleccion->arreglo[i].id, 
                        artista.nombre, 
                        escenario.nombre,
                        coleccion->arreglo[i].inicio.horas, 
                        coleccion->arreglo[i].inicio.minutos,
                        coleccion->arreglo[i].duracion.horas, 
                        coleccion->arreglo[i].duracion.minutos);
                } else {
                    fprintf(archTxt, "%s\t%s\t%02d:%02d\t%02d:%02d\n", 
                        artista.nombre, 
                        escenario.nombre,
                        coleccion->arreglo[i].inicio.horas, 
                        coleccion->arreglo[i].inicio.minutos,
                        coleccion->arreglo[i].duracion.horas, 
                        coleccion->arreglo[i].duracion.minutos);
                }
            }
        }
        
        fclose(archTxt);
        return 1; 
        
    } else {
        return 0;
    }
}

int bajaLogicaPresentacionesEnArchivoPorArtista(int idArtistaBuscado) {
    int cantidadBorradas = 0;
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "r+b"); 
    
    if (arch != NULL) {
        PresentacionArchivo leida;
        while (fread(&leida, sizeof(PresentacionArchivo), 1, arch) > 0) { 
            // Buscamos todas las presentaciones activas de ese artista
            if (leida.idArtista == idArtistaBuscado && leida.valido == 'S') {
                leida.valido = 'N'; // Las marcamos como borradas lógicamente
                fseek(arch, -1 * sizeof(PresentacionArchivo), SEEK_CUR); 
                fwrite(&leida, sizeof(PresentacionArchivo), 1, arch);
                // Preguntar sobre esta linea
                fseek(arch, 0, SEEK_CUR);
                cantidadBorradas++;
            }
        }
        fclose(arch);
    }
    return cantidadBorradas;
}

int bajaLogicaPresentacionesEnArchivoPorEscenario(int idEscenarioBuscado) {
    int cantidadBorradas = 0;
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "r+b"); 
    
    if (arch != NULL) {
        PresentacionArchivo leida;
        while (fread(&leida, sizeof(PresentacionArchivo), 1, arch) > 0) { 
            // Buscamos todas las presentaciones activas de ese escenario
            if (leida.idEscenario == idEscenarioBuscado && leida.valido == 'S') {
                leida.valido = 'N'; // Las marcamos como borradas lógicamente
                fseek(arch, -1 * sizeof(PresentacionArchivo), SEEK_CUR); 
                fwrite(&leida, sizeof(PresentacionArchivo), 1, arch);
                // Preguntar sobre esta linea
                fseek(arch, 0, SEEK_CUR);
                cantidadBorradas++;
            }
        }
        fclose(arch);
    }
    return cantidadBorradas;
}

ColeccionPresentaciones obtenerPresentacionesEliminadas() {
    ColeccionPresentaciones eliminadas;
    eliminadas.arreglo = NULL;
    eliminadas.capacidad = 0;
    eliminadas.validos = 0;

    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "rb");
    if (arch != NULL) {
        PresentacionArchivo presentacionLeida;

        while (fread(&presentacionLeida, sizeof(PresentacionArchivo), 1, arch)) {
            if (presentacionLeida.valido == 'N') {
                Presentacion presentacionMemoria = transformarAPresentacionMemoria(presentacionLeida);
                agregarPresentacion(&eliminadas, presentacionMemoria);
            }
        }
        fclose(arch);
    }
    return eliminadas;
}