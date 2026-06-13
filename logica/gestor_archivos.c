#include <stdio.h>
#include <string.h>
#include "gestor_archivos.h"

// ==========================================
// ARCHIVO USUARIOS
// ==========================================

void inicializarArchivoUsuarios(void) {
    FILE* archUsuarios = fopen(ARCHIVO_USUARIOS, "rb");
    
    if (archUsuarios == NULL) {
        // Si el archivo no existe lo creamos con wb
        archUsuarios = fopen(ARCHIVO_USUARIOS, "wb");
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

Usuarios validarLogin(Usuarios usuarioIngresado) {
    Usuarios usuarioLeido;
    // Creamos un usuario "centinela" para indicar que falló el login
    Usuarios usuarioError;
    usuarioError.rol = -1; 

    FILE* arch = fopen(ARCHIVO_USUARIOS, "rb");
    
    if (arch != NULL) {
        while (fread(&usuarioLeido, sizeof(Usuarios), 1, arch) > 0) { 
            if (strcmp(usuarioLeido.nombre, usuarioIngresado.nombre) == 0 && 
                strcmp(usuarioLeido.contrasenia, usuarioIngresado.contrasenia) == 0) {

                fclose(arch);
                return usuarioLeido;
            }
        }
        fclose(arch);
    }
    
    return usuarioError;
}

int guardarUsuario(Usuarios nuevoUsuario) {
    nuevoUsuario.rol = 0;
    FILE* arch = fopen(ARCHIVO_USUARIOS, "ab");
    
    if (arch != NULL) {
        fwrite(&nuevoUsuario, sizeof(Usuarios), 1, arch);
        fclose(arch); 
        
        return 1;
    }
    
    return 0;
}

// ==========================================
// ARCHIVO ARTISTAS
// ==========================================

ArtistaArchivo transformarAArtistaArchivo(Artista artistaMemoria) {
    ArtistaArchivo artistaDisco;

    artistaDisco.id = artistaMemoria.id;
    strcpy(artistaDisco.nombre, artistaMemoria.nombre);
    strcpy(artistaDisco.genero, artistaMemoria.genero);
    artistaDisco.valido = 'S';

    return artistaDisco;
}

int guardarArtistaEnArchivo(ArtistaArchivo nueva) {
    FILE* arch = fopen(ARCHIVO_ARTISTAS, "ab");

    if (arch!= NULL) {
        fwrite(&nueva, sizeof(ArtistaArchivo), 1, arch);
        fclose(arch);

        return 1;
    }

    return 0;
}

Artista transformarAArtistaMemoria(ArtistaArchivo artistaDisco) {
    Artista artistaMemoria;

    artistaMemoria.id = artistaDisco.id;
    strcpy(artistaMemoria.nombre, artistaDisco.nombre);
    strcpy(artistaMemoria.genero, artistaDisco.genero);

    return artistaMemoria;
}

void cargarArtistasDesdeArchivo(ColeccionArtistas* coleccion) {
    FILE* arch = fopen(ARCHIVO_ARTISTAS, "rb");

    if (arch != NULL) {
        ArtistaArchivo artistaLeido;
        int agregado;

        while (fread(&artistaLeido, sizeof(ArtistaArchivo), 1, arch)) {
            if (artistaLeido.valido == 'S') {
                Artista artistaMemoria = transformarAArtistaMemoria(artistaLeido);
                agregado = agregarArtista(coleccion, artistaMemoria);
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

int modificarArtistaEnArchivo(ArtistaArchivo modificado) {
    int exito = 0;
    FILE* arch = fopen("artistas.bin", "r+b"); 
    
    if (arch != NULL) {
        ArtistaArchivo leido;
        
        while (fread(&leido, sizeof(ArtistaArchivo), 1, arch)) { 
            
            // Si encontramos el artista con el mismo ID que queremos modificar
            if (leido.id == modificado.id) {
                
                // Movemos el indicador de posición exactamente un struct para atrás
                fseek(arch, -1 * sizeof(ArtistaArchivo), SEEK_CUR); 
                
                // Escribimos el dato nuevo pisando el viejo
                fwrite(&modificado, sizeof(ArtistaArchivo), 1, arch);
                
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int bajaLogicaArtistaEnArchivo(int idBorrar) {
    int exito = 0;
    FILE* arch = fopen("artistas.bin", "r+b"); 
    
    if (arch != NULL) {
        ArtistaArchivo leido;
        while (fread(&leido, sizeof(ArtistaArchivo), 1, arch)) { 
            if (leido.id == idBorrar && leido.valido == 'S') {
                // Cambiamos su estado a inactivo ('N')
                leido.valido = 'N'; 
                // Movemos el cursor exactamente un struct para atrás desde la posición actual
                fseek(arch, -1 * sizeof(ArtistaArchivo), SEEK_CUR); 
                // Sobrescribimos el registro en el disco
                fwrite(&leido, sizeof(ArtistaArchivo), 1, arch);
                exito = 1;
                break;
            }
        }
        fclose(arch);
    }
    return exito;
}

int exportarArtistasATexto(const char* nombreArchivoTxt, ColeccionArtistas* coleccion) {
    FILE* archTxt = fopen(nombreArchivoTxt, "w");
    
    if (archTxt != NULL) {
        
        fprintf(archTxt, "nombre\tgenero\n");
        for (int i = 0; i < coleccion->validos; i++) {
            fprintf(archTxt, "%s\t%s\n", coleccion->arreglo[i].nombre,  coleccion->arreglo[i].genero);
        }
        fclose(archTxt);
        return 1; 
        
    } else {
        return 0;
    }
}

// ==========================================
// ARCHIVO ESCENARIOS
// ==========================================

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

// ==========================================
// ARCHIVO PRESENTACIONES
// ==========================================


int bajaLogicaPresentacionesEnArchivoPorArtista(int idArtistaBuscado) {
    int cantidadBorradas = 0;
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "r+b"); 
    
    if (arch != NULL) {
        PresentacionArchivo leida;
        while (fread(&leida, sizeof(PresentacionArchivo), 1, arch) > 0) { 
            // Buscamos todas las presentaciones activas de ese artista
            if (leida.idArtista == idArtistaBuscado && leida.valido == 'S') {
                leida.valido = 'N'; // Las marcamos como borradas lógicamente
                fseek(arch, -1 * sizeof(PresentacionArchivo), SEEK_CUR); 
                fwrite(&leida, sizeof(PresentacionArchivo), 1, arch);
                // Refrescamos el buffer haciendo un seek vacio
                fseek(arch, 0, SEEK_CUR);
                cantidadBorradas++;
            }
        }
        fclose(arch);
    }
    return cantidadBorradas;
}

int bajaLogicaPresentacionesEnArchivoPorEscenario(int idEscenarioBuscado) {
    int cantidadBorradas = 0;
    FILE* arch = fopen(ARCHIVO_PRESENTACIONES, "r+b"); 
    
    if (arch != NULL) {
        PresentacionArchivo leida;
        while (fread(&leida, sizeof(PresentacionArchivo), 1, arch) > 0) { 
            // Buscamos todas las presentaciones activas de ese escenario
            if (leida.idEscenario == idEscenarioBuscado && leida.valido == 'S') {
                leida.valido = 'N'; // Las marcamos como borradas lógicamente
                fseek(arch, -1 * sizeof(PresentacionArchivo), SEEK_CUR); 
                fwrite(&leida, sizeof(PresentacionArchivo), 1, arch);
                // Refrescamos el buffer haciendo un seek vacio
                fseek(arch, 0, SEEK_CUR);
                cantidadBorradas++;
            }
        }
        fclose(arch);
    }
    return cantidadBorradas;
}