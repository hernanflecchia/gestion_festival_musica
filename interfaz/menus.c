#include <stdio.h>
#include "scanner.h"
#include "../dominio/usuario.h"

int mostrarMenuInicio(void) {
    printf("        INICIO  \n\n");
    printf("    1. Iniciar sesion \n");
    printf("    2. Crear usuario \n");
    printf("    3. Salir \n");

    return scanInt();
}

Usuarios pedirDatosLogin(void) {
    Usuarios usuario;

    printf("Ingrese nombre de usuario: ");
    scanString(usuario.nombre, DIMnombre);

    printf("Ingrese contraseña: ");
    scanString(usuario.contrasenia, DIMcontrasenia);

    return usuario;
}

Usuarios pedirDatosNuevoUsuario(void) {
    Usuarios usuario;

    printf("Ingrese nombre de usuario: ");
    scanString(usuario.nombre, DIMnombre);

    printf("Ingrese contraseña: ");
    scanString(usuario.contrasenia, DIMcontrasenia);

    return usuario;
}
