#include <stdio.h>
#include <string.h>
#include "gestor_archivos.h"

void inicializarArchivoUsuarios(void) {
    FILE* archUsuarios = fopen("usuarios.bin", "rb"); // Intentamos leer [6]
    
    if (archUsuarios == NULL) { // Si el archivo no existe [7]
        archUsuarios = fopen("usuarios.bin", "wb"); // Lo creamos [6]
        
        if (archUsuarios != NULL) {
            Usuarios primerAdmin;
            strcpy(primerAdmin.nombre, "admin");
            strcpy(primerAdmin.contrasenia, "admin");
            primerAdmin.rol = 1; // 1 = Admin
            
            // Escribimos el bloque en el archivo [8]
            fwrite(&primerAdmin, sizeof(Usuarios), 1, archUsuarios); 
            fclose(archUsuarios); [5]
            
            // Un pequeño aviso por consola no hace daño en la inicialización
            printf("[Sistema] Primer inicio detectado: Usuario 'admin' creado con exito.\n\n");
        }
    } else {
        // El archivo ya existía, lo cerramos [5]
        fclose(archUsuarios); 
    }
}