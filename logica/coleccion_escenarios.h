#ifndef COLECCION_ESCENARIOS_H
#define COLECCION_ESCENARIOS_H
#define CAPACIDAD_ESCENARIOS 3

#include "../dominio/escenario.h"

// ==========================================
// DEFINICIÓN DEL TDA (Coleccion Dinámica)
// ==========================================
typedef struct {
    Escenario* arreglo;
    int capacidad;
    int validos;
} ColeccionEscenarios;

// =====================================
// PROTOTIPOS PARA GESTION EN MEMORIA
// =====================================
ColeccionEscenarios inicializarColeccionEscenarios(void);
int agregarEscenario(ColeccionEscenarios* coleccion, Escenario unEscenario);
Escenario obtenerEscenario(ColeccionEscenarios* coleccion, int indice);
int actualizarEscenario(ColeccionEscenarios* coleccion, int indice, Escenario escenarioModificado);
int buscarIndiceEscenarioPorId(ColeccionEscenarios* coleccion, int idBuscado);
int obtenerCantidadEscenarios(ColeccionEscenarios* coleccion);
int obtenerSiguienteIdEscenario(ColeccionEscenarios* coleccion);
void eliminarEscenarioDeMemoria(ColeccionEscenarios* coleccion, int indice);
void liberarColeccionEscenarios(ColeccionEscenarios* coleccion);
void ordenarColeccionEscenariosAlfabeticamente(ColeccionEscenarios* coleccion);

#endif