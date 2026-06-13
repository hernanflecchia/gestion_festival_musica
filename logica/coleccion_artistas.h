#ifndef COLECCION_ARTISTAS_H
#define COLECCION_ARTISTAS_H

#include "../dominio/artista.h"

// ==========================================
// DEFINICIÓN DEL TDA (Coleccion Dinámica)
// ==========================================
typedef struct {
    Artista* arreglo;
    int capacidad;
    int validos;
} ColeccionArtistas;

// =====================================
// PROTOTIPOS PARA GESTION EN MEMORIA
// =====================================
ColeccionArtistas inicializarColeccionArtistas(void);
int agregarArtista(ColeccionArtistas* coleccion, Artista unArtista);
Artista obtenerArtista(ColeccionArtistas* coleccion, int indice);
int actualizarArtista(ColeccionArtistas* coleccion, int indice, Artista artistaModificado);
int buscarIndiceArtistaPorId(ColeccionArtistas* coleccion, int idBuscado);
int obtenerCantidadArtistas(ColeccionArtistas* coleccion);
int obtenerSiguienteIdArtista(ColeccionArtistas* coleccion);
void eliminarArtistaDeMemoria(ColeccionArtistas* coleccion, int indice);
void liberarColeccionArtistas(ColeccionArtistas* coleccion);
void ordenarColeccionArtistasAlfabeticamente(ColeccionArtistas* coleccion);

#endif