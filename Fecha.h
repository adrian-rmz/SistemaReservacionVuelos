/*  Autor: 
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#ifndef FECHA_H
#define FECHA_H

class Fecha {
    public:
        // Cosntructores
        Fecha();
        Fecha(int, int, int);

        // Destructor
        ~Fecha();

        // Métodos Getters o de Acceso
        int getDia() const;
        int getMes() const;
        int getAnnio() const;

        // Métodos Setters o Modificadores
        void setDia(int);
        void setMes(int);
        void setAnnio(int);

        // Metodos Adicionales
        int iguales(Fecha&);
        void imprimirFecha();
        // int numeroNegativo(int);

    private:
        int dia;
        int mes;
        int annio;
};

#endif // FECHA_H