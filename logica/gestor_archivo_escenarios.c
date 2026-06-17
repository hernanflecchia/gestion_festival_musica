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

void cargarEscenariosDePruebaAlArchivo() {
    Escenario escenariosDePrueba[] = {
        {1, "Principal"},
        {2, "Acustico"},
        {3, "Electronico"},
        {4, "Rock"},
        {5, "Cumbia"}
    };
    
    int cantidadDePrueba = sizeof(escenariosDePrueba) / sizeof(escenariosDePrueba[0]);
    
    for (int i = 0; i < cantidadDePrueba; i++) {
        EscenarioArchivo escenarioArchivo = transformarAEscenarioArchivo(escenariosDePrueba[i]);
        guardarEscenarioEnArchivo(escenarioArchivo);
    }
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
            
            if (leido.id == modificado.id) {
                fseek(arch, -1 * sizeof(EscenarioArchivo), SEEK_CUR); 
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
                leido.valido = 'N'; 
                fseek(arch, -1 * sizeof(EscenarioArchivo), SEEK_CUR); 
                fwrite(&leido, sizeof(EscenarioArchivo), 1, arch);
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int exportarEscenariosATexto(const char* nombreArchivoTxt, ColeccionEscenarios* coleccion, bool esAdmin) {
    FILE* archTxt = fopen(nombreArchivoTxt, "w");
    
    if (archTxt != NULL) {
        
        if (esAdmin) {
            fprintf(archTxt, "id\tnombre\n");
        } else {
            fprintf(archTxt, "nombre\n");
        }
        for (int i = 0; i < coleccion->validos; i++) {
            if (esAdmin) {
                fprintf(archTxt, "%d\t%s\n", coleccion->arreglo[i].id, coleccion->arreglo[i].nombre);
            } else {
                fprintf(archTxt, "%s\n", coleccion->arreglo[i].nombre);
            }
        }
        fclose(archTxt);
        return 1; 
        
    } else {
        return 0;
    }
}

ColeccionEscenarios obtenerEscenariosEliminados() {
    ColeccionEscenarios eliminados;
    eliminados.validos = 0;
    eliminados.capacidad = 0;
    eliminados.arreglo = NULL;

    FILE* arch = fopen(ARCHIVO_ESCENARIOS, "rb");
    if (arch != NULL) {
        EscenarioArchivo escenarioLeido;
        while (fread(&escenarioLeido, sizeof(EscenarioArchivo), 1, arch)) {
            if (escenarioLeido.valido == 'N') {
                Escenario escenarioMemoria = transformarAEscenarioMemoria(escenarioLeido);
                agregarEscenario(&eliminados, escenarioMemoria);
            }
        }
        fclose(arch);
    }
    return eliminados;
}