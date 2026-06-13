#ifndef COLECCION_PRESENTACIONES_H
#define COLECCIONES_H

#include "../dominio/presentacion.h"

// ==========================================
// DEFINICIÓN DEL TDA (Coleccion Dinámica)
// ==========================================
typedef struct {
    Presentacion* arreglo;
    int capacidad;
    int validos;
} ColeccionPresentaciones;

// =====================================
// PROTOTIPOS PARA GESTION EN MEMORIA
// =====================================
ColeccionPresentaciones inicializarColeccionPresentaciones(void);
int agregarPresentacion(ColeccionPresentaciones* coleccion, Presentacion unaPresentacion);
Presentacion obtenerPresentacion(ColeccionPresentaciones* coleccion, int indice);
int actualizarPresentacion(ColeccionPresentaciones* coleccion, int indice, Presentacion presentacionModificada);
int buscarIndicePresentacionPorId(ColeccionPresentaciones* coleccion, int idBuscado);
int obtenerCantidadPresentaciones(ColeccionPresentaciones* coleccion);
int obtenerSiguienteIdPresentacion(ColeccionPresentaciones* coleccion);
void eliminarPresentacionDeMemoria(ColeccionPresentaciones* coleccion, int indice);
void liberarColeccionPresentaciones(ColeccionPresentaciones* coleccion);
void ordenarColeccionPresentacionesAlfabeticamente(ColeccionPresentaciones* coleccion);

int eliminarPresentacionesDeMemoriaPorArtista(ColeccionPresentaciones* coleccion, int idArtista);
int eliminarPresentacionesDeMemoriaPorEscenario(ColeccionPresentaciones* coleccion, int idEscenario);

// Validaciones
// Verifica si el escenario está libre en ese rango (Retorna 1 si está libre, 0 si hay solapamiento).
int verificarDisponibilidadEscenario(ColeccionPresentaciones historial, int idEscenario, Horario inicio, Duracion duracion);
// Verifica si el artista está libre en ese rango (Retorna 1 si está libre, 0 si hay solapamiento).
int verificarDisponibilidadArtista(ColeccionPresentaciones historial, int idArtista, Horario inicio, Duracion duracion);
// Función principal que intenta crear la presentación. 
// Si pasa las dos validaciones anteriores, retorna la Presentacion con ID válido.
// Si falla, retorna una Presentacion con id = -1 (Valor centinela).
Presentacion crearPresentacionValidada(ColeccionPresentaciones historial, int idArtista, int idEscenario, Horario inicio, Duracion duracion);
#endif