#include <iostream>
#define ELEM_TYPE int

struct ListStr;
typedef ListStr* List;

struct RecorridoStr;
typedef RecorridoStr* Recorrido;

// INTERFAZ LISTA

List Nil();
bool isNil(List xs);
void tkTail(List& xs);
ELEM_TYPE head(List xs);
void mkCons(ELEM_TYPE x, List& xs);
void clear1(List& xs);

// INTERFAZ RECORRIDO

Recorrido initialize(List xs);
ELEM_TYPE getCurrent(Recorrido r);
bool finished(Recorrido r);
void next(Recorrido& r);
void finish(Recorrido& r);
