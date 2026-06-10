#ifndef PRESENTACION_H
#define PRESENTACION_H

#include "tipos_seguros.h"

typedef struct stPresentacion {
    int id;
    int idArtista;
    int idEscenario;
    Horario inicio;
    Duracion duracion;
} Presentacion;

// Prototipo de la función para mostrar la presentación
void mostrarPresentacion(Presentacion presentacion);

#endif