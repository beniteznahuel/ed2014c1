#include <iostream>
#include "ListNodeDestructive.h"

using namespace std;

int main(){
	List nl = Nil();
	mkCons(4, nl);
	mkCons(2, nl);
	tkTail(nl);
	cout << head(nl) << endl;
	return 0;
}

/*  ESTAS FUNCIONES SE DECLARAN ARRIBA DEL MAIN

    int sum (xs);
    int Length(List xs);
    List mapSucc(List xs); // Le suma 1 a cada elemento
    int promedio(List xs);
    List take(int  n, List xs) // Toma los "n" primeros numeros
    List drop(int n, List xs) // Borra los "n" primeros */
