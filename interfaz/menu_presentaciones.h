#ifndef MENU_PRESENTACIONES_H
#define MENU_PRESENTACIONES_H

#include "../logica/coleccion_presentaciones.h"

int mostrarMenuPresentaciones(void);
Presentacion pedirDatosNuevaPresentacion(void);
int pedirIdGenerico(const char* nombreEntidad); 
Presentacion pedirDatosModificadosPresentacion(Presentacion presentacionExistente);

#endif