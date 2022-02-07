/*  Autor: 
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#include "Usuario.h"

// Implementación del constructor por defecto
Usuario::Usuario() {
    usuario = "Desconocido";
    contrasenna = "Desconocido";
}


// Implementación del constructor por parámetros
Usuario:: Usuario(string _usuario, string _contrasenna) {
    usuario = _usuario;
    contrasenna = _contrasenna;
}


// Implementación del método destructor
Usuario::~Usuario() {}


// Implementación de Getters
string Usuario::getUsuario() const {
    return usuario;
}

string Usuario::getContrasenna() const {
    return contrasenna;
}


// Implementación de Setters
void Usuario::setUsuario(string _usuario) {
    usuario = _usuario;
}

void Usuario::setContrasenna(string _contrasenna) {
    contrasenna = _contrasenna;
}