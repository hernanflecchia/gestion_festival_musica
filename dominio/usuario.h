#ifndef USUARIOS_H
#define USUARIOS_H
#define DIM_NOMBRE 30
#define DIM_CONTRASENIA 15

typedef struct stUsuarios
{
    int id;
    char nombre[DIM_NOMBRE];
    char contrasenia[DIM_CONTRASENIA];
    int rol; //El rol es 1 adminiatrador y 0 Usuario corriente. Esto para hacer verificaciones mas rapidas.
} Usuarios;

// Prototipo de la función para mostrar el usuario
void mostrarUsuario(Usuarios usuario);

#endif