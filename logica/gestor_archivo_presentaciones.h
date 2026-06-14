#ifndef GESTOR_ARCHIVOS_PRESENTACIONES_H
#define GESTOR_ARCHIVOS_PRESENTACIONES_H
#define ARCHIVO_PRESENTACIONES "presentaciones.bin"

#include "coleccion_presentaciones.h"
#include "coleccion_artistas.h"
#include "coleccion_escenarios.h"

// =====================================
// PROTOTIPOS PARA GESTION EN DISCO
// =====================================
int guardarPresentacionEnArchivo(PresentacionArchivo nuevaPresentacion); 
void cargarPresentacionesDesdeArchivo(ColeccionPresentaciones* coleccion);
int exportarPresentacionesATexto(const char* nombreArchivoTxt, ColeccionPresentaciones* coleccion, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios);
int modificarPresentacionEnArchivo(PresentacionArchivo presentacionModificado);
int bajaLogicaPresentacionEnArchivo(int idBuscado);

// Utilitarios de mapeo (transforman un modelo en otro)
PresentacionArchivo transformarAPresentacionArchivo(Presentacion presentacionMemoria);
Presentacion transformarAPresentacionMemoria(PresentacionArchivo presentacionDisco);

// Bajas por Artistas o Escenarios
int bajaLogicaPresentacionesEnArchivoPorArtista(int idArtistaBuscado);
int bajaLogicaPresentacionesEnArchivoPorEscenario(int idEscenarioBuscado);

#endif