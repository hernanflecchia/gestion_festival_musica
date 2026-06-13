#ifndef MENU_PRESENTACIONES_H
#define MENU_PRESENTACIONES_H

#include <stdbool.h>
#include "../logica/coleccion_presentaciones.h"
#include "../dominio/presentacion.h"

int mostrarMenuPresentaciones(void);
void mostrarListadoPresentaciones(ColeccionPresentaciones* colPresentaciones, bool esAdmin);
Presentacion pedirDatosNuevaPresentacion(void);
Presentacion pedirDatosModificadosPresentacion(Presentacion presentacionExistente);

#endif