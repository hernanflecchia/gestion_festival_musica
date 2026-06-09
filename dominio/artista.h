#ifndef ARTISTA_H
#define ARTISTA_H

typedef struct stArtista {
    int id;
    char nombre[50];
    char genero[30];
} Artista;

// Prototipo de la función para mostrar los datos del artista
void mostrarArtista(Artista artista);

#endif