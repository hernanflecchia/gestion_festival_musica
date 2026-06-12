#include <stdio.h>
#include <stdlib.h>
#include "colecciones.h"

// ===========
// ARTISTAS
// ===========

ColeccionArtistas inicializarColeccionArtistas(void) {
    ColeccionArtistas col;
    
    // Definimos un tamaño inicial arbitrario (por ejemplo, para 10 artistas)
    col.capacidad = 10;
    col.validos = 0;
    // Solicitamos el bloque de memoria dinámico
    col.arreglo = (Artista*) malloc(col.capacidad * sizeof(Artista));
    // Verificamos que el sistema operativo nos haya dado la memoria
    if (col.arreglo == NULL) {
        printf("[Error Critico] No hay memoria disponible para inicializar Artistas.\n");
        col.capacidad = 0;
    }
    
    return col;
}

int agregarArtista(ColeccionArtistas* coleccion, Artista unArtista) {
    
    // Verificamos si NO hay espacio (los válidos alcanzaron la capacidad)
    if (coleccion->validos == coleccion->capacidad) {
        
        int nuevaCapacidad = coleccion->capacidad + 10;
        Artista* nuevoBloque = (Artista*) realloc(coleccion->arreglo, nuevaCapacidad * sizeof(Artista));
        
        if (nuevoBloque == NULL) {
            return 0; // Falló la inserción
        }
        
        // Actualizamos los datos de la colección
        coleccion->arreglo = nuevoBloque;
        coleccion->capacidad = nuevaCapacidad;
    }
    
    // Agregamos el artista a la coleccion
    coleccion->arreglo[coleccion->validos] = unArtista;
    coleccion->validos++;
    
    return 1;
}

Artista obtenerArtista(ColeccionArtistas* coleccion, int indice) {
    Artista unArtista;

    // Verificamos que el indice sea valido y no se pase de los elementos cargados
    // si falla algo devolvemos -1 como id indicando con ello que falló
    if (indice >= 0 && indice < coleccion->validos) {
        unArtista = coleccion->arreglo[indice];
    } else {
        unArtista.id = -1; 
    }

    return unArtista;
}

int actualizarArtista(ColeccionArtistas* coleccion, int indice, Artista artistaModificado) {
    int respuesta = 1;
    // Verificamos que el indice sea valido y no se pase de los elementos cargados
    // si falla algo devolvemos -1 como respuesta
    if (indice >= 0 && indice < coleccion->validos) {
        coleccion->arreglo[indice] = artistaModificado;
        respuesta = 1;
    } else {
        respuesta = -1; 
    }
    return respuesta;
}

int obtenerCantidadArtistas(ColeccionArtistas* coleccion) {
    return coleccion->validos;
}

int obtenerSiguienteIdArtista(ColeccionArtistas* coleccion) {
    int proximoId = 1;
    
    if (coleccion->validos > 0) {
        // Vamos a la ultima celda ocupada (validos - 1)
        // Leemos su id y le sumamos 1
        proximoId = coleccion->arreglo[coleccion->validos - 1].id + 1;
    }
    
    return proximoId;
}

void liberarColeccionArtistas(ColeccionArtistas* coleccion) {
    // Verificamos que el puntero no sea nulo antes de liberar
    if (coleccion->arreglo != NULL) {
        free(coleccion->arreglo);
    }
}

// =============
// ESCENARIOS
// =============

ColeccionEscenarios inicializarColeccionEscenarios(void) {
    ColeccionEscenarios col;
    
    // Definimos un tamaño inicial arbitrario (por ejemplo, para 4 Escenarios)
    col.capacidad = 4;
    col.validos = 0;
    // Solicitamos el bloque de memoria dinámico
    col.arreglo = (Escenario*) malloc(col.capacidad * sizeof(Artista));
    // Verificamos que el sistema operativo nos haya dado la memoria
    if (col.arreglo == NULL) {
        printf("[Error Critico] No hay memoria disponible para inicializar Escenarios.\n");
        col.capacidad = 0;
    }
    
    return col;
}

void liberarColeccionEscenarios(ColeccionEscenarios* coleccion) {
    // Verificamos que el puntero no sea nulo antes de liberar
    if (coleccion->arreglo != NULL) {
        free(coleccion->arreglo);
    }
}

// =================
// PRESENTACIONES
// =================

ColeccionPresentaciones inicializarColeccionPresentaciones(void) {
    ColeccionPresentaciones col;
    
    // Definimos un tamaño inicial arbitrario (por ejemplo, para 10 Presentaciones)
    col.capacidad = 10;
    col.validos = 0;
    // Solicitamos el bloque de memoria dinámico
    col.arreglo = (Presentacion*) malloc(col.capacidad * sizeof(Artista));
    // Verificamos que el sistema operativo nos haya dado la memoria
    if (col.arreglo == NULL) {
        printf("[Error Critico] No hay memoria disponible para inicializar Presentaciones.\n");
        col.capacidad = 0;
    }
    
    return col;
}

void liberarColeccionPresentaciones(ColeccionPresentaciones* coleccion) {
    // Verificamos que el puntero no sea nulo antes de liberar
    if (coleccion->arreglo != NULL) {
        free(coleccion->arreglo);
    }
}