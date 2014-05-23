#include <iostream>
#include "ListNodeDestructive.h"

using namespace std;

int main(){
	List nl = Nil();
	mkCons(4, nl);
	mkCons(2, nl);
	cout << head(nl) << endl;
	return 0;
}