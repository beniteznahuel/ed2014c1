#include "ListNodeDestructive.h"

struct ListNodeSt{
	ELEM_TYPE elem;
	ListNodeSt* next;
};

List Nil(){
	return NULL;
}

List singleton(ELEM_TYPE x, List xs){
	List newNode = new ListNodeSt;
	newNode -> elem = x;
	newNode -> next = xs;
	return newNode;
}

void mkCons(ELEM_TYPE x, List& xs){
	xs = singleton(x, xs);
}

void mkSnoc(List& xs, ELEM_TYPE x){
	List current = xs;
	if(current != NULL){
		while(current -> next != NULL)
			current = current -> next;
		current -> next = singleton(x, NULL);
	}
	else
		mkCons(x, xs);
}

void tkTail(List& xs){
	if(not(isNil(xs)))
		xs = xs -> next;
}

ELEM_TYPE head(List xs){
	if(not(isNil(xs)))
		return xs -> elem;
}

bool isNil(List xs){
	return xs == NULL;
}

List copy(List xs){
    if(xs =! NULL){
        List nl = singleton(xs -> elem, NULL);
        xs = xs -> next;
        List retorno = nl;
        while(xs != NULL){
            nl -> next = singleton(xs -> elem, NULL);
            nl = nl -> next;
            xs = xs -> next;
        }
    }
    else
        return Nil();

    return retorno;
}
