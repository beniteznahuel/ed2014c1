#include <iostream>
#include "Persona.h"

using namespace std;

int main()
{
  Persona p = crearPersona("pepe", 25); 
  cout << getEdad(p) << endl;
  return 0;
}