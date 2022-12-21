#include "Matrix.h"

using namespace std;

Matrix::Matrix(int inputMatrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = inputMatrix[i][j];
        }
    }
}

void Matrix::printMetrix() {
    cout << endl;
    for (auto &j: matrix) {
        for (int k: j) {
            cout << k << "\t";
        }
        cout << endl;
    }
}

void Matrix::addition(int secondMatrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = matrix[i][j] + secondMatrix[i][j];
        }
    }
    printMetrix();
}

void Matrix::subtraction(int secondMatrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = matrix[i][j] - secondMatrix[i][j];
        }
    }
    printMetrix();
}

void Matrix::scalarMultiplication(int scalarValue) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = matrix[i][j] * scalarValue;
        }
    }
    printMetrix();
}

void Matrix::multiplication(int secondMatrix[3][3]) {
    int mult[3][3] = {0};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k) {
                mult[i][j] += matrix[i][k] * secondMatrix[k][j];
            }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << mult[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix::transpose() {
    int transpose[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpose[i][j] << "\t";
        }
        cout << endl;
    }
}

void Matrix::rank() {
    int i, j, n, k, m, r, N, z, R, p, q, v;
    m = 3;
    n = 3;
    if (matrix[0][0] == 0) {
        for (j = 0; j < m; j++) {
            z = -1;
            for (i = 1; i < n; i++) {
                if (matrix[i][j] != 0) {
                    z = i;
                    break;
                }
            }
            if (z != -1) {
                for (v = 0; v < m; v++) {
                    int t = matrix[0][v];
                    matrix[0][v] = matrix[i][v];
                    matrix[i][v] = t;
                }
                break;
            }
        }
    }
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            p = matrix[k][k];
            q = matrix[i][k];
            for (j = 0; j < m; j++) {
                matrix[i][j] = p * matrix[i][j] - q * matrix[k][j];
            }
        }
    }
    z = 0;
    for (i = 0; i < n; i++) {
        int c = 0;
        for (j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                c++;
            }
        }
        if (c == m) {
            z++;
        }
    }
    R = n - z;
    N = m - R;
    cout << "Rank of the matrix : " << R << endl;
}

void Matrix::inverse() {
    int i, j;
    // finding the determinant
    for (i = 0; i < 3; i++)
        determinant = determinant + (matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] -
                                                     matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]));

    cout << "\n\nInverse of matrix is : \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << ((matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3]) -
                     (matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3])) / determinant << "\t";
        }
        cout << "\n";
    }
}

void Matrix::adjoint() {
    inverse();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << (matrix[i][j] / determinant);
        }
        cout << "\n";
    }
}
