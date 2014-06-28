#include "PriorityQueue.h"
#include <iostream>
#include <stdlib.h>
#include <assert.h>

void testEmptyPriorityQueue(){
    PriorityQueue empty = emptyPriorityQueue();
    assert(size(empty) == 0);
    std::cout << "testEmptyPriorityQueue -- OK" << std::endl;
}

void testSize(){
    PriorityQueue colaCon2Elementos = emptyPriorityQueue();
    HuffmanTree t1 = leaf('x', 9);
    HuffmanTree t2 = leaf('z', 1);
    enqueue(colaCon2Elementos, t1);
    assert(size(colaCon2Elementos) == 1);
    enqueue(colaCon2Elementos, t2);
    assert(size(colaCon2Elementos) == 2);
    std::cout << "testSize -- OK" << std::endl;
}

void testEnqueueAndDequeue(){
    PriorityQueue colaCon2Elementos = emptyPriorityQueue();
    HuffmanTree t1 = leaf('x', 9);
    HuffmanTree t2 = leaf('z', 1);
    enqueue(colaCon2Elementos, t1);
    enqueue(colaCon2Elementos, t2);
    assert(dequeue(colaCon2Elementos) == t2);
    assert(size(colaCon2Elementos) == 1);
    assert(dequeue(colaCon2Elementos) == t1);
    assert(size(colaCon2Elementos) == 0);
    std::cout << "testEnqueueAndDequeue -- OK" << std::endl;
}
