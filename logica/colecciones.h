#ifndef COLECCIONES_H
#define COLECCIONES_H

#include "../dominio/presentacion.h"

// Definición del TDA Colección
typedef struct {
    Presentacion* arreglo;
    int capacidad;
    int validos;
} ColeccionPresentaciones;

// Prototipos
ColeccionPresentaciones inicializarColeccion();
int agregarPresentacion(ColeccionPresentaciones* coleccion, Presentacion nueva);
Presentacion obtenerPresentacion(ColeccionPresentaciones coleccion, int indice);
void liberarColeccion(ColeccionPresentaciones* coleccion);

#endif