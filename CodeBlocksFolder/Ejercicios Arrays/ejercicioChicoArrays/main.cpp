#include <iostream>

using namespace std;

double sum (int n, double* numbers){
    double result = 0;
    for(int i=0;i<n;i++)
        result += numbers[i];
    return result;
}

int main()
{
    int n;
    cout << " Cuantos numeros desea ingresar: "; // printf
    cin >> n; // scanf
    cout << " Ingrese " << n << " numeros" << endl;
    double* numbers = new double[n];
    for(int i; i<n ; i++){
        cin >> numbers[i];
        delete[] numbers;
    }
    cout << "La suma es: " << sum(n, numbers) << endl;
    return 0;
}
