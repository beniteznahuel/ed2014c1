#include "Persona.h"

Persona crearPersona(string n, int e){
  Persona nuevaPersona = new PersonaSt;
  nuevaPersona->nombre = n;
  nuevaPersona->edad = e;
  nuevaPersona->casado = false;
  return nuevaPersona;
}

void cambiarNombre(Persona& p, string nuevo) {
  p->nombre = nuevo;
}

int getEdad(Persona p){
  return p->edad;
}

string getNombre(Persona p){
  return p->nombre;
}

bool esCasado(Persona p){
  return p->casado;
}

void crecer(Persona& p){
  p->edad = p->edad + 1;
}


struct lista{
  int elem=2;
  lista* siguiente = null;
}