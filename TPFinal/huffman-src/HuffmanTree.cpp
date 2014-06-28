#include "HuffmanTree.h"
#include "ZipTable.h"
#include <iostream>

/*Inv. Rep: - El peso del nodo es la suma de los pesos de sus hijos.
            - Sólo si es hoja, ambos hijos son NULL.
            - Sólo las hojas tienen caracteres asociados.
*/

struct HuffmanTreeStr{
    char caracter;
    int peso;
    HuffmanTreeStr* izq;
    HuffmanTreeStr* der;
};

//En varias oportunidades necesito crear un nodo pero sin caracter asociado, por eso creé esta funcion.
HuffmanTree singletonTree(int p, HuffmanTree iz, HuffmanTree de){
    HuffmanTree newTree = new HuffmanTreeStr;
    newTree -> peso = p;
    newTree -> izq = iz;
    newTree -> der = de;
    return newTree;
}

// Construye una hoja de un árbold de Huffman a partir de un caracter y un peso.
// Complejidad: O(1)Untitled1
HuffmanTree leaf(char c, int w){
    HuffmanTree newTree = singletonTree(w, NULL, NULL);
    newTree -> caracter = c;
    return newTree;
}

// Construye una nodo binario de un árbol de Huffman a partir de dos hijos.
// Complejidad: O(1)
HuffmanTree binary(HuffmanTree a, HuffmanTree b){
    return singletonTree(weight(a) + weight(b), a, b);
}
// Libera toda la memoria utilizada por un árbol de Huffman.
void deleteHuffmanTree(HuffmanTree& t){
    delete(t);
    //TODO: Esto está mal, debo pensar en como borrarlo por completo.
}

// Retorna el peso de un árbol de Huffman.
// Cmplejidad: O(1)
int weight(HuffmanTree t){
    return t -> peso;
}

bool isNil(HuffmanTree t){
    return t == NULL;
}

bool isLeaf(HuffmanTree t){
    return (isNil(t -> izq)) && (isNil(t -> der));
}

//Necesito crear una función auxiliar para poder hacer recursión recibiendo el ziptable y el bitchain por parámetro.
ZipTable recursiveBuild(ZipTable zt, HuffmanTree t, BitChain bc){
    if(isLeaf(t))
        add(zt, t -> caracter, bc);
    else {
        append(bc, false);
        recursiveBuild(zt, t -> izq, bc);
        remove(bc);
        append(bc, true);
        recursiveBuild(zt, t -> der, bc);
        remove(bc);
    }
    return zt;
}

// Construye la tabla de compresión asociada al árbol de Huffman.
ZipTable buildTable(HuffmanTree t){
    ZipTable zt = emptyZipTable();
    BitChain bc = emptyBitChain();

    return recursiveBuild(zt, t, bc);
}
