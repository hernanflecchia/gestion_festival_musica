#ifndef MENU_ESCENARIOS_H
#define MENU_ESCENARIOS_H

#include "../dominio/escenario.h"
#include "../logica/coleccion_escenarios.h"

int mostrarMenuEscenarios(void);
void mostrarListadoEscenarios(ColeccionEscenarios* colEscenarios);
Escenario pedirDatosNuevoEscenario(void);
Escenario pedirDatosModificadosEscenario(Escenario escenarioExistente);

#endif