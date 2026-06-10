#ifndef MENUS_H
#define MENUS_H

#include "../dominio/usuario.h"
#include "../dominio/artista.h"
#include "../dominio/escenario.h"
#include "../dominio/presentacion.h"
#include "../logica/colecciones.h"

// ==========================================
// MENÚS DE NAVEGACIÓN
// ==========================================
int mostrarMenuInicio(void);
int mostrarMenuPrincipal(void);
int mostrarMenuArtistas(void);
int mostrarMenuEscenarios(void);
int mostrarMenuPresentaciones(void);
int mostrarMenuListados(void);
void menuAdmin(Usuarios usuario, ColeccionArtistas colArtistas, ColeccionEscenarios colEscenarios, ColeccionPresentaciones colPresentaciones);
void menuUsuario(Usuarios usuario, ColeccionArtistas colArtistas, ColeccionEscenarios colEscenarios, ColeccionPresentaciones colPresentaciones);

// ==========================================
// INGRESOS DE DATOS (ALTAS)
// ==========================================
Usuarios pedirCredencialesUsuario(const char* titulo);
Artista pedirDatosNuevoArtista(void);
Escenario pedirDatosNuevoEscenario(void);
Presentacion pedirDatosNuevaPresentacion(void);

// ==========================================
// PEDIDOS PARA BAJAS Y MODIFICACIONES
// ==========================================
// Función genérica se pasa la palabra "Artista" o "Escenario" 
int pedirIdGenerico(const char* nombreEntidad); 

// Si el usuario quiere modificar algo, primero pedís el ID con la función de arriba,
// la Lógica busca la entidad en el arreglo, y si existe se la pasás a estas 
// funciones para que el usuario sobreescriba los campos que desee:
Artista pedirDatosModificadosArtista(Artista artistaExistente);
Escenario pedirDatosModificadosEscenario(Escenario escenarioExistente);

#endif