#include "tipos_seguros.h"

// Función para inicializar y validar un Horario
Horario crearHorario(int horas, int minutos) {
    Horario nuevoHorario;
    
    // Validación: Las horas deben estar entre 0 y 23, y los minutos entre 0 y 59
    if (horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59) {
        nuevoHorario.horas = horas;
        nuevoHorario.minutos = minutos;
        nuevoHorario.esValido = 1; // 1 significa verdadero/válido
    } else {
        // Valores por defecto para un horario inválido
        nuevoHorario.horas = -1;
        nuevoHorario.minutos = -1;
        nuevoHorario.esValido = 0; // 0 significa falso/inválido
    }
    
    return nuevoHorario;
}

// Función para inicializar y validar una Duración
Duracion crearDuracion(int horas, int minutos) {
    Duracion nuevaDuracion;
    
    // Validación: Los minutos deben estar entre 0 y 59. 
    // Las horas no tienen límite máximo (pueden ser > 24), pero no pueden ser negativas.
    if (horas >= 0 && minutos >= 0 && minutos <= 59) {
        nuevaDuracion.horas = horas;
        nuevaDuracion.minutos = minutos;
        nuevaDuracion.esValido = 1;
    } else {
        // Valores por defecto para una duración inválida
        nuevaDuracion.horas = -1;
        nuevaDuracion.minutos = -1;
        nuevaDuracion.esValido = 0;
    }
    
    return nuevaDuracion;
}