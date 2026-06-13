#include <stdio.h>
#include "scanner.h"
#include "../logica/coleccion_escenarios.h"

Escenario pedirDatosNuevoEscenario(void) {
    Escenario nuevo;
    printf("\n--- ALTA DE ESCENARIO ---\n");
    printf("Ingrese el nombre del escenario: ");
    scanString(nuevo.nombre, DIM_ESCENARIO_NOMBRE);
    return nuevo;
}

Escenario pedirDatosModificadosEscenario(Escenario escenarioExistente) {
    printf("\n--- MODIFICANDO ESCENARIO ---\n");
    printf("Modificando los datos del ID: %d\n", escenarioExistente.id);
    printf("Nuevo nombre (anterior: %s): ", escenarioExistente.nombre);
    scanString(escenarioExistente.nombre, DIM_ESCENARIO_NOMBRE);
    return escenarioExistente;
}

int mostrarMenuEscenarios(void) {
    printf("\n--- GESTION DE ESCENARIOS ---\n");
    printf("1. Dar de alta nuevo Escenario\n");
    printf("2. Modificar Escenario existente\n");
    printf("3. Dar de baja (Eliminar) Escenario\n");
    printf("4. Listar Escenarios por pantalla\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}