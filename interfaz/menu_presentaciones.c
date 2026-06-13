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
        
        // Verificamos el valor centinela para saltar las presentaciones borradas
        if (presentacion.id != -1) { 
            
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
    
    printf("\nPresione Enter para continuar...");
    getchar();
}

Presentacion pedirDatosNuevoPresentacion(void) {
    Presentacion nuevo;

    system("clear");
    printf("\n--- ALTA DE PRESENTACION ---\n");
    printf("Ingrese el nombre del presentacion: ");

    return nuevo;
}

Presentacion pedirDatosModificadosPresentacion(Presentacion presentacionExistente) {
    system("clear");
    printf("\n--- MODIFICANDO PRESENTACION ---\n");
    printf("Modificando los datos del ID: %d\n", presentacionExistente.id);

    return presentacionExistente;
}