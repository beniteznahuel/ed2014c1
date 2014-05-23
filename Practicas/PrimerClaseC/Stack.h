#include <iostream>

using namespace std;

struct StackStr{
  int elem;
  StackStr* next;
}

typedef StackStr* Stack;

//API
void empty();
void push(int n, Stack& s);
void pop(Stack& s);
int top(Stack s);

//Auxiliares
Stack singleton(int n, Stack s);
