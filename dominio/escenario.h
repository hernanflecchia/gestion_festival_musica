#ifndef ESCENARIO_H
#define ESCENARIO_H
#define DIM_ESCENARIO_NOMBRE 50

typedef struct stEscenario {
    int id;
    char nombre[DIM_ESCENARIO_NOMBRE];
} Escenario;

typedef struct stEscenarioArchivo {
    int id;
    char nombre[DIM_ESCENARIO_NOMBRE];
    char valido; // 'S' para activo, 'N' para borrado lógico (Auditoría)
} EscenarioArchivo;

// Prototipo de la función para mostrar los datos del escenario
void mostrarEscenario(Escenario escenario);

#endif