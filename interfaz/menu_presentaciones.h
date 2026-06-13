#ifndef MENU_PRESENTACIONES_H
#define MENU_PRESENTACIONES_H

#include "../logica/coleccion_presentaciones.h"
#include "../dominio/presentacion.h"

int mostrarMenuPresentaciones(void);
void mostrarListadoPresentaciones(ColeccionPresentaciones* colPresentaciones);
Presentacion pedirDatosNuevaPresentacion(void);
Presentacion pedirDatosModificadosPresentacion(Presentacion presentacionExistente);

#endif