#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H
#define ARCHIVO_USUARIOS "usuarios.bin"
#define ARCHIVO_ARTISTAS "artistas.bin"
#define ARCHIVO_ESCENARIOS "escenarios.bin"
#define ARCHIVO_PRESENTACIONES "presentaciones.bin"

#include "colecciones.h"
#include "../dominio/usuario.h"

// ==========================================
// ARCHIVO USUARIOS
// ==========================================

// Verifica si existe el archivo y crea el administrador por defecto si no existe
void inicializarArchivoUsuarios(void);
// Devuelve el Usuario o en caso que no exista el usuario o si la contraseña es incorrecta devuelve usuario.rol = -1 
Usuarios validarLogin(Usuarios usuarioIngresado);
// Devuelve 1 si loguardo y 0 si hubo un error
int guardarUsuario(Usuarios nuevoUsuario);

// ==========================================
// ARCHIVO ARTISTAS
// ==========================================

// Funciones de persistencia de Artistas
int guardarArtistaEnArchivo(ArtistaArchivo nueva); 
void cargarArtistasDesdeArchivo(ColeccionArtistas* coleccion);
int exportarArtistasATexto(const char* nombreArchivoTxt, ColeccionArtistas* coleccion);

// Prototipos utilitarios de mapeo (transforman un modelo en otro)
ArtistaArchivo transformarAArtistaArchivo(Artista pMemoria);
Artista transformarAArtistaMemoria(ArtistaArchivo pDisco);

// ==========================================
// ARCHIVO ESCENARIOS
// ==========================================

// Funciones de persistencia de Escenarios
int guardarEscenarioEnArchivo(EscenarioArchivo nueva); 
void cargarEscenariosDesdeArchivo(ColeccionEscenarios* coleccion);
int exportarEscenariosATexto(const char* nombreArchivoTxt, ColeccionEscenarios* coleccion);

// Prototipos utilitarios de mapeo (transforman un modelo en otro)
EscenarioArchivo transformarAEscenarioArchivo(Escenario pMemoria);
Escenario transformarAEscenarioMemoria(EscenarioArchivo pDisco);

// ==========================================
// ARCHIVO PRESENTACIONES
// ==========================================

// Funciones de persistencia de Presentaciones
int guardarPresentacionEnArchivo(PresentacionArchivo nueva); 
void cargarPresentacionesDesdeArchivo(ColeccionPresentaciones* coleccion);
int exportarPresentacionesATexto(const char* nombreArchivoTxt, ColeccionPresentaciones* coleccion);

// Prototipos utilitarios de mapeo (transforman un modelo en otro)
PresentacionArchivo transformarAPresentacionArchivo(Presentacion pMemoria);
Presentacion transformarAPresentacionMemoria(PresentacionArchivo pDisco);

#endif