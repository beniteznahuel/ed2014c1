#include "LinkedList.h"
#include <iostream>

using namespace std;

struct ListStr {
   ELEM_TYPE elem;
   ListStr* next;
};

List Nil(){
    return NULL;
}

bool isNil(List xs){
    return xs == NULL;
}

//Parcial en Lista vacía
void tkTail(List& xs){
    List elementoABorrar = xs;
    xs = xs -> next;
    delete(elementoABorrar);
}

//Parcial en Lista vacía
ELEM_TYPE head(List xs){ return xs -> elem; }

void mkCons(ELEM_TYPE x, List& xs){
    List newNode = new ListStr;
    newNode -> elem = x;
    newNode -> next = xs;
    xs = newNode;
}

void clear1(List& xs){
    while(not(isNil(xs))){
        List elementoABorrar = xs;
        xs = xs -> next;
        delete(elementoABorrar);
    }
    delete(xs);
}

// Implementación de recorrido.

struct RecorridoStr{
    List current;
};

Recorrido initialize(List xs){
    Recorrido newRecorrido = new RecorridoStr;
    newRecorrido -> current = xs;
    return newRecorrido;
}

ELEM_TYPE getCurrent(Recorrido r){
    return (head(r->current));
}

bool finished(Recorrido r){
    return r -> current == NULL;
}

void next(Recorrido& r){
    r -> current = r -> current -> next;
}

void finish(Recorrido& r){
    delete(r);
}
