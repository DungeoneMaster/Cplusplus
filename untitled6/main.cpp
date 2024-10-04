#include <iostream>
#include "Matrix.h"

using namespace std;



int main() {

    int size;
    //cin >> size;

    Matrix matrix(1,1);
    //matrix.input(size);
    Matrix d = matrix;
    Matrix a(4,15);


    a(1)[3] = 2;
    a[1][3] = 23;
    a(4)(3) = 1234;
    a[4](3) = 90;
    a.output();
    cout << a(2)[2];
    //for(int l = 0; l < 1; l++)
    //    matrix[l].input(size);


    //((matrix[0] + matrix[1] * ~matrix[2] + k) * ~matrix[3]).output();


    return 0;
}

