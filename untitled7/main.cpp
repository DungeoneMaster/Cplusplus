#include <iostream>
#include "Gauss.h"

using namespace std;

int main()
{
    int n;
    cout << "Введите количество уравнений: ";
    cin >> n;
    Gauss gauss(n);

    gauss.input();
    gauss.method();
    gauss.output();

}