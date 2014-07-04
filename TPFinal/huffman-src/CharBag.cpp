#include "CharBag.h"
#include "LinkedList.h"

/*Inv.Rep: -Las ocurrencias deben ser valores mayores a cero.
           -Los caracteres no pueden repetirse en la lista.*/

struct CharBagStr{
    int *ocurrencias;
    List caracteres;
};

CharBag emptyCharBag(int n){
    CharBag newBag = new CharBagStr;
    newBag -> ocurrencias = new int[n]; //La capacidad del array es n.
    newBag -> caracteres = Nil();
    for(int x=0;x<n;x++)
        newBag -> ocurrencias[x] = 0;
    return newBag;
}

void deleteCharBag(CharBag& bag){
    clear1(bag->caracteres);
    delete[] (bag->ocurrencias);
    delete(bag);
}

void add(CharBag& bag, char caracter){
    bag->ocurrencias[caracter] = bag->ocurrencias[caracter] + 1;
    if(bag->ocurrencias[caracter] == 1)
        mkCons(caracter, bag->caracteres);
}

int get(CharBag& b, char c){
    return b->ocurrencias[c];
}

struct CharBagIteratorStr{
    Recorrido r;
    int *ocurrencias;
};

// Construye un iterador a un CharBag apuntando al primer elemento definido.
// Complejidad: O(1)
CharBagIterator iterate(CharBag bag){
    CharBagIterator it = new CharBagIteratorStr;
    it -> r = initialize(bag->caracteres);
    it -> ocurrencias = bag -> ocurrencias;
    return it;
}

// Libera la memoria correspondiente al iterador.
void deleteCharBagIterator(CharBagIterator& it){
    finish(it->r);
    delete(it);
}

bool valid(CharBagIterator it){
    return !finished(it->r);
}

// Avanza al siguiente elemento definido en el CharBag
// (aquellos con ocurrencias mayor o igual a cero)
// PRE: valid(it)
// Complejidad: O(1), NOTA: Esto debe ser independiente del tamaño máximo del CharBag
void next(CharBagIterator it){
    next(it->r);
}

// Retorna el caracter actualmente apuntado por el iterador.
// PRE: valid(it)
// Complejidad: O(1)
char currentChar(CharBagIterator it){
    return getCurrent(it->r);
}

// Retorna la cantidad de ocurrencias del caracter actualmente apuntado por el iterador.
// PRE: valid(it)
// Complejidad: O(1)
int currentCount(CharBagIterator it){
    return it->ocurrencias[getCurrent(it->r)];
}
