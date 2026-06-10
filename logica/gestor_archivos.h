#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H

#include "colecciones.h"

typedef struct stDuracionArchivo {
    int horas;
    int minutos;
} DuracionArchivo;

typedef struct stHorarioArchivo {
    int horas;
    int minutos;
} HorarioArchivo;

typedef struct stPresentacionArchivo {
    int id;
    int idArtista;
    int idEscenario;
    HorarioArchivo inicio;
    DuracionArchivo duracion;
} PresentacionArchivo;

// Funciones para persistencia binaria
int guardarPresentacionesBinario(const char* nombreArchivo, ColeccionPresentaciones coleccion);
ColeccionPresentaciones cargarPresentacionesBinario(const char* nombreArchivo);

// Función para exportar los datos a texto
int exportarPresentacionesATexto(const char* nombreArchivoTxt, ColeccionPresentaciones coleccion);

// Prototipos utilitarios de mapeo (transforman un modelo en otro)
PresentacionArchivo transformarAPresentacionArchivo(Presentacion pMemoria);
Presentacion transformarAPresentacionMemoria(PresentacionArchivo pDisco);

#endif