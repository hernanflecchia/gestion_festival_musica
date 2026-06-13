#include <stdio.h>
#include <stdlib.h>
#include "presentacion.h"

void mostrarPresentacionAdmin(Presentacion presentacion, char nombreArtista[], char nombreEscenario[]) {
    printf("ID: %d | Artista: %-20s | Escenario: %-20s | Inicio: %02d:%02d hs | Duracion: %02d:%02d hs\n", 
           presentacion.id, 
           nombreArtista, 
           nombreEscenario,
           presentacion.inicio.horas, presentacion.inicio.minutos,
           presentacion.duracion.horas, presentacion.duracion.minutos);
}

void mostrarPresentacionUsuario(Presentacion presentacion, char nombreArtista[], char nombreEscenario[]) {
    printf("Artista: %-20s | Escenario: %-20s | Inicio: %02d:%02d hs | Duracion: %02d:%02d hs\n", 
           nombreArtista, 
           nombreEscenario,
           presentacion.inicio.horas, presentacion.inicio.minutos,
           presentacion.duracion.horas, presentacion.duracion.minutos);
}