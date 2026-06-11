#ifndef ARTISTA_H
#define ARTISTA_H
#define DIM_NOMBRE 50
#define DIM_GENERO 30

typedef struct stArtista {
    int id;
    char nombre[DIM_NOMBRE];
    char genero[DIM_GENERO];
} Artista;

typedef struct stArtistaArchivo {
    int id;
    char nombre[DIM_NOMBRE];
    char genero[DIM_GENERO];
    char valido; // 'S' para activo, 'N' para borrado lógico (Auditoría)
} ArtistaArchivo;

// Prototipo de la función para mostrar los datos del artista
void mostrarArtista(Artista artista);

#endif