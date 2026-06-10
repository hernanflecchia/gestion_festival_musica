#include <stdio.h>
#include <string.h>
#include "gestor_archivos.h"

void inicializarArchivoUsuarios(void) {
    FILE* archUsuarios = fopen("usuarios.bin", "rb");
    
    if (archUsuarios == NULL) {
        // Si el archivo no existe lo creamos con wb
        archUsuarios = fopen("usuarios.bin", "wb");
        // Creamos el usuario admin
        if (archUsuarios != NULL) {
            Usuarios primerAdmin;
            strcpy(primerAdmin.nombre, "admin");
            strcpy(primerAdmin.contrasenia, "admin");
            primerAdmin.rol = 1;
            
            fwrite(&primerAdmin, sizeof(Usuarios), 1, archUsuarios); 
            fclose(archUsuarios);
            
            printf("[Sistema] Primer inicio detectado: Usuario 'admin' creado con exito.\n\n");
        }
    } else {
        // Si el archivo ya existe lo cerramos nada mas
        fclose(archUsuarios); 
    }
}