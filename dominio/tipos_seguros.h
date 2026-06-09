#ifndef TIPOS_SEGUROS_H
#define TIPOS_SEGUROS_H

// Estructura para manejar un horario específico del reloj
typedef struct stHorario {
    int horas;
    int minutos;
    int esValido; // Funciona como flag: 1 es Válido, 0 es Inválido
} Horario;

// Estructura para manejar la cantidad de tiempo que dura un show
typedef struct stDuracion {
    int horas;
    int minutos;
    int esValido; // Funciona como flag: 1 es Válido, 0 es Inválido
} Duracion;

// Prototipos de las funciones validadoras
Horario crearHorario(int horas, int minutos);
Duracion crearDuracion(int horas, int minutos);

#endif