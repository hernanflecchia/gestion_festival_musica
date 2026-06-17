#ifndef GESTOR_ARCHIVOS_ESCENARIOS_H
#define GESTOR_ARCHIVOS_ESCENARIOS_H
#define ARCHIVO_ESCENARIOS "escenarios.bin"

#include <stdbool.h>
#include "coleccion_escenarios.h"

// =====================================
// PROTOTIPOS PARA GESTION EN DISCO
// =====================================
int guardarEscenarioEnArchivo(EscenarioArchivo nuevoEscenario);
void inicializarArchivoEscenarios(void);
void cargarEscenariosDesdeArchivo(ColeccionEscenarios* coleccion);
int exportarEscenariosATexto(const char* nombreArchivoTxt, ColeccionEscenarios* coleccion, bool esAdmin);
int modificarEscenarioEnArchivo(EscenarioArchivo escenarioModificado);
int bajaLogicaEscenarioEnArchivo(int idBuscado);
ColeccionEscenarios obtenerEscenariosEliminados();

// Utilitarios de mapeo (transforman un modelo en otro)
EscenarioArchivo transformarAEscenarioArchivo(Escenario escenarioMemoria);
Escenario transformarAEscenarioMemoria(EscenarioArchivo escenarioDisco);

#endif