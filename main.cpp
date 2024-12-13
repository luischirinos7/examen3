#include <iostream>
#include "persona.h"
#include "archivo.h"
using namespace std;

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
