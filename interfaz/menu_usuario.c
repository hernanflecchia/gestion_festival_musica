#include <stdio.h>
#include "scanner.h"
#include "menu_artistas.h"
#include "menu_escenarios.h"
#include "menu_presentaciones.h"

void menuUsuario(Usuarios usuario, ColeccionArtistas* colArtistas, ColeccionEscenarios* colEscenarios, ColeccionPresentaciones* colPresentaciones) {
    int opcionMenu;
    do {
        opcionMenu = mostrarMenuDeUsuario(usuario);

        switch(opcionMenu) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        default:
            if(opcionMenu != 4) {
            printf("\nOpcion invalida. Intente de nuevo.\n");
            }
            break;
        }
    }
    while(opcionMenu != 4);
}

int mostrarMenuUsuario(Usuarios usuario) {
    printf(" Usuario: %s\n", usuario.nombre);
    printf("|====================================|\n");
    printf("|            MENU USUARIO            |\n");
    printf("|====================================|\n");
    printf("|                                    |\n");
    printf("|   1. Ver artistas                  |\n");
    printf("|   2. Ver escenarios                |\n");
    printf("|   3. Ver presentaciones            |\n");
    printf("|   4. Salir                         |\n");
    printf("|                                    |\n");
    printf("|------------------------------------|\n");
    printf("|Seleccione una opcion: ");
    return scanInt();
}
