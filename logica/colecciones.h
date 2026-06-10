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
int agregarPresentacion(ColeccionPresentaciones* coleccion, Presentacion nueva);
Presentacion obtenerPresentacion(ColeccionPresentaciones coleccion, int indice);
int actualizarPresentacion(ColeccionPresentaciones* coleccion, int indice, Presentacion modificada);
void liberarColeccionPresentaciones(ColeccionPresentaciones* coleccion);

// --- Para Artistas ---
ColeccionArtistas inicializarColeccionArtistas(void);
int agregarArtista(ColeccionArtistas* coleccion, Artista nueva);
Artista obtenerArtista(ColeccionArtistas coleccion, int indice);
int actualizarArtista(ColeccionArtistas* coleccion, int indice, Artista modificada);
void liberarColeccionArtistas(ColeccionArtistas* coleccion);

// --- Para Escenarios ---
ColeccionEscenarios inicializarColeccionEscenarios(void);
int agregarEscenario(ColeccionEscenarios* coleccion, Escenario nueva);
Escenario obtenerEscenario(ColeccionEscenarios coleccion, int indice);
int actualizarEscenario(ColeccionEscenarios* coleccion, int indice, Escenario modificada);
void liberarColeccionEscenarios(ColeccionEscenarios* coleccion);

// =======================================================
// FUNCIONES DE BÚSQUEDA
// =======================================================
// Devuelven el índice donde está guardado, o -1 si no existe

int buscarPosicionArtistaRecursivo(Artista arreglo[], int validos, int idBuscado, int indiceActual);
int buscarPosicionEscenarioRecursivo(Escenario arreglo[], int validos, int idBuscado, int indiceActual);
int buscarPosicionPresentacionRecursivo(Presentacion arreglo[], int validos, int idBuscado, int indiceActual);

#endif