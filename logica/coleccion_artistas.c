#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coleccion_artistas.h"

ColeccionArtistas inicializarColeccionArtistas(void) {
    ColeccionArtistas col;
    
    col.capacidad = CAPACIDAD_ARTISTAS;
    col.validos = 0;
    col.arreglo = (Artista*) malloc(col.capacidad * sizeof(Artista));
    if (col.arreglo == NULL) {
        printf("[Error Critico] No hay memoria disponible para inicializar Artistas.\n");
        col.capacidad = 0;
    }
    
    return col;
}

int agregarArtista(ColeccionArtistas* coleccion, Artista unArtista) {
    
    if (coleccion->validos == coleccion->capacidad) {
        
        int nuevaCapacidad = coleccion->capacidad + CAPACIDAD_ARTISTAS;
        Artista* nuevoBloque = (Artista*) realloc(coleccion->arreglo, nuevaCapacidad * sizeof(Artista));
        
        if (nuevoBloque == NULL) {
            return 0;
        }
        
        coleccion->arreglo = nuevoBloque;
        coleccion->capacidad = nuevaCapacidad;
    }
    
    coleccion->arreglo[coleccion->validos] = unArtista;
    coleccion->validos++;
    
    return 1;
}

Artista obtenerArtista(ColeccionArtistas* coleccion, int indice) {
    Artista unArtista;

    if (indice >= 0 && indice < coleccion->validos) {
        unArtista = coleccion->arreglo[indice];
    } else {
        unArtista.id = -1; 
    }

    return unArtista;
}

int actualizarArtista(ColeccionArtistas* coleccion, int indice, Artista artistaModificado) {
    int respuesta = 1;
    if (indice >= 0 && indice < coleccion->validos) {
        coleccion->arreglo[indice] = artistaModificado;
        respuesta = 1;
    } else {
        respuesta = -1; 
    }
    return respuesta;
}

int buscarIndiceArtistaPorId(ColeccionArtistas* coleccion, int idBuscado) {
    int indiceEncontrado = -1;
    
    for (int i = 0; i < coleccion->validos; i++) {
        if (coleccion->arreglo[i].id == idBuscado) {
            indiceEncontrado = i;
            break;
        }
    }
    
    return indiceEncontrado;
}

int obtenerCantidadArtistas(ColeccionArtistas* coleccion) {
    return coleccion->validos;
}

int obtenerSiguienteIdArtista(ColeccionArtistas* coleccion) {
    int proximoId = 1;
    
    if (coleccion->validos > 0) {
        proximoId = coleccion->arreglo[coleccion->validos - 1].id + 1;
    }
    
    return proximoId;
}

void eliminarArtistaDeMemoria(ColeccionArtistas* coleccion, int indiceAEliminar) {
    if (indiceAEliminar >= 0 && indiceAEliminar < coleccion->validos) {
        for (int i = indiceAEliminar; i < coleccion->validos - 1; i++) {
            coleccion->arreglo[i] = coleccion->arreglo[i + 1];
        }
        coleccion->validos--;

        if ((coleccion->capacidad - coleccion->validos) > CAPACIDAD_ARTISTAS) {
            int nuevaCapacidad = coleccion->capacidad - CAPACIDAD_ARTISTAS;
            
            if (nuevaCapacidad > 0) {
                Artista* bloqueAchicado = (Artista*) realloc(coleccion->arreglo, nuevaCapacidad * sizeof(Artista));
                if (bloqueAchicado != NULL) {
                    coleccion->arreglo = bloqueAchicado;
                    coleccion->capacidad = nuevaCapacidad;
                }
            }
        }
    }
}

void liberarColeccionArtistas(ColeccionArtistas* coleccion) {
    if (coleccion->arreglo != NULL) {
        free(coleccion->arreglo);
    }
}

int buscarArtistaPosMenorAlfabeticoRecursivo(Artista arreglo[], int validos, int indiceActual, int indiceMenor) {
    // Condición de corte: llegamos al final del arreglo
    if (indiceActual == validos) {
        return indiceMenor; 
    }
    // Si el nombre actual es alfabéticamente menor que el que teníamos guardado, actualizamos
    if (strcmp(arreglo[indiceActual].nombre, arreglo[indiceMenor].nombre) < 0) {
        indiceMenor = indiceActual;
    }
    // Llamada recursiva avanzando al siguiente elemento
    return buscarArtistaPosMenorAlfabeticoRecursivo(arreglo, validos, indiceActual + 1, indiceMenor);
}

void ordenarArtistasRecursivo(Artista arreglo[], int validos, int indiceActual) {
    // Condición de corte: si llegamos al anteúltimo elemento, ya está todo ordenado
    if (indiceActual >= validos - 1) {
        return; 
    }
    // Buscamos el menor desde la posición actual hasta el final
    int posMenor = buscarArtistaPosMenorAlfabeticoRecursivo(arreglo, validos, indiceActual + 1, indiceActual);
    // Si encontramos uno menor, hacemos el "swap" (intercambio)
    if (posMenor != indiceActual) {
        Artista aux = arreglo[indiceActual];
        arreglo[indiceActual] = arreglo[posMenor];
        arreglo[posMenor] = aux;
    }
    // Llamada recursiva para ordenar el resto del arreglo avanzando un lugar
    ordenarArtistasRecursivo(arreglo, validos, indiceActual + 1);
}

void ordenarColeccionArtistasAlfabeticamente(ColeccionArtistas* coleccion) {
    // Disparamos la recursión empezando desde el índice 0
    if (coleccion->validos > 1) {
        ordenarArtistasRecursivo(coleccion->arreglo, coleccion->validos, 0);
    }
}