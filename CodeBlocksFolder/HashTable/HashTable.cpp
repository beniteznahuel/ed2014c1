#include <stlib.h>

Struct PairKV{
    K key;
    V value;
}

PairKV* makePair(K k, V v){
    PairKV* newPair = new PairKV;
    newPair -> key = k;
    newPair -> value = v;
    return newPair;
}

typedef PairStr* Pair;

void deletePair(PairKV* p){
    delete(p);
}

unsigned rand (int min, int max){
    return (rand()/RAND_MAX)*(max-min)+min;
}

unsigned hash(HashTable t, K k){
    return(k* t->f + t->g) >> (32 - t -> exp);
}

Struct HashTableStr{
    Pair* table;
    unsigned capacity; // 2^exp
    unsigned exp; //log(cap) > 1
    unsigned f; //random odd
    unsigned g; //random
}

bool has(HashTable t, K k){
    PairKV* p = t -> table[hash(t,k)];
    return p!=NULL && p->key == k;
}

V get(HashTable t, K k){
    return t->table[hash(t,k)] -> value
}

void put(HashTable t, K k, V v){
    unsigned hk = hash(t,k);
    while(t->table[hk] != NULL){
        rehash(t);
        hk=hash(t,k);
    }
    t->table[hk] = makePair(k,v);
}

void remove(HashTable t, K k){
    unsigned hk = hash(t,k);

    delete PairKV(t->table[hk]);
    t->table[hk] = NULL;
}

void rehash(HashTable& t){
    HashTable newTable = new HashTableStr;
    newTable -> exp = t -> exp +1;
    newTable -> capacity = 1 << newTable -> exp;
    newTable -> table = new Pair[newTable->capacity];
    for(int i=newTable->capacity -1;i>=0;--i)
        newTable->table[i]=NULL;
    newTable->f = rand(0,1<<31)|1;
    newTable->g = rand(0,1<<(31 - newTable->exp));
    for(int i=0; i<t->capacity;++i){
        Pair p = t -> table[i];
        if(p!=NULL) put(newTable, p->key, p->value);
    }
    deleteHashTable(t);
    t=newTable;
}
