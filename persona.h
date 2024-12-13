#ifndef PERSONA_H
#define PERSONA_H

#include <string>
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

void crearPersona();
void leerPersonas();
void actualizarPersona();
void eliminarPersona();

extern Persona* cabeza;

#endif 
