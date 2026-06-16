#include <stdio.h>
#include "scanner.h"
#include "menu_admin.h"
#include "menu_artistas.h"
#include "menu_escenarios.h"
#include "menu_presentaciones.h"

void menuAdmin(Usuarios usuario) {
    int opcionMenu;
    do {
        opcionMenu = mostrarMenuAdmin(usuario);

        switch(opcionMenu) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        default:
            if(opcionMenu != 4){
                printf("\nOpcion invalida. Intente de nuevo.\n");
            }
            break;
        }
    }
    while(opcionMenu != 4);
}

int mostrarMenuAdmin(Usuarios usuario) {
    printf(" Usuario: %s\n", usuario.nombre);
    printf("|====================================|\n");
    printf("|         MENU ADMINISTRADOR         |\n");
    printf("|====================================|\n");
    printf("|                                    |\n");
    printf("|   1. Menu artistas                 |\n");
    printf("|   2. Menu escenarios               |\n");
    printf("|   3. Menu presentaciones           |\n");
    printf("|   4. Salir                         |\n");
    printf("|                                    |\n");
    printf("|------------------------------------|\n");
    printf("|Seleccione una opcion: ");
    return scanInt();
}
