#include <stdio.h>
#include <stdlib.h>
#include "presentacion.h"

PresentacionArchivo crearNuevaPresentacion() {
    PresentacionArchivo nuevaPresentacion;
    
    nuevaPresentacion.id = -1; 
    nuevaPresentacion.valido = 'S'; 

    printf("\n=== ALTA DE NUEVA PRESENTACION ===\n");

    printf("Ingrese el ID de la presentacion (o ingrese -1 para cancelar): ");
    scanf("%d", &nuevaPresentacion.id);

    if (nuevaPresentacion.id == -1) {
        printf("Alta cancelada por el usuario.\n");
        return nuevaPresentacion; 
    }

    printf("Ingrese el ID del Artista asignado: ");
    scanf("%d", &nuevaPresentacion.idArtista);

    printf("Ingrese el ID del Escenario donde tocara: ");
    scanf("%d", &nuevaPresentacion.idEscenario);

    // Acá vamos a sumar la parte de los horarios...

    return nuevaPresentacion;
}

void mostrarPresentacion(Presentacion presentacion) {
    printf("\n--- Detalle de la Presentacion ---\n");
    printf("ID Presentacion : %d\n", presentacion.id);
    printf("ID Artista      : %d\n", presentacion.idArtista);
    printf("ID Escenario    : %d\n", presentacion.idEscenario);
    
    // Usamos %02d para que los números menores a 10 se impriman con un cero adelante (ej: 09:05)
    printf("Inicio          : %02d:%02d hs\n", presentacion.inicio.horas, presentacion.inicio.minutos);
    printf("Duracion        : %02d:%02d hs\n", presentacion.duracion.horas, presentacion.duracion.minutos);
    printf("----------------------------------\n");
}