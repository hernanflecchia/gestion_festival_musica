#ifndef MENU_PRESENTACIONES_H
#define MENU_PRESENTACIONES_H

#include <stdbool.h>
#include "../logica/coleccion_presentaciones.h"
#include "../logica/coleccion_artistas.h"
#include "../logica/coleccion_escenarios.h"
#include "../dominio/presentacion.h"

int mostrarMenuPresentaciones(void);
void mostrarListadoPresentaciones(ColeccionPresentaciones* colPresentaciones, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, bool esAdmin);
int mostrarListadoPresentacionesPorArtista(int idArtista, ColeccionPresentaciones* colPresentaciones, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, bool esAdmin);
int mostrarListadoPresentacionesPorEscenario(int idEscenario, ColeccionPresentaciones* colPresentaciones, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, bool esAdmin);
Presentacion pedirDatosNuevaPresentacion(ColeccionArtistas* cArt, ColeccionEscenarios* cEsc);
Presentacion pedirDatosModificadosPresentacion(Presentacion presentacionExistente, ColeccionArtistas* cArt, ColeccionEscenarios* cEsc);

#endif