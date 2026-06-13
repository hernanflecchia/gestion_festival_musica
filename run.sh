gcc main.c logica/coleccion_artistas.c logica/coleccion_escenarios.c logica/coleccion_presentaciones.c \
    logica/gestor_archivo_artistas.c logica/gestor_archivo_escenarios.c logica/gestor_archivo_presentaciones.c logica/gestor_archivo_usuarios.c \
    interfaz/menu_inicio.c interfaz/menu_admin.c interfaz/menu_usuario.c interfaz/menu_artistas.c interfaz/menu_escenarios.c interfaz/menu_presentaciones.c \
    interfaz/scanner.c \
    dominio/artista.c dominio/escenario.c dominio/presentacion.c dominio/tipos_seguros.c -o main && ./main
