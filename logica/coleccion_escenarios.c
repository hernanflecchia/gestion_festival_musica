#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coleccion_escenarios.h"

ColeccionEscenarios inicializarColeccionEscenarios(void) {
    ColeccionEscenarios col;
    
    col.capacidad = CAPACIDAD_ESCENARIOS;
    col.validos = 0;
    col.arreglo = (Escenario*) malloc(col.capacidad * sizeof(Escenario));
    if (col.arreglo == NULL) {
        printf("[Error Critico] No hay memoria disponible para inicializar Escenarios.\n");
        col.capacidad = 0;
    }
    
    return col;
}

void cargarEscenariosDePrueba(ColeccionEscenarios* coleccion) {
    Escenario escenariosDePrueba[] = {
        {1, "Principal"},
        {2, "Acustico"},
        {3, "Electronico"},
        {4, "Rock"},
        {5, "Cumbia"}
    };
    
    int cantidadDePrueba = sizeof(escenariosDePrueba) / sizeof(escenariosDePrueba[0]);
    
    for (int i = 0; i < cantidadDePrueba; i++) {
        agregarEscenario(coleccion, escenariosDePrueba[i]);
    }
}

int agregarEscenario(ColeccionEscenarios* coleccion, Escenario unEscenario) {
    
    if (coleccion->validos == coleccion->capacidad) {
        
        int nuevaCapacidad = coleccion->capacidad + CAPACIDAD_ESCENARIOS;
        Escenario* nuevoBloque = (Escenario*) realloc(coleccion->arreglo, nuevaCapacidad * sizeof(Escenario));
        
        if (nuevoBloque == NULL) {
            return 0; // Falló la inserción
        }
        
        coleccion->arreglo = nuevoBloque;
        coleccion->capacidad = nuevaCapacidad;
    }
    
    coleccion->arreglo[coleccion->validos] = unEscenario;
    coleccion->validos++;
    
    return 1;
}

Escenario obtenerEscenario(ColeccionEscenarios* coleccion, int indice) {
    Escenario unEscenario;

    if (indice >= 0 && indice < coleccion->validos) {
        unEscenario = coleccion->arreglo[indice];
    } else {
        unEscenario.id = -1; 
    }

    return unEscenario;
}

int actualizarEscenario(ColeccionEscenarios* coleccion, int indice, Escenario escenarioModificado) {
    int respuesta = 1;
    if (indice >= 0 && indice < coleccion->validos) {
        coleccion->arreglo[indice] = escenarioModificado;
        respuesta = 1;
    } else {
        respuesta = -1; 
    }
    return respuesta;
}

int buscarIndiceEscenarioPorId(ColeccionEscenarios* coleccion, int idBuscado) {
    int indiceEncontrado = -1;
    
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
        proximoId = coleccion->arreglo[coleccion->validos - 1].id + 1;
    }
    
    return proximoId;
}

void eliminarEscenarioDeMemoria(ColeccionEscenarios* coleccion, int indiceAEliminar) {
    if (indiceAEliminar >= 0 && indiceAEliminar < coleccion->validos) {
        for (int i = indiceAEliminar; i < coleccion->validos - 1; i++) {
            coleccion->arreglo[i] = coleccion->arreglo[i + 1];
        }
        coleccion->validos--;

        if ((coleccion->capacidad - coleccion->validos) > CAPACIDAD_ESCENARIOS) {
            int nuevaCapacidad = coleccion->capacidad - CAPACIDAD_ESCENARIOS;
    
            if (nuevaCapacidad > 0) {
                Escenario* bloqueAchicado = (Escenario*) realloc(coleccion->arreglo, nuevaCapacidad * sizeof(Escenario));
                if (bloqueAchicado != NULL) {
                    coleccion->arreglo = bloqueAchicado;
                    coleccion->capacidad = nuevaCapacidad;
                }
            }
        }
    }
}

void liberarColeccionEscenarios(ColeccionEscenarios* coleccion) {
    if (coleccion->arreglo != NULL) {
        free(coleccion->arreglo);
    }
}

int buscarEscenarioPosMenorAlfabeticoRecursivo(Escenario arreglo[], int validos, int indiceActual, int indiceMenor) {
    if (indiceActual == validos) {
        return indiceMenor; 
    }
    if (strcmp(arreglo[indiceActual].nombre, arreglo[indiceMenor].nombre) < 0) {
        indiceMenor = indiceActual;
    }
    return buscarEscenarioPosMenorAlfabeticoRecursivo(arreglo, validos, indiceActual + 1, indiceMenor);
}

void ordenarEscenariosRecursivo(Escenario arreglo[], int validos, int indiceActual) {
    if (indiceActual >= validos - 1) {
        return; 
    }
    int posMenor = buscarEscenarioPosMenorAlfabeticoRecursivo(arreglo, validos, indiceActual + 1, indiceActual);
    if (posMenor != indiceActual) {
        Escenario aux = arreglo[indiceActual];
        arreglo[indiceActual] = arreglo[posMenor];
        arreglo[posMenor] = aux;
    }
    ordenarEscenariosRecursivo(arreglo, validos, indiceActual + 1);
}

void ordenarColeccionEscenariosAlfabeticamente(ColeccionEscenarios* coleccion) {
    if (coleccion->validos > 1) {
        ordenarEscenariosRecursivo(coleccion->arreglo, coleccion->validos, 0);
    }
}