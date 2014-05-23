#include <iostream>

using namespace std;

struct PersonaSt{
  string nombre;
  int edad;
  bool casado;
};

typedef PersonaSt* Persona;

Persona crearPersona(string n,  int e);

string getNombre(Persona p);

int getEdad(Persona p);

bool esCasado(Persona p);

void cambiarNombre(Persona& p, string nuevo);

void crecer(Persona& p);
