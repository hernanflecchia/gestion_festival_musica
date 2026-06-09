#ifndef ESCENARIO_H
#define ESCENARIO_H

typedef struct stEscenario {
    int id;
    char nombre[50];
} Escenario;

// Prototipo de la función para mostrar los datos del escenario
void mostrarEscenario(Escenario escenario);

#endif