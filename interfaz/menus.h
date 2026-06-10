#ifndef MENUS_H
#define MENUS_H

#include "../dominio/usuario.h"

int mostrarMenuInicio(void);
int mostrarMenuPrincipal(void);

void menuAdmin(Usuarios usua);
void menuUsuario(Usuarios usua);

Usuarios pedirDatosNuevoUsuario(void);
Usuarios pedirDatosLogin(void);

#endif