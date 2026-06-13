#ifndef MENU_ARTISTAS_H
#define MENU_ARTISTAS_H

#include <stdbool.h>
#include "../dominio/artista.h"
#include "../logica/coleccion_artistas.h"

int mostrarMenuArtistas(void);
void mostrarListadoArtistas(ColeccionArtistas* colArtistas, bool esAdmin);
Artista pedirDatosNuevoArtista(void);
Artista pedirDatosModificadosArtista(Artista artistaExistente);

#endif