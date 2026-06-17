#ifndef COLECCION_PRESENTACIONES_H
#define COLECCION_PRESENTACIONES_H
#define CAPACIDAD_PRESENTACIONES 10

#include "../dominio/presentacion.h"
#include "../dominio/tipos_seguros.h"
#include "coleccion_artistas.h"

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
void cargarPresentacionesDePrueba(ColeccionPresentaciones* coleccion);
int agregarPresentacion(ColeccionPresentaciones* coleccion, Presentacion unaPresentacion);
Presentacion obtenerPresentacion(ColeccionPresentaciones* coleccion, int indice);
int actualizarPresentacion(ColeccionPresentaciones* coleccion, int indice, Presentacion presentacionModificada);
int buscarIndicePresentacionPorId(ColeccionPresentaciones* coleccion, int idBuscado);
int obtenerCantidadPresentaciones(ColeccionPresentaciones* coleccion);
int obtenerSiguienteIdPresentacion(ColeccionPresentaciones* coleccion);
void eliminarPresentacionDeMemoria(ColeccionPresentaciones* coleccion, int indice);
void liberarColeccionPresentaciones(ColeccionPresentaciones* coleccion);
void ordenarColeccionPresentacionesAlfabeticamente(ColeccionPresentaciones* coleccion, ColeccionArtistas* colArtistas);
ColeccionPresentaciones filtrarPresentacionesPorArtista(ColeccionPresentaciones* originales, int idBuscado, int cantidad);
ColeccionPresentaciones filtrarPresentacionesPorEscenario(ColeccionPresentaciones* originales, int idBuscado, int cantidad);

int eliminarPresentacionesDeMemoriaPorArtista(ColeccionPresentaciones* coleccion, int idArtista);
int eliminarPresentacionesDeMemoriaPorEscenario(ColeccionPresentaciones* coleccion, int idEscenario);

// Validaciones
// Si falla, retorna una Presentacion con id = -1 (Valor centinela).
Presentacion crearPresentacionValidada(ColeccionPresentaciones* coleccion, Presentacion datosTemporales);
#endif