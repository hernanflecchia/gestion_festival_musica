#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scanner.h"
#include "../logica/coleccion_presentaciones.h"
#include "../logica/coleccion_artistas.h"
#include "../logica/coleccion_escenarios.h"

int mostrarMenuPresentaciones(void) {
    system("clear");
    printf("\n--- GESTION DE PRESENTACIONES ---\n");
    printf("1. Dar de alta nueva Presentacion\n");
    printf("2. Modificar Presentacion existente\n");
    printf("3. Dar de baja (Eliminar) Presentacion\n");
    printf("4. Listar Presentaciones por pantalla\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}

void mostrarListadoPresentaciones(ColeccionPresentaciones* colPresentaciones, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, bool esAdmin) {
    
    system("clear");
    printf("\n--- LISTADO DE PRESENTACIONES ---\n");
    
    for (int i = 0; i < colPresentaciones->validos; i++) {
        Presentacion presentacion = obtenerPresentacion(colPresentaciones, i);
            
        int indiceArt = buscarIndiceArtistaPorId(colArtistas, presentacion.idArtista);
        Artista artista = obtenerArtista(colArtistas, indiceArt); 

        int indiceEsc = buscarIndiceEscenarioPorId(colEscenarios, presentacion.idEscenario);
        Escenario escenario = obtenerEscenario(colEscenarios, indiceEsc);

        if (esAdmin) {
            mostrarPresentacionAdmin(presentacion, artista.nombre, escenario.nombre);
        } else {
            mostrarPresentacionUsuario(presentacion, artista.nombre, escenario.nombre);
        }
    }
}

int mostrarListadoPresentacionesPorArtista(int idArtista, ColeccionPresentaciones* colPresentaciones, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, bool esAdmin) {
    system("clear");
    int validos = 0;
    for (int i = 0; i < colPresentaciones->validos; i++) {
        Presentacion presentacion = obtenerPresentacion(colPresentaciones, i);
        
        // Verificamos el valor centinela para saltar las presentaciones borradas
        if (presentacion.id != -1) { 
            if (presentacion.idArtista == idArtista) {
                int indiceArt = buscarIndiceArtistaPorId(colArtistas, presentacion.idArtista);
                Artista artista = obtenerArtista(colArtistas, indiceArt); 

                int indiceEsc = buscarIndiceEscenarioPorId(colEscenarios, presentacion.idEscenario);
                Escenario escenario = obtenerEscenario(colEscenarios, indiceEsc);

                if (esAdmin) {
                    mostrarPresentacionAdmin(presentacion, artista.nombre, escenario.nombre);
                } else {
                    mostrarPresentacionUsuario(presentacion, artista.nombre, escenario.nombre);
                }
                validos++;
            }
        }
    }
    return validos;
}

int mostrarListadoPresentacionesPorEscenario(int idEscenario, ColeccionPresentaciones* colPresentaciones, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, bool esAdmin) {
    system("clear");
    int validos = 0;
    for (int i = 0; i < colPresentaciones->validos; i++) {
        Presentacion presentacion = obtenerPresentacion(colPresentaciones, i);
        
        // Verificamos el valor centinela para saltar las presentaciones borradas
        if (presentacion.id != -1) { 
            if (presentacion.idEscenario == idEscenario) {
                int indiceArt = buscarIndiceArtistaPorId(colArtistas, presentacion.idArtista);
                Artista artista = obtenerArtista(colArtistas, indiceArt); 

                int indiceEsc = buscarIndiceEscenarioPorId(colEscenarios, presentacion.idEscenario);
                Escenario escenario = obtenerEscenario(colEscenarios, indiceEsc);

                if (esAdmin) {
                    mostrarPresentacionAdmin(presentacion, artista.nombre, escenario.nombre);
                } else {
                    mostrarPresentacionUsuario(presentacion, artista.nombre, escenario.nombre);
                }
                validos++;
            }
        }
    }
    return validos;
}

Presentacion pedirDatosNuevaPresentacion(ColeccionArtistas* cArt, ColeccionEscenarios* cEsc) {
    Presentacion nueva;
    Horario inicio;
    Duracion duracion;
        
    printf("Ingrese el id del artista: ");
    nueva.idArtista = scanInt();
    while (buscarIndiceArtistaPorId(cArt, nueva.idArtista) == -1 && nueva.idArtista != 0) {
        printf("\n[Error] El ID del Artista no existe en el sistema.\n");
        printf("Por favor, ingrese un ID valido o 0 para salir: ");
        nueva.idArtista = scanInt();
    }
    if (nueva.idArtista == 0) {
        return nueva;
    }
    printf("\nIngrese el id del escenario: ");
    nueva.idEscenario = scanInt();
    while (buscarIndiceEscenarioPorId(cEsc, nueva.idEscenario) == -1 && nueva.idEscenario != 0) {
        printf("\n[Error] El ID del Escenario no existe en el sistema.\n");
        printf("Por favor, ingrese un ID valido o 0 para salir: ");
        nueva.idEscenario = scanInt();
    }
    if (nueva.idEscenario == 0) {
        return nueva;
    }
    printf("\nINICIO\n");
    printf("Ingrese la hora de inicio (formato 24hs, solo la hora): ");
    nueva.inicio.horas = scanInt();
    printf("Ingrese los minutos de inicio: ");
    nueva.inicio.minutos = scanInt();
    inicio = crearHorario(nueva.inicio.horas, nueva.inicio.minutos);
    while (inicio.esValido == 0) {
        printf("\n[Error] Horario de inicio invalido. Asegurese de ingresar una hora entre 0 y 23, y minutos entre 0 y 59.\n");
        printf("Ingrese la hora de inicio (formato 24hs, solo la hora): ");
        nueva.inicio.horas = scanInt();
        printf("Ingrese los minutos de inicio: ");
        nueva.inicio.minutos = scanInt();
        inicio = crearHorario(nueva.inicio.horas, nueva.inicio.minutos);
    }    
    printf("\nDURACION\n");
    printf("Ingrese la hora de la duracion (formato 24hs, solo la hora): ");
    nueva.duracion.horas = scanInt();
    printf("Ingrese los minutos de la duracion: ");
    nueva.duracion.minutos = scanInt();
    duracion = crearDuracion(nueva.duracion.horas, nueva.duracion.minutos);
    while (duracion.esValido == 0) {
        printf("\n[Error] Duracion invalida. Asegurese de ingresar una hora de duracion mayor o igual a 0, y minutos entre 0 y 59.\n");
        printf("Ingrese la hora de la duracion (formato 24hs, solo la hora): ");
        nueva.duracion.horas = scanInt();
        printf("Ingrese los minutos de la duracion: ");
        nueva.duracion.minutos = scanInt();
        duracion = crearDuracion(nueva.duracion.horas, nueva.duracion.minutos);
    }
    return nueva;
}

Presentacion pedirDatosModificadosPresentacion(Presentacion presentacionExistente, ColeccionArtistas* cArt, ColeccionEscenarios* cEsc) {
    Horario inicio;
    Duracion duracion;
    
    system("clear");
    printf("\n--- MODIFICANDO PRESENTACION ---\n");
    printf("Modificando los datos del ID: %d\n", presentacionExistente.id);
    printf("Nuevo id del artista (anterior: %d): ", presentacionExistente.idArtista);
    presentacionExistente.idArtista = scanInt();
    while (buscarIndiceArtistaPorId(cArt, presentacionExistente.idArtista) == -1 && presentacionExistente.idArtista != 0) {
        printf("\n[Error] El ID del Artista no existe en el sistema.\n");
        printf("Por favor, ingrese un ID valido o 0 para salir: ");
        presentacionExistente.idArtista = scanInt();
    }
    if (presentacionExistente.idArtista == 0) {
        return presentacionExistente;
    }
    printf("Nuevo id del escenario (anterior: %d): ", presentacionExistente.idEscenario);
    presentacionExistente.idEscenario = scanInt();
    while (buscarIndiceEscenarioPorId(cEsc, presentacionExistente.idEscenario) == -1 && presentacionExistente.idEscenario != 0) {
        printf("\n[Error] El ID del Escenario no existe en el sistema.\n");
        printf("Por favor, ingrese un ID valido o 0 para salir: ");
        presentacionExistente.idEscenario = scanInt();
    }
    if (presentacionExistente.idEscenario == 0) {
        return presentacionExistente;
    }
    printf("\nINICIO\n");
    printf("Nueva hora de inicio (anterior: %d): ", presentacionExistente.inicio.horas);
    presentacionExistente.inicio.horas = scanInt();
    printf("Nuevo minuto de inicio (anterior: %d): ", presentacionExistente.inicio.minutos);
    presentacionExistente.inicio.minutos = scanInt();
    inicio = crearHorario(presentacionExistente.inicio.horas, presentacionExistente.inicio.minutos);
    while (inicio.esValido == 0) {
        printf("\n[Error] Horario de inicio invalido. Asegurese de ingresar una hora entre 0 y 23, y minutos entre 0 y 59.\n");
        printf("Ingrese la hora de inicio (formato 24hs, solo la hora): ");
        presentacionExistente.inicio.horas = scanInt();
        printf("Ingrese los minutos de inicio: ");
        presentacionExistente.inicio.minutos = scanInt();
        inicio = crearHorario(presentacionExistente.inicio.horas, presentacionExistente.inicio.minutos);
    } 
    printf("\nDURACION\n");
    printf("Nueva hora de duracion (anterior: %d): ", presentacionExistente.duracion.horas);
    presentacionExistente.duracion.horas = scanInt();
    printf("Nuevo minuto de duracion (anterior: %d): ", presentacionExistente.duracion.minutos);
    presentacionExistente.duracion.minutos = scanInt();
    duracion = crearDuracion(presentacionExistente.duracion.horas, presentacionExistente.duracion.minutos);
    while (duracion.esValido == 0) {
        printf("\n[Error] Duracion invalida. Asegurese de ingresar una hora de duracion mayor o igual a 0, y minutos entre 0 y 59.\n");
        printf("Ingrese la hora de la duracion (formato 24hs, solo la hora): ");
        presentacionExistente.duracion.horas = scanInt();
        printf("Ingrese los minutos de la duracion: ");
        presentacionExistente.duracion.minutos = scanInt();
        duracion = crearDuracion(presentacionExistente.duracion.horas, presentacionExistente.duracion.minutos);
    }

    return presentacionExistente;
}