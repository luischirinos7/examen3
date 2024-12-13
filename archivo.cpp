#include "archivo.h"
#include "persona.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void cargarPersonasDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        Persona* nuevaPersona = new Persona;
        stringstream ss(linea);
        getline(ss, nuevaPersona->cedula, ',');
        getline(ss, nuevaPersona->nombre, ',');
        getline(ss, nuevaPersona->apellido, ',');
        getline(ss, nuevaPersona->email, ',');
        ss >> nuevaPersona->cantidad_vehiculos;
        ss.ignore();
        ss >> nuevaPersona->activo;
        ss.ignore();
        getline(ss, nuevaPersona->direccion, ',');

        nuevaPersona->siguiente = cabeza;
        cabeza = nuevaPersona;
    }

    archivo.close();
    cout << "Datos cargados exitosamente desde el archivo.\n";
}

void guardarPersonasEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    Persona* actual = cabeza;
    while (actual != nullptr) {
        archivo << actual->cedula << ',' << actual->nombre << ',' 
                << actual->apellido << ',' << actual->email << ',' 
                << actual->cantidad_vehiculos << ',' << actual->activo << ',' 
                << actual->direccion << '\n';
        actual = actual->siguiente;
    }

    archivo.close();
    cout << "Datos guardados exitosamente en el archivo.\n";
}
