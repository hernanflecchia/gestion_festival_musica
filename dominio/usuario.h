#ifndef USUARIOS_H
#define USUARIOS_H
#define DIMcontrasenia 15
#define DIMnombre 30

typedef struct stUsuarios
{
    int id;
    char nombre[DIMnombre];
    char contrasenia[DIMcontrasenia];
    int rol; //El rol es 1 adminiatrador y 0 Usuario corriente. Esto para hacer verificaciones mas rapidas.
} Usuarios;

// Prototipo de la función para mostrar el usuario
void mostrarUsuario(Usuarios usuario);

#endif