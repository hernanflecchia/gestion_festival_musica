#include <stdio.h>
#include <stdlib.h>
#include "artista.h"

void mostrarArtistaAdmin(Artista artista) {
    printf("ID: %d | Nombre: %-*s | Genero: %s\n", artista.id, DIM_ARTISTA_NOMBRE, artista.nombre, artista.genero);
}

void mostrarArtistaUsuario(Artista artista) {
    printf("Nombre: %-*s | Genero: %s\n", DIM_ARTISTA_NOMBRE, artista.nombre, artista.genero);
}