#include <stdio.h>
#include <string.h>
#include "gestor_archivo_artistas.h"

ArtistaArchivo transformarAArtistaArchivo(Artista artistaMemoria) {
    ArtistaArchivo artistaDisco;

    artistaDisco.id = artistaMemoria.id;
    strcpy(artistaDisco.nombre, artistaMemoria.nombre);
    strcpy(artistaDisco.genero, artistaMemoria.genero);
    artistaDisco.valido = 'S';

    return artistaDisco;
}

int guardarArtistaEnArchivo(ArtistaArchivo nueva) {
    FILE* arch = fopen(ARCHIVO_ARTISTAS, "ab");

    if (arch!= NULL) {
        fwrite(&nueva, sizeof(ArtistaArchivo), 1, arch);
        fclose(arch);

        return 1;
    }

    return 0;
}

Artista transformarAArtistaMemoria(ArtistaArchivo artistaDisco) {
    Artista artistaMemoria;

    artistaMemoria.id = artistaDisco.id;
    strcpy(artistaMemoria.nombre, artistaDisco.nombre);
    strcpy(artistaMemoria.genero, artistaDisco.genero);

    return artistaMemoria;
}

void cargarArtistasDesdeArchivo(ColeccionArtistas* coleccion) {
    FILE* arch = fopen(ARCHIVO_ARTISTAS, "rb");

    if (arch != NULL) {
        ArtistaArchivo artistaLeido;
        int agregado;

        while (fread(&artistaLeido, sizeof(ArtistaArchivo), 1, arch)) {
            if (artistaLeido.valido == 'S') {
                Artista artistaMemoria = transformarAArtistaMemoria(artistaLeido);
                agregado = agregarArtista(coleccion, artistaMemoria);
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

int modificarArtistaEnArchivo(ArtistaArchivo modificado) {
    int exito = 0;
    FILE* arch = fopen("artistas.bin", "r+b"); 
    
    if (arch != NULL) {
        ArtistaArchivo leido;
        
        while (fread(&leido, sizeof(ArtistaArchivo), 1, arch)) {
            if (leido.id == modificado.id) {
                fseek(arch, -1 * sizeof(ArtistaArchivo), SEEK_CUR); 
                fwrite(&modificado, sizeof(ArtistaArchivo), 1, arch);
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int bajaLogicaArtistaEnArchivo(int idBorrar) {
    int exito = 0;
    FILE* arch = fopen("artistas.bin", "r+b"); 
    
    if (arch != NULL) {
        ArtistaArchivo leido;
        while (fread(&leido, sizeof(ArtistaArchivo), 1, arch)) { 
            if (leido.id == idBorrar && leido.valido == 'S') {
                leido.valido = 'N'; 
                fseek(arch, -1 * sizeof(ArtistaArchivo), SEEK_CUR); 
                fwrite(&leido, sizeof(ArtistaArchivo), 1, arch);
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int exportarArtistasATexto(const char* nombreArchivoTxt, ColeccionArtistas* coleccion, bool esAdmin) {
    FILE* archTxt = fopen(nombreArchivoTxt, "w");
    
    if (archTxt != NULL) {
        
        if (esAdmin) {
            fprintf(archTxt, "id\tnombre\tgenero\n");
        } else {
            fprintf(archTxt, "nombre\tgenero\n");
        }
        for (int i = 0; i < coleccion->validos; i++) {
            if (esAdmin) {
                fprintf(archTxt, "%d\t%s\t%s\n", coleccion->arreglo[i].id, coleccion->arreglo[i].nombre, coleccion->arreglo[i].genero);
            } else {
                fprintf(archTxt, "%s\t%s\n", coleccion->arreglo[i].nombre,  coleccion->arreglo[i].genero);
            }
        }
        fclose(archTxt);
        return 1; 
        
    } else {
        return 0;
    }
}

ColeccionArtistas obtenerArtistasEliminados() {
    ColeccionArtistas eliminados;
    eliminados.arreglo = NULL;
    eliminados.capacidad = 0;
    eliminados.validos = 0;

    FILE* arch = fopen(ARCHIVO_ARTISTAS, "rb");
    if (arch != NULL) {
        ArtistaArchivo artistaLeido;

        while (fread(&artistaLeido, sizeof(ArtistaArchivo), 1, arch)) {
            if (artistaLeido.valido == 'N') {
                Artista artistaMemoria = transformarAArtistaMemoria(artistaLeido);
                agregarArtista(&eliminados, artistaMemoria);
            }
        }
        fclose(arch);
    }
    return eliminados;
}