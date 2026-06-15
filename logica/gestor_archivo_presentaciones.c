#include <stdio.h>
#include <string.h>
#include "gestor_archivo_presentaciones.h"
#include "../dominio/tipos_seguros.h"

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

int guardarPresentacionEnArchivo(PresentacionArchivo nuevaPresentacion) {
    int exito = 0;
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "ab"); 
    
    if (arch != NULL) {
        fwrite(&nuevaPresentacion, sizeof(PresentacionArchivo), 1, arch);
        fclose(arch);
        exito = 1; 
    } else {
        printf("[Error] No se pudo abrir el archivo %s para guardar.\n", ARCHIVO_PRESENTACIONES);
    }
    
    return exito;
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
                // Refrescamos el buffer haciendo un seek vacio
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
                // Refrescamos el buffer haciendo un seek vacio
                fseek(arch, 0, SEEK_CUR);
                cantidadBorradas++;
            }
        }
        fclose(arch);
    }
    return cantidadBorradas;
}