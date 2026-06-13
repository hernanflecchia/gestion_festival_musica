#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coleccion_escenarios.h"

ColeccionEscenarios inicializarColeccionEscenarios(void) {
    ColeccionEscenarios col;
    
    // Definimos un tamaño inicial arbitrario (por ejemplo, para 10 escenarios)
    col.capacidad = 10;
    col.validos = 0;
    // Solicitamos el bloque de memoria dinámico
    col.arreglo = (Escenario*) malloc(col.capacidad * sizeof(Escenario));
    // Verificamos que el sistema operativo nos haya dado la memoria
    if (col.arreglo == NULL) {
        printf("[Error Critico] No hay memoria disponible para inicializar Escenarios.\n");
        col.capacidad = 0;
    }
    
    return col;
}

int agregarEscenario(ColeccionEscenarios* coleccion, Escenario unEscenario) {
    
    // Verificamos si NO hay espacio (los válidos alcanzaron la capacidad)
    if (coleccion->validos == coleccion->capacidad) {
        
        int nuevaCapacidad = coleccion->capacidad + 10;
        Escenario* nuevoBloque = (Escenario*) realloc(coleccion->arreglo, nuevaCapacidad * sizeof(Escenario));
        
        if (nuevoBloque == NULL) {
            return 0; // Falló la inserción
        }
        
        // Actualizamos los datos de la colección
        coleccion->arreglo = nuevoBloque;
        coleccion->capacidad = nuevaCapacidad;
    }
    
    // Agregamos el escenario a la coleccion
    coleccion->arreglo[coleccion->validos] = unEscenario;
    coleccion->validos++;
    
    return 1;
}

Escenario obtenerEscenario(ColeccionEscenarios* coleccion, int indice) {
    Escenario unEscenario;

    // Verificamos que el indice sea valido y no se pase de los elementos cargados
    // si falla algo devolvemos -1 como id indicando con ello que falló
    if (indice >= 0 && indice < coleccion->validos) {
        unEscenario = coleccion->arreglo[indice];
    } else {
        unEscenario.id = -1; 
    }

    return unEscenario;
}

int actualizarEscenario(ColeccionEscenarios* coleccion, int indice, Escenario escenarioModificado) {
    int respuesta = 1;
    // Verificamos que el indice sea valido y no se pase de los elementos cargados
    // si falla algo devolvemos -1 como respuesta
    if (indice >= 0 && indice < coleccion->validos) {
        coleccion->arreglo[indice] = escenarioModificado;
        respuesta = 1;
    } else {
        respuesta = -1; 
    }
    return respuesta;
}

int buscarIndiceEscenarioPorId(ColeccionEscenarios* coleccion, int idBuscado) {
    int indiceEncontrado = -1; // Por defecto asumimos que no existe
    
    for (int i = 0; i < coleccion->validos; i++) {
        if (coleccion->arreglo[i].id == idBuscado) {
            indiceEncontrado = i;
            break;
        }
    }
    
    return indiceEncontrado;
}

int obtenerCantidadEscenarios(ColeccionEscenarios* coleccion) {
    return coleccion->validos;
}

int obtenerSiguienteIdEscenario(ColeccionEscenarios* coleccion) {
    int proximoId = 1;
    
    if (coleccion->validos > 0) {
        // Vamos a la ultima celda ocupada (validos - 1)
        // Leemos su id y le sumamos 1
        proximoId = coleccion->arreglo[coleccion->validos - 1].id + 1;
    }
    
    return proximoId;
}

void eliminarEscenarioDeMemoria(ColeccionEscenarios* coleccion, int indiceAEliminar) {
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

void liberarColeccionEscenarios(ColeccionEscenarios* coleccion) {
    // Verificamos que el puntero no sea nulo antes de liberar
    if (coleccion->arreglo != NULL) {
        free(coleccion->arreglo);
    }
}

int buscarEscenarioPosMenorAlfabeticoRecursivo(Escenario arreglo[], int validos, int indiceActual, int indiceMenor) {
    // Condición de corte: llegamos al final del arreglo
    if (indiceActual == validos) {
        return indiceMenor; 
    }
    // Si el nombre actual es alfabéticamente menor que el que teníamos guardado, actualizamos
    if (strcmp(arreglo[indiceActual].nombre, arreglo[indiceMenor].nombre) < 0) {
        indiceMenor = indiceActual;
    }
    // Llamada recursiva avanzando al siguiente elemento
    return buscarEscenarioPosMenorAlfabeticoRecursivo(arreglo, validos, indiceActual + 1, indiceMenor);
}

void ordenarEscenariosRecursivo(Escenario arreglo[], int validos, int indiceActual) {
    // Condición de corte: si llegamos al anteúltimo elemento, ya está todo ordenado
    if (indiceActual >= validos - 1) {
        return; 
    }
    // Buscamos el menor desde la posición actual hasta el final
    int posMenor = buscarEscenarioPosMenorAlfabeticoRecursivo(arreglo, validos, indiceActual + 1, indiceActual);
    // Si encontramos uno menor, hacemos el "swap" (intercambio)
    if (posMenor != indiceActual) {
        Escenario aux = arreglo[indiceActual];
        arreglo[indiceActual] = arreglo[posMenor];
        arreglo[posMenor] = aux;
    }
    // Llamada recursiva para ordenar el resto del arreglo avanzando un lugar
    ordenarEscenariosRecursivo(arreglo, validos, indiceActual + 1);
}

void ordenarColeccionEscenariosAlfabeticamente(ColeccionEscenarios* coleccion) {
    // Disparamos la recursión empezando desde el índice 0
    if (coleccion->validos > 1) {
        ordenarEscenariosRecursivo(coleccion->arreglo, coleccion->validos, 0);
    }
}