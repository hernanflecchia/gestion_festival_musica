#include <stdio.h>
#include "scanner.h"
#include "../dominio/usuario.h"
#include "../dominio/artista.h"
#include "../logica/colecciones.h"

int mostrarMenuInicio(void) {
    printf("        INICIO  \n\n");
    printf("    1. Iniciar sesion \n");
    printf("    2. Crear usuario \n");
    printf("    3. Salir \n");

    return scanInt();
}

Usuarios pedirCredencialesUsuario(const char* titulo) {
    Usuarios usuario;

    printf("%s\n", titulo); 
    printf("Ingrese nombre de usuario: ");
    scanString(usuario.nombre, DIM_USUARIO_NOMBRE);
    printf("Ingrese contraseña: ");
    scanString(usuario.contrasenia, DIM_USUARIO_CONTRASENIA);

    return usuario;
}

Artista pedirDatosNuevoArtista(void) {
    Artista nuevo;
    printf("\n--- ALTA DE ARTISTA ---\n");
    printf("Ingrese el nombre del artista: ");
    scanString(nuevo.nombre, 50);
    printf("Ingrese el genero musical: ");
    scanString(nuevo.genero, 30);
    return nuevo;
}

int mostrarMenuArtistas(void) {
    printf("\n--- GESTION DE ARTISTAS ---\n");
    printf("1. Dar de alta nuevo Artista\n");
    printf("2. Modificar Artista existente\n");
    printf("3. Dar de baja (Eliminar) Artista\n");
    printf("0. Volver al menu principal\n");
    printf("Elija una opcion: ");
    return scanInt();
}

void menuAdmin(Usuarios usuario, ColeccionArtistas* cArt, ColeccionEscenarios* cEsc, ColeccionPresentaciones* cPres) {
    int opcionPrincipal;
    int opcionSubMenu;

    do {
        printf("\n=== PANEL DE ADMINISTRADOR ===\n");
        printf("Bienvenido/a, %s\n", usuario.nombre);
        printf("1. Gestionar Artistas\n");
        printf("2. Gestionar Escenarios\n");
        printf("3. Gestionar Presentaciones\n");
        printf("4. Ver Listados y Reportes\n");
        printf("0. Cerrar Sesion\n");
        printf("Elija una opcion: ");
        opcionPrincipal = scanInt();

        switch(opcionPrincipal) {
            case 1:
                do {
                    opcionSubMenu = mostrarMenuArtistas();
                    
                    switch(opcionSubMenu) {
                        case 1:
                        {
                            Artista nuevoArtista = pedirDatosNuevoArtista();
                            agregarArtista(cArt, nuevoArtista);
                            printf("\n[Exito] Artista '%s' agregado a la memoria.\n", nuevoArtista.nombre);
                            break;
                        }
                        case 2:
                            // Aca usarías pedirIdGenerico("Artista"), luego lo buscás en el arreglo, 
                            // y si existe, se lo pasas a pedirDatosModificadosArtista...
                            printf("\n(En construccion...)\n");
                            break;
                        case 3:
                            // Pedir ID, buscarlo y cambiarle el valido a 'N' en el archivo
                            printf("\n(En construccion...)\n");
                            break;
                        case 0:
                            // Simplemente vuelve al menú principal
                            break;
                        default:
                            printf("\nOpcion invalida.\n");
                    }
                } while(opcionSubMenu != 0);
                break;

            case 2:
                // Aca armarías el do-while para ESCENARIOS
                printf("\n(Menu Escenarios en construccion...)\n");
                break;
                
            case 3:
                // Aca armarías el do-while para PRESENTACIONES
                printf("\n(Menu Presentaciones en construccion...)\n");
                break;

            case 0:
                printf("\nCerrando sesion de %s...\n", usuario.nombre);
                break;

            default:
                printf("\nOpcion invalida.\n");
        }
    } while(opcionPrincipal != 0);
}

int pedirIdGenerico(const char* nombreEntidad) {
    printf("\nIngrese el ID del %s: ", nombreEntidad);
    return scanInt();
}