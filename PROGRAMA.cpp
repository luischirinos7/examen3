#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Persona {
    string cedula;
    string nombre;
    string apellido;
    string email;
    int cantidad_vehiculos;
    bool activo;
    string direccion;
    Persona* siguiente;
};

Persona* cabeza = nullptr;

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

int main() {
    cargarPersonasDesdeArchivo("Personas.csv");

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Crear persona\n";
        cout << "2. Leer personas\n";
        cout << "3. Actualizar persona\n";
        cout << "4. Eliminar persona\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: crearPersona(); break;
            case 2: leerPersonas(); break;
            case 3: actualizarPersona(); break;
            case 4: eliminarPersona(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 5);

    return 0;
}
