#include <iostream>
#define ELEM_TYPE int

struct ListStr;
typedef ListStr* List;
struct RecorridoStr{
    List current;
};
typedef listNode* Recorrido;

// INTERFAZ LISTA

List Nil();
bool isNil(List xs);
void tkTail(List& xs);
ELEM_TYPE head(List xs);
void mkCons(ELEM_TYPE x, List& xs);
void clear1(List& xs);

void mkSnoc(List& xs, ELEM_TYPE x);

void append(List& xs, List& ys);

// INTERFAZ RECORRIDO

Recorrido initialize(List xs);
ELEM_TYPE getCurrent(Recorrido r);
bool finished(Recorrido r);
void next(Recorrido& r);
void finish(Recorrido& r);
