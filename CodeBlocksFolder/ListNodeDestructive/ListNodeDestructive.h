#define ELEM_TYPE int
#include <iostream>

using namespace std;
struct ListNodeSt;

typedef ListNodeSt* List;

List Nil();
void mkCons(ELEM_TYPE x, List& xs);
void mkSnoc(List& xs, ELEM_TYPE x);
void tkTail(List& xs);
ELEM_TYPE head(List xs);
bool isNil(List xs);
List copy(List xs);
