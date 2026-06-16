#ifndef MENU_ADMIN_H
#define MENU_ADMIN_H

#include "../dominio/usuario.h"
#include "../logica/coleccion_artistas.h"
#include "../logica/coleccion_escenarios.h"
#include "../logica/coleccion_presentaciones.h"

void menuAdmin(Usuarios usuario, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, ColeccionPresentaciones* colPresentaciones);
int mostrarMenuAdmin(Usuarios usuario);

#endif
