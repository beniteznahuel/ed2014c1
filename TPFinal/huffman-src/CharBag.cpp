struct CharBagStr{
    char *ocurrencias;
    LinkedList caracteres;
}

CharBag emptyCharBag(int n){
    CharBag nuevaBag = new CharBagStr;
    nuevaBag -> ocurrencias = new char[n]; //La capacidad del array es n.
    nuevaBag -> caracteres = Nil();
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
    if(b->ocurrencias == 1)
        mkCons(c, b->caracteres);
}

int get(CharBag& b, char c){
    return b->caracteres[c];
}
