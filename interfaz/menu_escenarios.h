#ifndef MENU_ESCENARIOS_H
#define MENU_ESCENARIOS_H

#include "../dominio/escenario.h"

int mostrarMenuEscenarios(void);
Escenario pedirDatosNuevoEscenario(void);
int pedirIdGenerico(const char* nombreEntidad); 
Escenario pedirDatosModificadosEscenario(Escenario escenarioExistente);

#endif