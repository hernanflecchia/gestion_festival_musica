#include <stdio.h>
#include "scanner.h"
#include "menu_usuario.h"

int mostrarMenuInicio(void)
{
    printf("======================\n");
    printf("        INICIO \n");
    printf("======================\n\n");
    printf("    1. Iniciar sesion \n");
    printf("    2. Crear usuario \n");
    printf("    3. Salir \n");
    
    printf("Seleccione una opción: ");
return scanInt();
}
