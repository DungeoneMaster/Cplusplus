//
// Created by dno on 24.09.2024.
//

#ifndef UNTITLED7_GAUSS_H
#define UNTITLED7_GAUSS_H

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Gauss;

class Gauss{
private:
    int size;
    vector<vector<double>> matrix;
    vector<double> col, col_x;
public:
    Gauss(int size = 0);

    void input();
    void output();

    void method();
};


#endif //UNTITLED7_GAUSS_H
