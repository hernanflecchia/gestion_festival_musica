#include <stdio.h>
#include <stdlib.h>
#include "artista.h"

void mostrarArtista(Artista artista) {
    printf("ID: %d | Nombre: %-20s | Genero: %s\n", artista.id, artista.nombre, artista.genero);
}