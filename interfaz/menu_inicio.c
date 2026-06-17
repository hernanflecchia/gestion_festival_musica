#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "../dominio/usuario.h"

int mostrarMenuInicio(void) {
    printf("|====================================|\n");
    printf("|               INICIO               |\n");
    printf("|====================================|\n");
    printf("|                                    |\n");
    printf("|   1. Iniciar sesion                |\n");
    printf("|   2. Crear usuario                 |\n");
    printf("|   3. Salir                         |\n");
    printf("|                                    |\n");
    printf("|------------------------------------|\n");
    printf("|Seleccione una opcion: ");
return scanInt();
}

Usuarios pedirCredencialesUsuario(const char* titulo) {
    Usuarios usuario;

    system("clear");
    printf("%s\n", titulo); 
    printf("Ingrese nombre de usuario: ");
    scanString(usuario.nombre, DIM_USUARIO_NOMBRE);
    printf("Ingrese contraseña: ");
    scanString(usuario.contrasenia, DIM_USUARIO_CONTRASENIA);

    return usuario;
}


