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
// ARCHIVO PRESENTACIONES
// ==========================================

// Funciones para persistencia binaria
int guardarPresentacionesBinario(const char* nombreArchivo, ColeccionPresentaciones coleccion);
ColeccionPresentaciones cargarPresentacionesBinario(const char* nombreArchivo);
// Función para exportar los datos a texto
int exportarPresentacionesATexto(const char* nombreArchivoTxt, ColeccionPresentaciones coleccion);
// Prototipos utilitarios de mapeo (transforman un modelo en otro)
PresentacionArchivo transformarAPresentacionArchivo(Presentacion pMemoria);
Presentacion transformarAPresentacionMemoria(PresentacionArchivo pDisco);

#endif