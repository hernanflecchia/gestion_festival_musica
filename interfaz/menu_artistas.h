#ifndef MENU_ARTISTAS_H
#define MENU_ARTISTAS_H

#include "../dominio/artista.h"

int mostrarMenuArtistas(void);
Artista pedirDatosNuevoArtista(void);
int pedirIdGenerico(const char* nombreEntidad); 
Artista pedirDatosModificadosArtista(Artista artistaExistente);

#endif