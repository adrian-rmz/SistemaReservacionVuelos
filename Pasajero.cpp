/*  Autor: 
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#include "Pasajero.h"

// Implementación del constructor por defecto
Pasajero::Pasajero() {
    nombre = "Desconocido";
    telefono = "Desconocido";
    kilometros = 0;
}


// Implementación del constructor por parámetros
Pasajero:: Pasajero(string _nombre, string _telefono, double _kilometros) {
    nombre = _nombre;
    telefono = _telefono;
    setKilometros(_kilometros);
}


// Implementación del método destructor
Pasajero::~Pasajero() {}


// Implementación de Getters
string Pasajero::getNombre() const {
    return nombre;
}

string Pasajero::getTelefono() const {
    return telefono;
}

double Pasajero::getKilometros() const {
    return kilometros;
}


// Implementación de Setters
void Pasajero::setNombre(string _nombre) {
    nombre = _nombre;
}

void Pasajero::setTelefono(string _telefono) {
    telefono = _telefono;
}

void Pasajero::setKilometros(double _kilometros) {
    if (_kilometros >= 0) {
        kilometros = _kilometros;
    } else {
        kilometros = 0;
    }
}


// Implementación de Métodos Adicionales
void Pasajero::imprimirPasajero() {
    cout << "********* PASAJERO *********" << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Telefono: " << getTelefono() << endl;
    cout << "Kilometros: " << getKilometros() << endl;
}