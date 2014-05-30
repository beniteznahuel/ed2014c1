#include "LinkedList.h"

struct ListNode {
   ELEM_TYPE elem;
   ListNode* next;
};

struct ListStr {
   ListNode* first;
   ListNode* last;
};

List Nil(){
    List xs = new ListStr;
    xs -> first = NULL;
    xs -> last = NULL;
    return xs;
}

bool isNil(List xs){
    return xs -> first == NULL;
}

//Parcial en Lista vacía
void tkTail(List& xs){
    ListNode* elementoABorrar = xs -> first;
    xs -> first = xs -> first -> next;
    if(xs -> first == NULL)
        xs -> last = NULL;
    delete(elementoABorrar);
}


//Parcial en Lista vacía
ELEM_TYPE head(List xs){ return xs -> first -> elem; }

void mkCons(ELEM_TYPE x, List& xs){
    ListNode* newNode = new ListNode;
    newNode -> elem = x;
    newNode -> next = xs -> first;
    if(isNil(xs))
    xs -> first = newNode;
}

void clear1(List& xs){
    while(not(isNil(xs))){
        ListNode* elementoABorrar = xs -> first;
        xs -> first = xs -> first -> next;
        delete(elementoABorrar);
    }
    delete(xs);
}

void mkSnoc(List& xs, ELEM_TYPE x){
    if(isNil(xs))
        mkCons(x, xs);
    else{
        ListNode* newNode = new ListNode;
        newNode -> elem = x;
        newNode -> next = NULL;
        xs -> last -> next = newNode;
        xs -> last = newNode;
    }
}

void append(List& xs, List& ys){
    if(isNil(xs)){
        xs = ys;
    }
    else{
        if(not(isNil(ys))){
            xs -> last -> next = ys -> first;
            xs -> last = ys -> last;
            delete(ys);
        }
    }
}
