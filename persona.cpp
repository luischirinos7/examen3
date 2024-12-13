#include "persona.h"
#include "archivo.h"
#include <iostream>
using namespace std;

Persona* cabeza = nullptr;

void crearPersona() {
    Persona* nuevaPersona = new Persona;
    cout << "Ingrese cedula: ";
    cin >> nuevaPersona->cedula;
    cout << "Ingrese nombre: ";
    cin >> nuevaPersona->nombre;
    cout << "Ingrese apellido: ";
    cin >> nuevaPersona->apellido;
    cout << "Ingrese email: ";
    cin >> nuevaPersona->email;
    cout << "Ingrese cantidad de vehiculos: ";
    cin >> nuevaPersona->cantidad_vehiculos;
    cout << "¿Activo? (1 para sí, 0 para no): ";
    cin >> nuevaPersona->activo;
    cout << "Ingrese direccion: ";
    cin.ignore();
    getline(cin, nuevaPersona->direccion);

    nuevaPersona->siguiente = cabeza;
    cabeza = nuevaPersona;
    cout << "Persona creada exitosamente.\n";
    guardarPersonasEnArchivo("Personas.csv");
}

void leerPersonas() {
    Persona* actual = cabeza;
    cout << "Lista de personas:\n";
    while (actual != nullptr) {
        cout << "Cedula: " << actual->cedula << ", Nombre: " << actual->nombre
             << ", Apellido: " << actual->apellido << ", Email: " << actual->email
             << ", Cantidad de Vehiculos: " << actual->cantidad_vehiculos 
             << ", Activo: " << actual->activo << ", Direccion: " << actual->direccion << endl;
        actual = actual->siguiente;
    }
}

void actualizarPersona() {
    string cedula;
    cout << "Ingrese la cedula de la persona a actualizar: ";
    cin >> cedula;
    Persona* actual = cabeza;
    while (actual != nullptr) {
        if (actual->cedula == cedula) {
            cout << "Ingrese nuevo nombre: ";
            cin >> actual->nombre;
            cout << "Ingrese nuevo apellido: ";
            cin >> actual->apellido;
            cout << "Ingrese nuevo email: ";
            cin >> actual->email;
            cout << "Ingrese nueva cantidad de vehiculos: ";
            cin >> actual->cantidad_vehiculos;
            cout << "¿Activo? (1 para sí, 0 para no): ";
            cin >> actual->activo;
            cout << "Ingrese nueva direccion: ";
            cin.ignore();
            getline(cin, actual->direccion);
            cout << "Persona actualizada exitosamente.\n";
            guardarPersonasEnArchivo("Personas.csv");
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Persona no encontrada.\n";
}

void eliminarPersona() {
    string cedula;
    cout << "Ingrese la cedula de la persona a eliminar: ";
    cin >> cedula;
    Persona* actual = cabeza;
    Persona* anterior = nullptr;
    while (actual != nullptr) {
        if (actual->cedula == cedula) {
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            cout << "Persona eliminada exitosamente.\n";
            guardarPersonasEnArchivo("Personas.csv");
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Persona no encontrada.\n";
}
