#include "CharBag.h"
#include "LinkedList.h"

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

void deleteCharBag(CharBag& b){
    delete(b->caracteres);
    delete[] (b->ocurrencias);
    delete(b);
}

void add(CharBag& b, char c){
    b->ocurrencias[c] = b->ocurrencias[c] + 1;
    if(b->ocurrencias[c] == 1)
        mkCons(c, b->caracteres);
}

int get(CharBag& b, char c){
    return b->ocurrencias[c];
}




