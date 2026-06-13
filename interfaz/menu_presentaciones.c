#include <stdio.h>
#include "scanner.h"
#include "../logica/coleccion_presentaciones.h"

Presentacion pedirDatosNuevoPresentacion(void) {
    Presentacion nuevo;
    printf("\n--- ALTA DE PRESENTACION ---\n");
    printf("Ingrese el nombre del presentacion: ");

    return nuevo;
}

Presentacion pedirDatosModificadosPresentacion(Presentacion presentacionExistente) {
    printf("\n--- MODIFICANDO PRESENTACION ---\n");
    printf("Modificando los datos del ID: %d\n", presentacionExistente.id);

    return presentacionExistente;
}

int mostrarMenuPresentaciones(void) {
    printf("\n--- GESTION DE PRESENTACIONES ---\n");
    printf("1. Dar de alta nueva Presentacion\n");
    printf("2. Modificar Presentacion existente\n");
    printf("3. Dar de baja (Eliminar) Presentacion\n");
    printf("4. Listar Presentaciones por pantalla\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}