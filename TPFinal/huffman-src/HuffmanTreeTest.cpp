#include "HuffmanTree.h"

#include <iostream>
#include <stdlib.h>
#include <assert.h>

int testLeaf() {
    HuffmanTree hojaConPeso9 = leaf('x', 9);
    assert(weight(hojaConPeso9) == 9);
    deleteHuffmanTree(hojaConPeso9);
    std::cout << "testLeaf -- OK" << std::endl;
}

int testBinary(){
    HuffmanTree hojaConPeso15= leaf('n', 15);
    HuffmanTree hojaConPeso9 = leaf('x', 9);
    HuffmanTree nodoConPeso24 = binary(hojaConPeso15, hojaConPeso9);
    assert(weight(nodoConPeso24) == 24);
    deleteHuffmanTree(nodoConPeso24);
    std::cout << "testBinary -- OK" << std::endl;
}

int testWeight() {
    HuffmanTree hojaConPeso15= leaf('n', 15);
    HuffmanTree hojaConPeso9 = leaf('x', 9);
    HuffmanTree hojaConPeso3= leaf('e', 3);
    HuffmanTree hojaConPeso10 = leaf('q', 10);
    HuffmanTree nodoConPeso24 = binary(hojaConPeso15, hojaConPeso9);
    HuffmanTree nodoConPeso13 = binary(hojaConPeso3, hojaConPeso10);
    HuffmanTree nodoConPeso37 = binary(nodoConPeso24, nodoConPeso13);
    assert(weight(nodoConPeso37) == 37);
    deleteHuffmanTree(nodoConPeso37);
    std::cout << "testWeight -- OK" << std::endl;
}
