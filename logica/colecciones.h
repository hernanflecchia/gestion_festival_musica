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
void liberarColeccionPresentaciones(ColeccionPresentaciones* coleccion);

// --- Para Artistas ---
ColeccionArtistas inicializarColeccionArtistas(void);
int agregarArtista(ColeccionArtistas* coleccion, Artista unArtista);
Artista obtenerArtista(ColeccionArtistas* coleccion, int indice);
int actualizarArtista(ColeccionArtistas* coleccion, int indice, Artista artistaModificado);
void liberarColeccionArtistas(ColeccionArtistas* coleccion);

// --- Para Escenarios ---
ColeccionEscenarios inicializarColeccionEscenarios(void);
int agregarEscenario(ColeccionEscenarios* coleccion, Escenario unEscenario);
Escenario obtenerEscenario(ColeccionEscenarios* coleccion, int indice);
int actualizarEscenario(ColeccionEscenarios* coleccion, int indice, Escenario escenarioModificado);
void liberarColeccionEscenarios(ColeccionEscenarios* coleccion);

// =======================================================
// FUNCIONES DE BÚSQUEDA
// =======================================================
// Devuelven el índice donde está guardado, o -1 si no existe

int buscarPosicionArtistaRecursivo(Artista arreglo[], int validos, int idBuscado, int indiceActual);
int buscarPosicionEscenarioRecursivo(Escenario arreglo[], int validos, int idBuscado, int indiceActual);
int buscarPosicionPresentacionRecursivo(Presentacion arreglo[], int validos, int idBuscado, int indiceActual);

#endif