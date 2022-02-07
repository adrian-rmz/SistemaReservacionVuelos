/*  Autor: 
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#ifndef VUELO_H
#define VUELO_H

#include <vector>
#include <iostream>
using namespace std;
#include "Fecha.h"
#include "Pasajero.h"
#include "Usuario.h"

class Vuelo {
    public:
        // Constructor por defecto
        Vuelo();

        // Constructor por parámetros
        Vuelo(const Fecha&, int, string, double, double, string, string, vector<Pasajero>);

        // Destructor
        ~Vuelo();

        // Métodos Getters o de Acceso
        Fecha getFecha() const;
        int getNumeroVuelo() const;
        string getDestino() const;
        double getPrecioVuelo() const;
        double getDistanciaVuelo() const;
        string getAerolinea() const;
        string getHora() const;

        // Métodos Setters o Modificadores
        void setFecha(Fecha&);
        void setNumeroVuelo(int);
        void setDestino(string);
        void setPrecioVuelo(double);
        void setDistanciaVuelo(double);
        void setAerolinea(string);
        void setHora(string);

        // Métodos Adicionales
        void agregarPasajero(Pasajero&);
        void eliminarPasajero(Pasajero&);
        void modificarPasajero(Pasajero&);
        void imprimirVuelo();
        void imprimirPasajeros();

    private:
        Fecha fecha;
        int numeroVuelo;
        string destino;
        double precioVuelo;
        double distanciaVuelo;
        string aerolinea;
        string hora;
        vector<Pasajero> pasajeros;
};

#endif // VUELO_H