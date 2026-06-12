#ifndef COLECCIONES_H
#define COLECCIONES_H

#include "../dominio/presentacion.h"
#include "../dominio/artista.h"
#include "../dominio/escenario.h"

// =======================================================
// DEFINICIÓN DE LOS TDA (Colecciones Dinámicas)
// =======================================================
typedef struct {
    Presentacion* arreglo;
    int capacidad;
    int validos;
} ColeccionPresentaciones;

typedef struct {
    Artista* arreglo;
    int capacidad;
    int validos;
} ColeccionArtistas;

typedef struct {
    Escenario* arreglo;
    int capacidad;
    int validos;
} ColeccionEscenarios;

// =======================================================
// FUNCIONES BÁSICAS DE GESTIÓN (CRUD en memoria)
// =======================================================

// --- Para Presentaciones ---
ColeccionPresentaciones inicializarColeccionPresentaciones(void);
int agregarPresentacion(ColeccionPresentaciones* coleccion, Presentacion unaPresentacion);
Presentacion obtenerPresentacion(ColeccionPresentaciones* coleccion, int indice);
int actualizarPresentacion(ColeccionPresentaciones* coleccion, int indice, Presentacion presentacionModificada);
int buscarIndicePresentacionPorId(ColeccionPresentaciones* coleccion, int idBuscado);
int obtenerCantidadPresentaciones(ColeccionPresentaciones* coleccion);
int obtenerSiguienteIdPresentacion(ColeccionPresentaciones* coleccion);
void eliminarPresentacionDeMemoria(ColeccionPresentaciones* coleccion, int indice);
void liberarColeccionPresentaciones(ColeccionPresentaciones* coleccion);

int eliminarPresentacionesDeMemoriaPorArtista(ColeccionPresentaciones* coleccion, int idArtista);
int eliminarPresentacionesDeMemoriaPorEscenario(ColeccionPresentaciones* coleccion, int idEscenario);

// --- Para Artistas ---
ColeccionArtistas inicializarColeccionArtistas(void);
int agregarArtista(ColeccionArtistas* coleccion, Artista unArtista);
Artista obtenerArtista(ColeccionArtistas* coleccion, int indice);
int actualizarArtista(ColeccionArtistas* coleccion, int indice, Artista artistaModificado);
int buscarIndiceArtistaPorId(ColeccionArtistas* coleccion, int idBuscado);
int obtenerCantidadArtistas(ColeccionArtistas* coleccion);
int obtenerSiguienteIdArtista(ColeccionArtistas* coleccion);
void eliminarArtistaDeMemoria(ColeccionArtistas* coleccion, int indice);
void liberarColeccionArtistas(ColeccionArtistas* coleccion);

// --- Para Escenarios ---
ColeccionEscenarios inicializarColeccionEscenarios(void);
int agregarEscenario(ColeccionEscenarios* coleccion, Escenario unEscenario);
Escenario obtenerEscenario(ColeccionEscenarios* coleccion, int indice);
int actualizarEscenario(ColeccionEscenarios* coleccion, int indice, Escenario escenarioModificado);
int buscarIndiceEscenarioPorId(ColeccionEscenarios* coleccion, int idBuscado);
int obtenerCantidadEscenarios(ColeccionEscenarios* coleccion);
int obtenerSiguienteIdEscenario(ColeccionEscenarios* coleccion);
void eliminarEscenarioDeMemoria(ColeccionEscenarios* coleccion, int indice);
void liberarColeccionEscenarios(ColeccionEscenarios* coleccion);

// =======================================================
// FUNCIONES DE ORDENAMIENTO RECURSIVO
// =======================================================

void ordenarColeccionArtistasAlfabeticamente(ColeccionArtistas* coleccion);
void ordenarColeccionEscenariosAlfabeticamente(ColeccionEscenarios* coleccion);
void ordenarColeccionPresentacionesAlfabeticamente(ColeccionPresentaciones* coleccion);

#endif