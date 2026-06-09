#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H

#include "./colecciones.h"

// Funciones para persistencia binaria
int guardarPresentacionesBinario(const char* nombreArchivo, ColeccionPresentaciones coleccion);
ColeccionPresentaciones cargarPresentacionesBinario(const char* nombreArchivo);

// Función para exportar los datos a texto
int exportarPresentacionesATexto(const char* nombreArchivoTxt, ColeccionPresentaciones coleccion);

#endif