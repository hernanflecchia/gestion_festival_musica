#include <stdio.h>
#include <stdlib.h>
#include "colecciones.h"

// ==========================================
// INICIALIZACIÓN Y LIBERACIÓN DE ARTISTAS
// ==========================================

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

void liberarColeccionArtistas(ColeccionArtistas* coleccion) {
    // Verificamos que el puntero no sea nulo antes de liberar
    if (coleccion->arreglo != NULL) {
        free(coleccion->arreglo);
    }
}

// ============================================
// INICIALIZACIÓN Y LIBERACIÓN DE ESCENARIOS
// ============================================

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

// ================================================
// INICIALIZACIÓN Y LIBERACIÓN DE PRESENTACIONES
// ================================================

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