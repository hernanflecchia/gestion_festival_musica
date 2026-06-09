# 🎸 Sistema de Gestión de un Festival de Música

Trabajo Práctico Final para la materia **Programación I** de la **UTN - Facultad Regional Mar del Plata**. 

Esta aplicación de consola, desarrollada íntegramente en lenguaje C, permite administrar las entidades principales de un festival de música aplicando buenas prácticas de programación, modularización y control de versiones.

## 🧑‍💻 Integrantes

* 🎓 **Bustos, Matias**
* 🎓 **Fariña, Adriel**
* 🎓 **Flecchia, Hernán**

## 📋 Características Principales

El sistema cumple con todas las funcionalidades y restricciones de negocio exigidas por la cátedra:
* **ABM Completos:** Alta, baja y modificación de Artistas, Escenarios y Presentaciones.
* **Listados Dinámicos:** Visualización en orden alfabético de todos los registros, con filtros específicos (Presentaciones por Artista y Presentaciones por Escenario).
* **Reglas de Negocio Estrictas:** Algoritmos de validación para evitar el solapamiento de horarios en un mismo escenario y para impedir que un mismo artista se presente en distintos escenarios simultáneamente.
* **Persistencia y Exportación:** Guardado de datos en archivos binarios (`.bin`) y capacidad de exportar listados a archivos de texto (`.txt`).

## 🏗️ Arquitectura del Proyecto

El código fuente está dividido en tres directorios principales, implementando una **arquitectura en capas** estricta:

* 📂 **Dominio:** Contiene los modelos base (`artista.c/h`, `escenario.c/h`, `presentacion.c/h`) y la implementación de **Tipos de Datos Seguros** (`tipos_seguros.c/h` con las estructuras `Horario` y `Duracion`) para centralizar las validaciones de datos. Fiel a su capa, solo define cómo se representan los datos visualmente sin solicitar información por teclado.
* 📂 **Logica (o Servicio):** Aquí residen las colecciones dinámicas (TDA) que reemplazan a las pilas básicas, el gestor de persistencia mediante archivos, y el control de las reglas del festival. Solo interactúa con su propia capa y la de Dominio.
* 📂 **Interfaz:** Contiene los menús y vistas interactivas. Es la única capa autorizada para usar funciones de entrada interactuando directamente con el usuario.

## 🚀 Conceptos Técnicos Implementados
* Gestión de Archivos Binarios de Acceso Aleatorio (`fread`, `fwrite`, `fseek`).
* Memoria Dinámica (`malloc`, `realloc`, `free`) y Tipos de Datos Abstractos (Colecciones).
* Algoritmos Recursivos aplicados a búsquedas y/o recorridos.
* Estructuras anidadas y punteros múltiples.

## 👥 Metodología de Trabajo
El equipo de desarrollo utilizó **Git y GitHub** para el control de versiones, acompañando el avance con un tablero **Kanban** (Backlog, Ready, In progress, Done) a modo de diario de desarrollo continuo. 
La integración del código se realiza dividiendo el trabajo mediante Issues rastreables, uso de ramas secundarias (dev) y Pull Requests, garantizando que los integrantes no sobreescriban su trabajo mutuo.