#include "arraylist.h"

#include <iostream>
#include <stdlib.h>
#include <assert.h>

void check(ArrayList l, std::string r) {
	std::string ls = toString(l);
	if (ls != r) {
		std::cout << "ERROR: " << ls << " != " << r << std::endl;
		exit(1);
	}
}

void testEmptyArrayList();
void testPush();
void testPop();
void testIsEmpty();
void testSize();
void testGet();
void testSet();
void testIterate();
void testValid();
void testGetCurrent();
void testSetCurrent();
void testNext();
void testInsert();
void testRemove();

int main() {
	testEmptyArrayList();
	testPush();
	testPop();
	testIsEmpty();
	return 0;
}

void testEmptyArrayList() {
	ArrayList l = emptyArrayList();
	check(l,"[ ]");
	deleteArrayList(l);
	std::cout << "testEmptyArrayList - OK" << std::endl;
}

void testPush() {
	ArrayList l = emptyArrayList();
	push(l,3);
	check(l, "[ 3 ]");
	push(l,42);
	check(l, "[ 3 42 ]");
	deleteArrayList(l);
	std::cout << "testPush - OK" << std::endl;
}

void testPop() {
	ArrayList l = emptyArrayList();
	push(l,3);
	push(l,42);
	int i = pop(l);
	assert(i == 42);
	check(l, "[ 3 ]");
	i = pop(l);
	assert(i == 3);
	check(l, "[ ]");
	deleteArrayList(l);
	std::cout << "testPop - OK" << std::endl;
}

void testIsEmpty() {
	ArrayList l = emptyArrayList();
	assert(isEmpty(l));
	push(l,3);
	assert(!isEmpty(l));
	pop(l);
	assert(isEmpty(l));
	deleteArrayList(l);
	std::cout << "testIsEmpty - OK" << std::endl;
}

