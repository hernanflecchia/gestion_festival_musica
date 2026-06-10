#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H

#include "colecciones.h"
#include "../dominio/usuario.h"

// Estructuras exclusivas para persistencia (disco)
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
    char valido; // 'S' para activo, 'N' para borrado lógico (Auditoría)
} PresentacionArchivo;

typedef struct stArtistaArchivo {
    int id;
    char nombre[50];
    char genero[30];
    char valido;
} ArtistaArchivo;

typedef struct stEscenarioArchivo {
    int id;
    char nombre[50];
    char valido;
} EscenarioArchivo;

// Verifica si existe el archivo y crea el administrador por defecto si no existe
void inicializarArchivoUsuarios(void);

// Funciones para persistencia binaria
int guardarPresentacionesBinario(const char* nombreArchivo, ColeccionPresentaciones coleccion);
ColeccionPresentaciones cargarPresentacionesBinario(const char* nombreArchivo);

// Función para exportar los datos a texto
int exportarPresentacionesATexto(const char* nombreArchivoTxt, ColeccionPresentaciones coleccion);

// Prototipos utilitarios de mapeo (transforman un modelo en otro)
PresentacionArchivo transformarAPresentacionArchivo(Presentacion pMemoria);
Presentacion transformarAPresentacionMemoria(PresentacionArchivo pDisco);

#endif