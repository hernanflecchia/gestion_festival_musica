# 🎸 Sistema de Gestión de un Festival de Música

Trabajo Práctico Final para la materia **Programación I** de la **UTN - Facultad Regional Mar del Plata**. 

Esta aplicación de consola, desarrollada íntegramente en lenguaje C, permite administrar las entidades principales de un festival de música aplicando modularización y control de versiones.

## 🧑‍💻 Integrantes

* 🎓 **Bustos, Matias**
* 🎓 **Fariña, Adriel**
* 🎓 **Flecchia, Hernán**

## 📋 Características Principales

El sistema cumple con las siguientes funcionalidades:
* **Modo Usuario y Modo Admin:** El administrador es el encargado de dar de alta, bajas y modificaciones de todas las entidades, asi tambien tiene acceso a una auditoria en donde poder ver los registros eliminados. Con respecto a la eliminación de una entidad, esta se marca con un flag de registro que indica que fue eliminada, de lo contrario es una entidad valida. El modo usuario puede ver los datos de las entidades y obtener todos los listados disponibles.
* **ABM Completos:** Alta, baja y modificación de Artistas, Escenarios y Presentaciones.
* **Listados Dinámicos:** Visualización en orden alfabético de todos los registros en modo usuario y en orden de ID en modo admin, con filtros específicos (Presentaciones por Artista y Presentaciones por Escenario).
* **Reglas de Negocio:** Algoritmos de validación para evitar el solapamiento de horarios en un mismo escenario y para impedir que un mismo artista se presente en distintos escenarios simultáneamente.
* **Persistencia y Exportación:** Guardado de datos en archivos binarios (`.bin`) y capacidad de exportar listados a archivos de texto (`.txt`).

## 🏗️ Arquitectura del Proyecto

El código fuente está dividido en tres directorios principales, implementando una **arquitectura en capas**:

* 📂 **Dominio:** Contiene los modelos base (`artista.c/h`, `escenario.c/h`, `presentacion.c/h`, `usuarios.c/h`) y la implementación de **Tipos de Datos Seguros** (`tipos_seguros.c/h` con las estructuras `Horario` y `Duracion`) para centralizar las validaciones de datos.
* 📂 **Logica (o Servicio):** Aquí residen las colecciones dinámicas (TDA) que reemplazan a las pilas básicas, el gestor de persistencia mediante archivos, y el control de las reglas del festival.
* 📂 **Interfaz:** Contiene los menús y vistas interactivas. Es la única capa autorizada para usar funciones de entrada interactuando directamente con el usuario.

## 🚀 Conceptos Técnicos Implementados
* Gestión de Archivos Binarios de Acceso Aleatorio (`fread`, `fwrite`, `fseek`).
* Memoria Dinámica (`malloc`, `realloc`, `free`) y Tipos de Datos Abstractos (Colecciones).
* Algoritmos Recursivos aplicados a búsquedas.

## 👥 Metodología de Trabajo
El equipo de desarrollo utilizó **Git y GitHub** para el control de versiones.
