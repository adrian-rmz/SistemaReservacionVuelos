/*  Autor:
    A00830640 Adrián Alejandro Ramírez Cruz
*/
#include "Vuelo.h"
#include <fstream>

void registrarUsuario() {
    string usuario, contrasenna;
    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese la contrasenna: ";
    cin >> contrasenna;
    ofstream archivo;
    archivo.open("usuarios.txt", ios::app);
    if (archivo.fail()) {
        cout << "Error al abrir el archivo" << endl;
    } else {
        archivo << usuario << " " << contrasenna << endl;
        archivo.close();
    }
}

void llenarVectorUsuarios(vector<Usuario> &vector) {
    string usuario, contrasenna;

    ifstream archivo;
    archivo.open("Usuarios.txt");
    if (archivo.fail()) {
        cout << "Error al abrir el archivo" << endl;
    } else {
        while (archivo >> usuario >> contrasenna) {
            Usuario usuarioTemp(usuario, contrasenna);
            vector.push_back(usuarioTemp);
        }
        archivo.close();
    }
}

void iniciarSesion(vector<Usuario> vector) {
    string usuario, contrasenna;
    bool encontrado = false;

    cout << "Ingrese su usuario: ";
    cin >> usuario;
    cout << "Ingrese su contrasenna: ";
    cin >> contrasenna;
    
    while (encontrado == false) {
        for (int i = 0; i < vector.size(); i++) {
            if (vector[i].getUsuario() == usuario && vector[i].getContrasenna() == contrasenna) {
                encontrado = true;
                cout << "Bienvenido " << usuario << endl;
            }
        }
        if (encontrado == false) {
            cout << "Usuario o contrasenna incorrectos" << endl;
            cout << "Ingrese su usuario: ";
            cin >> usuario;
            cout << "Ingrese su contrasenna: ";
            cin >> contrasenna;
        }
    }
}

void llenarVectorPasajeros(vector<Pasajero> &vector) {
    string nombre, telefono;
    double kilometros;

    ifstream archivo;
    archivo.open("Pasajeros.txt");
    if (archivo.fail()) {
        cout << "Error al abrir el archivo" << endl;
    } else {
        while (archivo >> nombre >> telefono >> kilometros) {
            Pasajero pasajero(nombre, telefono, kilometros);
            vector.push_back(pasajero);
        }
        archivo.close();
    }
}

void imprimirVectorPasajeros(vector<Pasajero> vector) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i].imprimirPasajero();
    }
}

void llenarVectorVuelos(vector<Pasajero> &vectorPasajeros, vector<Vuelo> &vectorVuelo) {
    int dia, mes, annio, numeroVuelo, precioVuelo, distanciaVuelo;
    string destino, aerolinea, hora;

    ifstream archivo;
    archivo.open("Vuelos.txt");
    if (archivo.fail()) {
        cout << "Error al abrir el archivo" << endl;
    } else {
        while (archivo >> dia >> mes >> annio >> numeroVuelo >> destino >> precioVuelo >> distanciaVuelo >> aerolinea >> hora) {
            Fecha fecha(dia, mes, annio);
            Vuelo vuelo(fecha, numeroVuelo, destino, precioVuelo, distanciaVuelo, aerolinea, hora, vectorPasajeros);
            vectorVuelo.push_back(vuelo);
        }
        archivo.close();
    }
}

void imprimirVectorVuelos(vector<Vuelo> vector) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i].imprimirVuelo();
    }
}

void filtrarVueloDestino(vector<Vuelo> vector, string destino) {
    int vuelosEncontrados;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].getDestino() == destino) {
            vector[i].imprimirVuelo();
            vuelosEncontrados++;
        }
    }
    if (vuelosEncontrados == 0) {
        cout << "No se encontraron vuelos con el destino " << destino << endl;
    }
}

