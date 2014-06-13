#include <iostream>
using namespace std;

int main(){
    char *p;
    p = new char[20];
    p[15] = 'a';
    cout << p[15] << endl;
}
