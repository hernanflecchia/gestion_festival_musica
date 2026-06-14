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

int actualizarPresentacion(ColeccionPresentaciones* coleccion, int indice, Presentacion presentacionModificada) {
    int respuesta = 1;
    // Verificamos que el indice sea valido y no se pase de los elementos cargados
    // si falla algo devolvemos -1 como respuesta
    if (indice >= 0 && indice < coleccion->validos) {
        coleccion->arreglo[indice] = presentacionModificada;
        respuesta = 1;
    } else {
        respuesta = -1; 
    }
    return respuesta;
}

int buscarIndicePresentacionPorId(ColeccionPresentaciones* coleccion, int idBuscado) {
    int indiceEncontrado = -1;
    
    for (int i = 0; i < coleccion->validos; i++) {
        if (coleccion->arreglo[i].id == idBuscado) {
            indiceEncontrado = i;
            break;
        }
    }
    
    return indiceEncontrado;
}

int obtenerCantidadPresentaciones(ColeccionPresentaciones* coleccion) {
    return coleccion->validos;
}

int obtenerSiguienteIdPresentacion(ColeccionPresentaciones* coleccion) {
    int proximoId = 1;
    
    if (coleccion->validos > 0) {
        // Vamos a la ultima celda ocupada(validos - 1) y le sumamos 1 al id que tiene para generar el próximo id
        proximoId = coleccion->arreglo[coleccion->validos - 1].id + 1;
    }
    
    return proximoId;
}

void eliminarPresentacionDeMemoria(ColeccionPresentaciones* coleccion, int indiceAEliminar) {
    // Verificamos que el indice sea valido y no se pase de los elementos cargados
    if (indiceAEliminar >= 0 && indiceAEliminar < coleccion->validos) {
        // Borrado físico: Pisamos moviendo todo hacia la izquierda
        for (int i = indiceAEliminar; i < coleccion->validos - 1; i++) {
            coleccion->arreglo[i] = coleccion->arreglo[i + 1];
        }
        coleccion->validos--;
    }
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