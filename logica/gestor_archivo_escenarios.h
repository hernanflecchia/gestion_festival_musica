#ifndef GESTOR_ARCHIVOS_ESCENARIOS_H
#define GESTOR_ARCHIVOS_ESCENARIOS_H
#define ARCHIVO_ESCENARIOS "escenarios.bin"

#include "coleccion_escenarios.h"

// =====================================
// PROTOTIPOS PARA GESTION EN DISCO
// =====================================
int guardarEscenarioEnArchivo(EscenarioArchivo nuevoEscenario); 
void cargarEscenariosDesdeArchivo(ColeccionEscenarios* coleccion);
int exportarEscenariosATexto(const char* nombreArchivoTxt, ColeccionEscenarios* coleccion);
int modificarEscenarioEnArchivo(EscenarioArchivo escenarioModificado);
int bajaLogicaEscenarioEnArchivo(int idBuscado);

// Utilitarios de mapeo (transforman un modelo en otro)
EscenarioArchivo transformarAEscenarioArchivo(Escenario escenarioMemoria);
Escenario transformarAEscenarioMemoria(EscenarioArchivo escenarioDisco);

#endif