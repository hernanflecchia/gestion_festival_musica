#ifndef GESTOR_ARCHIVOS_USUARIOS_H
#define GESTOR_ARCHIVOS_USUARIOS_H
#define ARCHIVO_USUARIOS "usuarios.bin"

#include "../dominio/usuario.h"

// =====================================
// PROTOTIPOS PARA GESTION EN DISCO
// =====================================
// Verifica si existe el archivo y crea el administrador por defecto si no existe
void inicializarArchivoUsuarios(void);
// Devuelve el Usuario o en caso que no exista el usuario o si la contraseña es incorrecta devuelve usuario.rol = -1 
Usuarios validarLogin(Usuarios usuarioIngresado);
// Devuelve 1 si el usuario se guardó correctamente y 0 si hubo un error
int guardarUsuario(Usuarios nuevoUsuario);

#endif