void filtrarVueloFecha(vector<Vuelo> vector, Fecha fecha) {
    int vuelosEncontrados;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].getFecha().getDia() == fecha.getDia() && vector[i].getFecha().getMes() == fecha.getMes() && vector[i].getFecha().getAnnio() == fecha.getAnnio()) {
            vector[i].imprimirVuelo();
            vuelosEncontrados++;
        }
    }
    if (vuelosEncontrados == 0) {
        cout << "No se encontraron vuelos con la fecha ";
        fecha.imprimirFecha();
    }
}

void filtrarVueloAerolinea(vector<Vuelo> vector, string aerolinea) {
    int vuelosEncontrados;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].getAerolinea() == aerolinea) {
            vector[i].imprimirVuelo();
            vuelosEncontrados++;
        }
    }
    if (vuelosEncontrados == 0) {
        cout << "No se encontraron vuelos con la aerolinea " << aerolinea << endl;
    }
}

int main() {

    // Login | Signup de usuario
    vector<Usuario> usuarios;
    llenarVectorUsuarios(usuarios);

    int menuUsuario = 0;
    do {
        int opcionMenuUsuario;
        cout << "---------- MENU USUARIO ----------" << endl;
        cout << "1. Signup" << endl;
        cout << "2. Login" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionMenuUsuario;

        if (opcionMenuUsuario == 1) {
            registrarUsuario();
            llenarVectorUsuarios(usuarios);
            cout << "Usuario registrado" << endl;
        } else if (opcionMenuUsuario == 2) {

            iniciarSesion(usuarios);
            menuUsuario = 1;

            // Menú operaciones
            int menuOperaciones = 0;
            do {
                vector<Pasajero> pasajeros;
                vector<Vuelo> vuelos;
                string destino, aerolinea;
                int dia, mes, annio;
                Fecha fecha;

                llenarVectorPasajeros(pasajeros);
                llenarVectorVuelos(pasajeros, vuelos);

                int opcionMenuOperaciones = 0;
                cout << "---------- MENU OPERACIONES ----------" << endl;
                cout << "1. Ver lista de pasajeros" << endl;
                cout << "2. Ver lista de vuelos" << endl;
                cout << "3. Filtrar vuelos por destino" << endl;
                cout << "4. Filtrar vuelos por fecha" << endl;
                cout << "5. Filtrar vuelos por aerolinea" << endl;
                cout << "6. Salir" << endl;
                cout << "Seleccione una opcion: ";
                cin >> opcionMenuOperaciones;
                
                if (opcionMenuOperaciones == 1) {
                    imprimirVectorPasajeros(pasajeros);
                } else if (opcionMenuOperaciones == 2) {
                    imprimirVectorVuelos(vuelos);
                } else if (opcionMenuOperaciones == 3) {
                    cout << "Ingrese destino: ";
                    cin >> destino;
                    filtrarVueloDestino(vuelos, destino);
                } else if (opcionMenuOperaciones == 4) {
                    cout << "Ingrese dia, mes y annio (separados por un espacio): ";
                    cin >> dia >> mes >> annio;
                    fecha.setDia(dia);
                    fecha.setMes(mes);
                    fecha.setAnnio(annio);
                    filtrarVueloFecha(vuelos, fecha);
                } else if (opcionMenuOperaciones == 5) {
                    cout << "Ingrese aerolinea: ";
                    cin >> aerolinea;
                    filtrarVueloAerolinea(vuelos, aerolinea);
                } else if (opcionMenuOperaciones == 6) {
                    cout << "Saliendo..." << endl;
                    menuOperaciones = 1;
                } else {
                    cout << "Opcion no valida" << endl;
                }
            } while (menuOperaciones == 0);

        } else if (opcionMenuUsuario == 3) {
            menuUsuario = 1;
            cout << "Saliendo..." << endl;
        } else {
            cout << "Opcion invalida" << endl;
        }
    } while (menuUsuario == 0);
    
    return 0;
}