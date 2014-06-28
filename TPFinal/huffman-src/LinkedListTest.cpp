#include "LinkedList.h"
#include <stdlib.h>
#include <assert.h>

using namespace std;

void testNil(){
    List l = Nil();
    assert(isNil(l));
    mkCons(1,l);
    assert(!isNil(l));
    cout << "testNil -- OK" << endl;
}

void testMkCons(){
    List l = Nil();
    mkCons(1,l);
    assert(head(l) == 1);
    mkCons(7,l);
    assert(head(l) == 7);
    cout << "testMkCons -- OK" << endl;
}

void testTkTail(){
    List l = Nil();
    mkCons(1,l);
    mkCons(6,l);
    mkCons(8,l);
    mkCons(23,l);
    assert(head(l) == 23);
    tkTail(l);
    assert(head(l) == 8);
    tkTail(l);
    assert(head(l) == 6);
    cout << "testTkTail -- OK" << endl;
}

void testHead(){
    List l = Nil();
    mkCons(1,l);
    assert(head(l) == 1);
    mkCons(5,l);
    assert(head(l) == 5);
    cout << "testHead -- OK" << endl;
}
