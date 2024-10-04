//
// Created by dno on 08.09.2024.
//
#include "Matrix.h"
Vector::Vector(int** array, int size) {
    array_plus = new int * [size];
    for(int i = 0; i < size; i++)
        array_plus[i] = array[i];
}
int& Vector::operator [] (int row){
    row--;
    return *array_plus[row];
}
int& Vector::operator () (int col){
    col--;
    return *array_plus[col];
}

int* Matrix::erase(const int* vec, int n_elem) const{
    int* temp = new int [size] ;
    for(int i = 0; i < size; i++){
        if(i >= n_elem)
            temp[i] = vec[i+1];
        else
            temp[i] = vec[i];
    }
    return temp;
}

Matrix::Matrix(int size, int k): size(size) {
    matrix = new int *[size];
    for(int i = 0; i < size; i++)
        matrix[i] = new int [size];
    if(k != 0)
        for(int i = 0; i < size; i++)
            matrix[i][i] = k;
}
Matrix::Matrix(int size, const int* array) : Matrix{size, 0} {
    for(int i = 0; i < size;i++)
        matrix[i][i] = array[i];
}
Matrix::Matrix(int size, int** array2D) : Matrix{size, 0} {
    for(int i = 0; i < size;i++)
        for(int j = 0; j < size;j++)
            matrix[i][j] = array2D[i][j];
}

Matrix::Matrix(const Matrix& m) : Matrix{m.size, 0} {
    size = m.size;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = m.matrix[i][j];

}

void Matrix::input(int s){
    size = s;
    int** array2D = new int * [size];
    for(int i = 0; i < size;i++)
        array2D[i] = new int [size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> array2D[i][j];
    matrix = array2D;
}
void Matrix::output() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

Matrix Matrix::operator () (int row, int col) {
    int temp_s= size - 1;
    int** array2D = new int * [size-1];
    for(int i = 0; i < size;i++)
        array2D[i] = new int [size-1];
    for(int i = 0; i < temp_s;i++){
        if(i > row - 1)
            matrix[i] = erase(matrix[i + 1], col);
        else
            matrix[i] = erase(matrix[i], col);
    }
    return Matrix{temp_s,array2D};
}


Vector Matrix::operator [] (int row){
    row--;
    int** array = new int * [size];
    for(int i = 0; i < size; i++){
        array[i] = &matrix[row][i];
    }

    Vector vec(array,size);

    delete[] array;
    return vec;
}
Vector Matrix::operator () (int col){
    col--;
    int** array = new int * [size];
    for(int i = 0; i < size; i++){
        array[i] = &matrix[i][col];
    }
    Vector vec(array, size);

    delete[] array;
    return vec;
}


Matrix Matrix::operator + (const Matrix& m) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] += m.matrix[i][j];
    return Matrix{size, matrix};
}
Matrix Matrix::operator - (const Matrix& m) {
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] -= m.matrix[i][j];
    return Matrix{size, matrix};
}
Matrix Matrix::operator * (const Matrix& m) {
    int** array2D = new int * [size];
    for(int i = 0; i < size;i++)
        array2D[i] = new int [size];
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int result = 0;
            for(int g = 0; g < size; g++)
                result += matrix[i][g] * m.matrix[g][j];
            array2D[i][j] = result;
        }
    }
    Matrix mat = Matrix{size, array2D};
    for(int i = 0; i < size; i++)
        delete[] array2D[i];
    delete[] array2D;
    return mat;
}
Matrix Matrix::operator ~ (){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size && i != j; j++)
            swap(matrix[i][j], matrix[j][i]);
    return Matrix{size, matrix};
}

bool Matrix::operator == (const Matrix& m) {
    for(int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if(matrix[i][j] != m.matrix[i][j])
                return false;
    return true;

}
Matrix::~Matrix(){
    for(int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}

