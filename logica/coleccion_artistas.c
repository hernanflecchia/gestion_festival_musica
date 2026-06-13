#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coleccion_artistas.h"

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

int buscarIndiceArtistaPorId(ColeccionArtistas* coleccion, int idBuscado) {
    int indiceEncontrado = -1; // Por defecto asumimos que no existe
    
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
        // Vamos a la ultima celda ocupada (validos - 1)
        // Leemos su id y le sumamos 1
        proximoId = coleccion->arreglo[coleccion->validos - 1].id + 1;
    }
    
    return proximoId;
}

void eliminarArtistaDeMemoria(ColeccionArtistas* coleccion, int indiceAEliminar) {
    // Verificamos por seguridad que el índice sea válido
    if (indiceAEliminar >= 0 && indiceAEliminar < coleccion->validos) {
        // Empezamos en la posición a eliminar y traemos el de la derecha hacia la izquierda
        for (int i = indiceAEliminar; i < coleccion->validos - 1; i++) {
            coleccion->arreglo[i] = coleccion->arreglo[i + 1];
        }
        // Achicamos la cantidad de válidos en 1
        coleccion->validos--;
    }
}

void liberarColeccionArtistas(ColeccionArtistas* coleccion) {
    // Verificamos que el puntero no sea nulo antes de liberar
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