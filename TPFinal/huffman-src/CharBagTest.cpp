#include "CharBag.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>

using namespace std;

void testEmptyCharBag(){
    CharBag bag = emptyCharBag(4);
    assert(get(bag, 0) == 0);
    assert(get(bag, 1) == 0);
    assert(get(bag, 2) == 0);
    assert(get(bag, 3) == 0);
    assert(get(bag, 3) == 0);
    assert(get(bag,4) == NULL);
    assert(get(bag,5) == NULL);
    std::cout << "testEmptyCharBag -- OK" << std::endl;
}

void testAddAndGet(){
    CharBag bag = emptyCharBag(4);
    add(bag, 0);
    assert(get(bag, 0) == 1);
    add(bag, 0);
    assert(get(bag, 0) == 2);
    std::cout << "testAddAndGet -- OK" << std::endl;
}

void testValid(){
    CharBag bag = emptyCharBag(256);
    add(bag, 'a');
    add(bag, 'b');
    CharBagIterator it = iterate(bag);
    assert(valid(it));
    next(it);
    assert(valid(it));
    next(it);
    assert(!valid(it));
    std::cout << "testValid -- OK" << std::endl;
}

void testCurrentCharAndNext(){
    CharBag bag = emptyCharBag(256);
    add(bag, 'a');
    add(bag, 'b');
    CharBagIterator it = iterate(bag);
    assert(currentChar(it) == 'b');
    next(it);
    assert(currentChar(it) == 'a');
    std::cout << "testCurrentCharAndNext -- OK" << std::endl;
}

void testCurrentCount(){
    CharBag bag = emptyCharBag(256);
    add(bag, 'b');
    add(bag, 'a');
    add(bag, 'b');
    add(bag, 'c');
    add(bag, 'b');
    add(bag, 'a');

    CharBagIterator it = iterate(bag);
    assert(currentCount(it) == 1);
    next(it);
    assert(currentCount(it) == 2);
    next(it);
    assert(currentCount(it) == 3);
    std::cout << "testCurrentCount -- OK" << std::endl;
}
