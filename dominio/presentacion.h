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

typedef struct stPresentacionArchivo {
    int id;
    int idArtista;
    int idEscenario;
    HorarioArchivo inicio;
    DuracionArchivo duracion;
    char valido; // 'S' para activo, 'N' para borrado lógico (Auditoría)
} PresentacionArchivo;

// Prototipo de la función para mostrar la presentación
void mostrarPresentacionAdmin(Presentacion presentacion);
void mostrarPresentacionUsuario(Presentacion presentacion);

#endif