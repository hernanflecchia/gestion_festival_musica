#include <stdio.h>
#include "scanner.h"
#include "../logica/coleccion_artistas.h"

Artista pedirDatosNuevoArtista(void) {
    Artista nuevo;
    printf("\n--- ALTA DE ARTISTA ---\n");
    printf("Ingrese el nombre del artista: ");
    scanString(nuevo.nombre, DIM_ARTISTA_NOMBRE);
    printf("Ingrese el genero musical: ");
    scanString(nuevo.genero, DIM_GENERO);
    return nuevo;
}

Artista pedirDatosModificadosArtista(Artista artistaExistente) {
    printf("\n--- MODIFICANDO ARTISTA ---\n");
    printf("Modificando los datos del ID: %d\n", artistaExistente.id);
    printf("Nuevo nombre (anterior: %s): ", artistaExistente.nombre);
    scanString(artistaExistente.nombre, DIM_ARTISTA_NOMBRE);
    printf("Nuevo genero (anterior: %s): ", artistaExistente.genero);
    scanString(artistaExistente.genero, DIM_GENERO);
    return artistaExistente;
}

int mostrarMenuArtistas(void) {
    printf("\n--- GESTION DE ARTISTAS ---\n");
    printf("1. Dar de alta nuevo Artista\n");
    printf("2. Modificar Artista existente\n");
    printf("3. Dar de baja (Eliminar) Artista\n");
    printf("4. Listar Artistas por pantalla\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}