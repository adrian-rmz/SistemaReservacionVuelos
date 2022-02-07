/*  Autor: 
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario {
    public:
        // Constructor por defecto
        Usuario();

        // Constructor por parámetros
        Usuario(string, string);

        // Destructor
        ~Usuario();

        // Métodos Getters o de Acceso
        string getUsuario() const;
        string getContrasenna() const;

        // Métodos Setters o Modificadores
        void setUsuario(string);
        void setContrasenna(string);

    private:
        string usuario;
        string contrasenna;
};

#endif // USUARIO_H