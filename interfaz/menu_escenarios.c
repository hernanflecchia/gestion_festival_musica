#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "../logica/coleccion_escenarios.h"

int mostrarMenuEscenarios(void) {
    system("clear");
    printf("\n--- GESTION DE ESCENARIOS ---\n");
    printf("1. Dar de alta nuevo Escenario\n");
    printf("2. Modificar Escenario existente\n");
    printf("3. Dar de baja (Eliminar) Escenario\n");
    printf("4. Listar Escenarios por pantalla\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}

void mostrarListadoEscenarios(ColeccionEscenarios* colEscenarios) {
    system("clear");
    printf("\n--- LISTADO DE ESCENARIOS ---\n");
    for (int i = 0; i < colEscenarios->validos; i++) {
        Escenario escenario = obtenerEscenario(colEscenarios, i);
        if (escenario.id != -1) {
            mostrarEscenarioUsuario(escenario);
        }
    }
    printf("\nPresione Enter para continuar...");
    getchar();
}

Escenario pedirDatosNuevoEscenario(void) {
    Escenario nuevo;
    
    system("clear");
    printf("\n--- ALTA DE ESCENARIO ---\n");
    printf("Ingrese el nombre del escenario: ");
    scanString(nuevo.nombre, DIM_ESCENARIO_NOMBRE);
    return nuevo;
}

Escenario pedirDatosModificadosEscenario(Escenario escenarioExistente) {
    system("clear");
    printf("\n--- MODIFICANDO ESCENARIO ---\n");
    printf("Modificando los datos del ID: %d\n", escenarioExistente.id);
    printf("Nuevo nombre (anterior: %s): ", escenarioExistente.nombre);
    scanString(escenarioExistente.nombre, DIM_ESCENARIO_NOMBRE);
    return escenarioExistente;
}