#ifndef MENU_USUARIO_H
#define MENU_USUARIO_H

#include "../dominio/usuario.h"
#include "../logica/coleccion_artistas.h"
#include "../logica/coleccion_escenarios.h"
#include "../logica/coleccion_presentaciones.h"

void menuUsuario(Usuarios usuario, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, ColeccionPresentaciones* colPresentaciones);
int mostrarMenuUsuario(Usuarios usuario);

#endif
