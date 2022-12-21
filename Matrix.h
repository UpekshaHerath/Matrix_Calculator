#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H
#include <iostream>

using namespace std;

class Matrix {
private:
    int matrix[3][3]{};
    float determinant = 0;

public:
    explicit Matrix(int inputMatrix[3][3]);

    void printMetrix();

    void addition(int secondMatrix[3][3]);

    void subtraction(int secondMatrix[3][3]);

    void scalarMultiplication(int scalarValue);

    void multiplication(int secondMatrix[3][3]);

    void transpose();

    void rank();

    void inverse();

    void adjoint();
};


#endif //UNTITLED_MATRIX_H
