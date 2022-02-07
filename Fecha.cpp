/*  Autor: 
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#include <iostream>
#include <iomanip>
#include "Fecha.h"

// Implementacion del constructor por defecto
Fecha::Fecha() {
    dia = 1;
    mes = 1;
    annio = 2022;
}

// Implementacion del constructor por parámetros
Fecha::Fecha(int _dia, int _mes, int _annio) {
    setAnnio(_annio);
    setMes(_mes);
    setDia(_dia);
}

Fecha::~Fecha() {}

// Implementacion de getters
int Fecha::getDia() const {
    return dia;
}

int Fecha::getMes() const {
    return mes;
}

int Fecha::getAnnio() const {
    return annio;
}

// Implementacion de setters
void Fecha::setDia(int _dia) {
    if (_dia > 0) {
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
            if (_dia > 31) {
                dia = 1;
            } else {
                dia = _dia;
            }
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if (_dia > 30) {
                dia = 1;
            } else {
                dia = _dia;
            }
        } else if (mes == 2) {
            if ((annio % 4 == 0 && annio % 100 != 0) || annio % 400 == 0) {
                if (_dia > 29) {
                    dia = 1;
                } else {
                    dia = _dia;
                }
            } else if (_dia > 28) {
                dia = 1;
            } else {
                dia = _dia;
            }
        }
    } else {
        dia = 1;
    }
}

void Fecha::setMes(int _mes) {
    if (_mes > 0 && _mes <= 12) {
        mes = _mes;
    } else {
        mes = 1;
    }
}

void Fecha::setAnnio(int _annio) {
    if (_annio >= 2022) {
        annio = _annio;
    } else {
        annio = 2022;
    }
}

// Implementacion de metodos adicionales
int Fecha::iguales(Fecha& f) {
    if (f.getDia() == dia && f.getMes() == mes && f.getAnnio() == annio) {
        return 1;
    } else {
        return 0;
    }
}

void Fecha::imprimirFecha() {
    std::cout.fill('0');
    std::cout << std::setw(2) << dia << "/" << std::setw(2) << mes << "/" << std::setw(4) << annio << std::endl;
}