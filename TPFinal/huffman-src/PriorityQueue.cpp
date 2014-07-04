#include "PriorityQueue.h"
#include <iostream>
#include <stdlib.h>

/*Inv. Rep: - Los elementos con mayor prioridad son los primeros a ser desencolados.
            - El totalSize es la cantidad máxima de elementos que puede almacenar la cola, dicho valor debe ser mayor cero.
            - El actualSize es la cantidad actual de elementos en la cola, jamás puede ser mayor al totalSize ni tampoco puede ser menor a cero.
*/

struct PriorityQueueStr{
    HuffmanTree* elements;
    int totalSize;
    int actualSize;
};

PriorityQueue emptyPriorityQueue(){
    PriorityQueue newPQ = new PriorityQueueStr;
    newPQ -> totalSize = 256; // Hardcodeo 256 porque estamos trabajando con codificacion ASCII y la máxima cantidad posible de elementos diferentes es 256.
    newPQ -> elements = new HuffmanTree[newPQ -> totalSize + 1];
    newPQ -> actualSize = 0;
    newPQ -> elements[0] = leaf('x',0); // Necesito quedarme con la posicion 0 para guardar el elemento más prioritario allí.
    return newPQ;
}

int size(PriorityQueue q){
    return q -> actualSize;
}

void deletePriorityQueue(PriorityQueue& q){
    deleteHuffmanTree(q->elements[0]);
    delete[] q->elements;
    delete(q);
}

void enqueue(PriorityQueue& q, HuffmanTree t){

    int posiblePosition = ++(q -> actualSize); // Posición a encolar

    while(weight(q -> elements[posiblePosition/2]) > weight(t)) {
        q -> elements[posiblePosition] = q -> elements[posiblePosition/2];
        posiblePosition = posiblePosition/2;
    }

    q -> elements[posiblePosition] = t;

}

HuffmanTree dequeue(PriorityQueue& q){

   int posiblePosition, child;

    //error al querer desencolar de cola vacía
    if(size(q) == 0) {
        std::cout << "Cola vacía" << std::endl;
        exit(1);
    }

    HuffmanTree min = q -> elements[1]; // primer elemento
    HuffmanTree last = q -> elements[q -> actualSize--]; // último elemento

    //halla la posición donde insertar
    for(posiblePosition = 1; posiblePosition * 2 <= q -> actualSize; posiblePosition = child){
        child = posiblePosition * 2;
        if(child != q -> actualSize && weight(q -> elements[child + 1]) < weight(q -> elements[child]))
            child++;

        if(weight(last) > weight(q -> elements[child]))
            q -> elements[posiblePosition] = q -> elements[child];
        else
            break;
    }

    q -> elements[posiblePosition] = last; // agrega el último elemento en la posicion correspondiente
    return min;
}
