#include <stdio.h>
#include <stdlib.h>
#include "escenario.h"

void mostrarEscenarioAdmin(Escenario escenario) {
    printf("ID: %d | Nombre: %-*s\n", escenario.id, DIM_ESCENARIO_NOMBRE, escenario.nombre);
}

void mostrarEscenarioUsuario(Escenario escenario) {
    printf("Nombre: %-*s\n", DIM_ESCENARIO_NOMBRE, escenario.nombre);
}