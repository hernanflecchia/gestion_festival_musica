#include <stdio.h>
#include <stdlib.h>
#include "artista.h"

void mostrarArtistaAdmin(Artista artista) {
    printf("ID: %d | Nombre: %-20s | Genero: %s\n", artista.id, artista.nombre, artista.genero);
}

void mostrarArtistaUsuario(Artista artista) {
    printf("Nombre: %-20s | Genero: %s\n", artista.nombre, artista.genero);
}