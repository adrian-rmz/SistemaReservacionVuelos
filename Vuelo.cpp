/*  Autor: 
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#include "Vuelo.h"

// Implementación del constructor por defecto
Vuelo::Vuelo() {
    numeroVuelo = 1;
    destino = "Desconocido";
    precioVuelo = 1000;
    distanciaVuelo = 100;
    aerolinea = "Desconocida";
    hora = "00:00";
}


// Implementación del constructor por parámetros
Vuelo::Vuelo(const Fecha& _fecha, int _numeroVuelo, string _destino, double _precioVuelo, double _distanciaVuelo, string _aerolinea, string _hora, vector<Pasajero> _pasajeros) {
    fecha = _fecha;
    setNumeroVuelo(_numeroVuelo);
    destino = _destino;
    setPrecioVuelo(_precioVuelo);
    setDistanciaVuelo(_distanciaVuelo);
    aerolinea = _aerolinea;
    hora = _hora;
    pasajeros = _pasajeros;
}


// Implementación del método destructor
Vuelo::~Vuelo() {}


// Implementación de Getters
Fecha Vuelo::getFecha() const {
    return fecha;
}

int Vuelo::getNumeroVuelo() const {
    return numeroVuelo;
}

string Vuelo::getDestino() const {
    return destino;
}

double Vuelo::getPrecioVuelo() const {
    return precioVuelo;
}

double Vuelo::getDistanciaVuelo() const {
    return distanciaVuelo;
}

string Vuelo::getAerolinea() const {
    return aerolinea;
}

string Vuelo::getHora() const {
    return hora;
}


// Implementación de Setters
void Vuelo::setFecha(Fecha& _fecha) {
    fecha = _fecha;
}

void Vuelo::setNumeroVuelo(int _numeroVuelo) {
    if (_numeroVuelo > 0) {
        numeroVuelo = _numeroVuelo;
    } else {
        numeroVuelo = 1;
    }
}

void Vuelo::setDestino(string _destino) {
    destino = _destino;
}

void Vuelo::setPrecioVuelo(double _precioVuelo) {
    if (_precioVuelo >= 0) {
        precioVuelo = _precioVuelo;
    } else {
        precioVuelo = 1000;
    }
}

void Vuelo::setDistanciaVuelo(double _distanciaVuelo) {
    if (_distanciaVuelo >= 0) {
        distanciaVuelo = _distanciaVuelo;
    } else {
        distanciaVuelo = 100;
    }
}

void Vuelo::setAerolinea(string _aerolinea) {
    aerolinea = _aerolinea;
}

void Vuelo::setHora(string _hora) {
    hora = _hora;
}


// Implementación de métodos adicionales
void Vuelo::agregarPasajero(Pasajero& _pasajero) {
    pasajeros.push_back(_pasajero);
}

void Vuelo::eliminarPasajero(Pasajero& _pasajero) {
    for (int i = 0; i < pasajeros.size(); i++) {
        if (pasajeros[i].getNombre() == _pasajero.getNombre()) {
            pasajeros.erase(pasajeros.begin() + i);
        }
    }
}

void Vuelo::modificarPasajero(Pasajero& _pasajero) {
    for (int i = 0; i < pasajeros.size(); i++) {
        if (pasajeros[i].getNombre() == _pasajero.getNombre()) {
            pasajeros[i] = _pasajero;
        }
    }
}

void Vuelo::imprimirVuelo() {
    cout << "******** VUELO " << getNumeroVuelo() << " ********" << endl;
    cout << "Fecha: ";
    fecha.imprimirFecha();
    cout << "Destino: " << getDestino() << endl;
    cout << "Precio: $" << getPrecioVuelo() << endl;
    cout << "Distancia: " << getDistanciaVuelo() << " km" << endl;
    cout << "Aerolinea: " << getAerolinea() << endl;
    cout << "Hora: " << getHora() << endl;
}

void Vuelo::imprimirPasajeros() {
    cout << "******** PASAJEROS ********" << endl;
    for (int i = 0; i < pasajeros.size(); i++) {
        pasajeros[i].imprimirPasajero();
    }
}
