/*  Autor: 
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#ifndef PASAJERO_H
#define PASAJERO_H

#include <iostream>
using namespace std;

class Pasajero {
    public:
        // Constructor por defecto
        Pasajero();

        // Constructor por parámetros
        Pasajero(string, string, double);

        // Destructor
        ~Pasajero();

        // Métodos Getters o de Acceso
        string getNombre() const;
        string getTelefono() const;
        double getKilometros() const;

        // Métodos Setters o Modificadores
        void setNombre(string);
        void setTelefono(string);
        void setKilometros(double);

        // Métodos Adicionales
        void imprimirPasajero();

    private:
        string nombre;
        string telefono;
        double kilometros;
};

#endif // PASAJERO_H