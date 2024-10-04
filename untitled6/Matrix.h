//
// Created by dno on 08.09.2024.
//

#ifndef UNTITLED6_MATRIX_H
#define UNTITLED6_MATRIX_H

#include <iostream>
using namespace std;


class Vector{
private:
    int** array_plus;
public:
    Vector(int** array, int size);

    int& operator [] (int row);
    int& operator () (int col);



};

class Matrix;

class Matrix{

    int size;
    int** matrix;

    int* erase(const int* vector, int n_elem) const;

public:
    Matrix(int size, int k);
    Matrix(int size, const int* array);
    Matrix(int size, int** array2D);

    Matrix(const Matrix& m);


    void input(int size);
    void output();



    Matrix operator()(int row, int col);
    Matrix operator+(const Matrix &matrix);
    Matrix operator-(const Matrix &matrix);
    Matrix operator*(const Matrix &matrix);
    Matrix operator~();


    bool operator==(const Matrix &matrix);

    Vector operator()(int col);
    Vector operator[](int row);


    ~Matrix();
};




#endif //UNTITLED6_MATRIX_H


