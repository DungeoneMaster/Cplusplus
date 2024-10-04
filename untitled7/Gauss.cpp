//
// Created by dno on 24.09.2024.
//

#include "Gauss.h"

using namespace std;

Gauss::Gauss(int size) : size(size), matrix(size, vector<double>(size)),col(size), col_x(size){}

void Gauss::input() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        cout << "y[" << i << "]= ";
        cin >> col[i];
    }
}

void Gauss::output() {
    for (int i = 0; i < size; i++)
        cout << "x[" << i << "]=" << col_x[i] << endl;
}

void Gauss::method() {
    try {
        double max;
        int k = 0, index;
        const double eps = 0.00001;
        vector<double> x(size);

        while (k < size) {
            max = abs(matrix[k][k]);
            index = k;
            for (int i = k + 1; i < size; i++) {
                if (abs(matrix[i][k]) > max) {
                    max = abs(matrix[i][k]);
                    index = i;
                }
            }
            if (max < eps) {
                cout << "Решение получить невозможно из-за нулевого столбца ";
                cout << index << " матрицы A" << endl;
                throw;
            }


            for (int j = 0; j < size; j++)
                swap(matrix[k][j], matrix[index][j]);

            swap(col[k], col[index]);

            for (int i = k; i < size; i++) {
                double temp = matrix[i][k];
                if (abs(temp) < eps) continue;
                for (int j = k; j < size; j++)
                    matrix[i][j] = matrix[i][j] / temp;
                col[i] = col[i] / temp;
                if (i == k) continue;
                for (int j = 0; j < size; j++)
                    matrix[i][j] = matrix[i][j] - matrix[k][j];
                col[i] = col[i] - col[k];
            }
            k++;
        }


        for (k = size - 1; k >= 0; k--) {
            col_x[k] = col[k];
            for (int i = 0; i < k; i++)
                col[i] = col[i] - matrix[i][k] * col_x[k];
        }
    }
    catch(const char* error_message) {
        cout << error_message << endl;
        exit(52);
    }
}


