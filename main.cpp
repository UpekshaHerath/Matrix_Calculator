#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
    int matrix1[3][3];
    int matrix2[3][3];
    int numberOfMatrices;
    int calculationNumber;

    string oneMatrixOperations[] = {"transpose", "rank", "adjoint", "inverse"};
    string twoMatricesOperations[] = {"addition", "subtraction", "scalar multiplication", "multiplication"};

    cout << "Select the number of matrices which you need to solve matrices (1 or 2) : ";
    takeInputNumberOfArrays:
    cin >> numberOfMatrices;

    if (!(numberOfMatrices == 1 || numberOfMatrices == 2)) {
        goto takeInputNumberOfArrays;
    }

    // take user inputs for a matrix or for two matrices
    for (int i = 0; i < numberOfMatrices; ++i) {
        if (i == 0) {
            cout << "Enter values for the matrix - 01" << endl;
        } else {
            cout << "Enter values for the matrix - 02" << endl;
        }
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (i == 0) {
                    cout << "place " << j << " , " << k << " : ";
                    cin >> matrix1[j][k];
                }
                if (i == 1) {
                    cout << "place " << j << " , " << k << " : ";
                    cin >> matrix2[j][k];
                }
            }
        }
    }

    Matrix matrixOne(matrix1); // create the first matrix object
    Matrix matrixTwo(matrix2); // create the second matrix object

    if (numberOfMatrices == 1) {
        matrixOne.printMetrix();
        cout << "As you have input only one matrix you can only perform these below operations only: " << endl;
        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << " " << oneMatrixOperations[i] << endl;
        }
        cout << "Input the calculation number which you need to perform : ";
        cin >> calculationNumber;
        switch (calculationNumber) {
            case 1:
                matrixOne.transpose();
                break;
            case 2:
                matrixOne.rank();
                break;
            case 3:
                matrixOne.adjoint();
                break;
            case 4:
                matrixOne.inverse();
                break;
            default:
                cout << "Provided number is not available" << endl;
        }
    } else {
        matrixOne.printMetrix();
        matrixTwo.printMetrix();
        cout << "As you have input only two matrices you can only perform these below operations only: " << endl;
        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << " " << twoMatricesOperations[i] << endl;
        }
        cout << "Input the calculation number which you need to perform : ";
        cin >> calculationNumber;
        // selects the relevant calculation type according to the user input
        switch (calculationNumber) {
            case 1:
                matrixOne.addition(matrix2);
                break;
            case 2:
                matrixOne.subtraction(matrix2);
                break;
            case 3:
                int scalarValue;
                cout << "Provide the scalar value : ";
                cin >> scalarValue;
                matrixOne.scalarMultiplication(scalarValue);
                break;
            case 4:
                matrixOne.multiplication(matrix2);
                break;
            default:
                cout << "Provided number is not available" << endl;
        }
    }
    return 0;
}
