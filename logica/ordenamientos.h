#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include "colecciones.h"
#include "../dominio/artista.h"
#include "../dominio/escenario.h"

void insertarArtistaOrdenadoRecursivo(Artista arreglo[], int validos, Artista nuevo);
void insertarEscenarioOrdenadoRecursivo(Escenario arreglo[], int validos, Escenario nuevo);

#endif