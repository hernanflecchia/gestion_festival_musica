#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coleccion_presentaciones.h"

ColeccionPresentaciones inicializarColeccionPresentaciones(void) {
    ColeccionPresentaciones col;
    
    // Definimos un tamaño inicial arbitrario (por ejemplo, para 10 presentaciones)
    col.capacidad = 10;
    col.validos = 0;
    // Solicitamos el bloque de memoria dinámico
    col.arreglo = (Presentacion*) malloc(col.capacidad * sizeof(Presentacion));
    // Verificamos que el sistema operativo nos haya dado la memoria
    if (col.arreglo == NULL) {
        printf("[Error Critico] No hay memoria disponible para inicializar Presentaciones.\n");
        col.capacidad = 0;
    }
    
    return col;
}

int agregarPresentacion(ColeccionPresentaciones* coleccion, Presentacion unaPresentacion) {
    
    // Verificamos si NO hay espacio (los válidos alcanzaron la capacidad)
    if (coleccion->validos == coleccion->capacidad) {
        
        int nuevaCapacidad = coleccion->capacidad + 10;
        Presentacion* nuevoBloque = (Presentacion*) realloc(coleccion->arreglo, nuevaCapacidad * sizeof(Presentacion));
        
        if (nuevoBloque == NULL) {
            return 0; // Falló la inserción
        }
        
        // Actualizamos los datos de la colección
        coleccion->arreglo = nuevoBloque;
        coleccion->capacidad = nuevaCapacidad;
    }
    
    // Agregamos el presentacion a la coleccion
    coleccion->arreglo[coleccion->validos] = unaPresentacion;
    coleccion->validos++;
    
    return 1;
}

Presentacion obtenerPresentacion(ColeccionPresentaciones* coleccion, int indice) {
    Presentacion unaPresentacion;

    // Verificamos que el indice sea valido y no se pase de los elementos cargados
    // si falla algo devolvemos -1 como id indicando con ello que falló
    if (indice >= 0 && indice < coleccion->validos) {
        unaPresentacion = coleccion->arreglo[indice];
    } else {
        unaPresentacion.id = -1; 
    }

    return unaPresentacion;
}

void liberarColeccionPresentaciones(ColeccionPresentaciones* coleccion) {
    // Verificamos que el puntero no sea nulo antes de liberar
    if (coleccion->arreglo != NULL) {
        free(coleccion->arreglo);
    }
}

int eliminarPresentacionesDeMemoriaPorArtista(ColeccionPresentaciones* coleccion, int idArtista) {
    int cantidadBorradas = 0;
    int i = 0;
    
    while (i < coleccion->validos) {
        if (coleccion->arreglo[i].idArtista == idArtista) {
            // Borrado físico: Pisamos moviendo todo hacia la izquierda
            for (int j = i; j < coleccion->validos - 1; j++) {
                coleccion->arreglo[j] = coleccion->arreglo[j + 1];
            }
            coleccion->validos--;
            cantidadBorradas++;
        } else {
            i++; // Solo avanzamos si no borramos nada
        }
    }
    
    return cantidadBorradas;
}

int eliminarPresentacionesDeMemoriaPorEscenario(ColeccionPresentaciones* coleccion, int idEscenario) {
    int cantidadBorradas = 0;
    int i = 0;
    
    while (i < coleccion->validos) {
        if (coleccion->arreglo[i].idEscenario == idEscenario) {
            // Borrado físico: Pisamos moviendo todo hacia la izquierda
            for (int j = i; j < coleccion->validos - 1; j++) {
                coleccion->arreglo[j] = coleccion->arreglo[j + 1];
            }
            coleccion->validos--;
            cantidadBorradas++;
        } else {
            i++; // Solo avanzamos si no borramos nada
        }
    }
    
    return cantidadBorradas;
}