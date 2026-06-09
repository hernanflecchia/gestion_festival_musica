#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include "./colecciones.h"
#include "../Dominio/tipos_seguros.h"
#include "../Dominio/presentacion.h"

// Verifica si el escenario está libre en ese rango (Retorna 1 si está libre, 0 si hay solapamiento).
int verificarDisponibilidadEscenario(ColeccionPresentaciones historial, int idEscenario, Horario inicio, Duracion duracion);

// Verifica si el artista está libre en ese rango (Retorna 1 si está libre, 0 si hay solapamiento).
int verificarDisponibilidadArtista(ColeccionPresentaciones historial, int idArtista, Horario inicio, Duracion duracion);

// Función principal que intenta crear la presentación. 
// Si pasa las dos validaciones anteriores, retorna la Presentacion con ID válido.
// Si falla, retorna una Presentacion con id = -1 (Valor centinela).
Presentacion crearPresentacionValidada(ColeccionPresentaciones historial, int idArtista, int idEscenario, Horario inicio, Duracion duracion);

#endif