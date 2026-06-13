#include <stdio.h>
#include <string.h>
#include "gestor_archivo_escenarios.h"

EscenarioArchivo transformarAEscenarioArchivo(Escenario escenarioMemoria) {
    EscenarioArchivo escenarioDisco;

    escenarioDisco.id = escenarioMemoria.id;
    strcpy(escenarioDisco.nombre, escenarioMemoria.nombre);
    escenarioDisco.valido = 'S';

    return escenarioDisco;
}

int guardarEscenarioEnArchivo(EscenarioArchivo nueva) {
    FILE* arch = fopen(ARCHIVO_ESCENARIOS, "ab");

    if (arch!= NULL) {
        fwrite(&nueva, sizeof(EscenarioArchivo), 1, arch);
        fclose(arch);

        return 1;
    }

    return 0;
}

Escenario transformarAEscenarioMemoria(EscenarioArchivo escenarioDisco) {
    Escenario escenarioMemoria;

    escenarioMemoria.id = escenarioDisco.id;
    strcpy(escenarioMemoria.nombre, escenarioDisco.nombre);

    return escenarioMemoria;
}

void cargarEscenariosDesdeArchivo(ColeccionEscenarios* coleccion) {
    FILE* arch = fopen(ARCHIVO_ESCENARIOS, "rb");

    if (arch != NULL) {
        EscenarioArchivo escenarioLeido;
        int agregado;

        while (fread(&escenarioLeido, sizeof(EscenarioArchivo), 1, arch)) {
            if (escenarioLeido.valido == 'S') {
                Escenario escenarioMemoria = transformarAEscenarioMemoria(escenarioLeido);
                agregado = agregarEscenario(coleccion, escenarioMemoria);
                if (agregado == 0) {
                    printf("[Error] No hay memoria disponible para ampliar el arreglo.\n");
                    fclose(arch);
                    return;
                }
            }
        }
        fclose(arch);
    }
}

int modificarEscenarioEnArchivo(EscenarioArchivo modificado) {
    int exito = 0;
    FILE* arch = fopen("escenarios.bin", "r+b"); 
    
    if (arch != NULL) {
        EscenarioArchivo leido;
        
        while (fread(&leido, sizeof(EscenarioArchivo), 1, arch)) { 
            
            // Si encontramos el escenario con el mismo ID que queremos modificar
            if (leido.id == modificado.id) {
                
                // Movemos el indicador de posición exactamente un struct para atrás
                fseek(arch, -1 * sizeof(EscenarioArchivo), SEEK_CUR); 
                
                // Escribimos el dato nuevo pisando el viejo
                fwrite(&modificado, sizeof(EscenarioArchivo), 1, arch);
                
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int bajaLogicaEscenarioEnArchivo(int idBorrar) {
    int exito = 0;
    FILE* arch = fopen("escenarios.bin", "r+b"); 
    
    if (arch != NULL) {
        EscenarioArchivo leido;
        while (fread(&leido, sizeof(EscenarioArchivo), 1, arch)) { 
            if (leido.id == idBorrar && leido.valido == 'S') {
                // Cambiamos su estado a inactivo ('N')
                leido.valido = 'N'; 
                // Movemos el cursor exactamente un struct para atrás desde la posición actual
                fseek(arch, -1 * sizeof(EscenarioArchivo), SEEK_CUR); 
                // Sobrescribimos el registro en el disco
                fwrite(&leido, sizeof(EscenarioArchivo), 1, arch);
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int exportarEscenariosATexto(const char* nombreArchivoTxt, ColeccionEscenarios* coleccion) {
    FILE* archTxt = fopen(nombreArchivoTxt, "w");
    
    if (archTxt != NULL) {
        
        fprintf(archTxt, "nombre\n");
        for (int i = 0; i < coleccion->validos; i++) {
            fprintf(archTxt, "%s\n", coleccion->arreglo[i].nombre);
        }
        fclose(archTxt);
        return 1; 
        
    } else {
        return 0;
    }
}