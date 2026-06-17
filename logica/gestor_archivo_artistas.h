#ifndef GESTOR_ARCHIVOS_ARTISTAS_H
#define GESTOR_ARCHIVOS_ARTISTAS_H
#define ARCHIVO_ARTISTAS "artistas.bin"

#include <stdbool.h>
#include "coleccion_artistas.h"

// =====================================
// PROTOTIPOS PARA GESTION EN DISCO
// =====================================
int guardarArtistaEnArchivo(ArtistaArchivo nuevoArtista);
void cargarArtistasDePruebaAlArchivo();
void cargarArtistasDesdeArchivo(ColeccionArtistas* coleccion);
int exportarArtistasATexto(const char* nombreArchivoTxt, ColeccionArtistas* coleccion, bool esAdmin);
int modificarArtistaEnArchivo(ArtistaArchivo artistaModificado);
int bajaLogicaArtistaEnArchivo(int idBuscado);
ColeccionArtistas obtenerArtistasEliminados();

// Utilitarios de mapeo (transforman un modelo en otro)
ArtistaArchivo transformarAArtistaArchivo(Artista artistaMemoria);
Artista transformarAArtistaMemoria(ArtistaArchivo artistaDisco);

#endif