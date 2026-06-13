#ifndef MENU_ARTISTAS_H
#define MENU_ARTISTAS_H

#include "../dominio/artista.h"

int mostrarMenuArtistas(void);
Artista pedirDatosNuevoArtista(void);
Artista pedirDatosModificadosArtista(Artista artistaExistente);

#endif