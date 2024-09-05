#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int** matrix;
public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Input values
    void input() {
        cout << "\nInputting values of matrix" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter value: ";
                cin >> matrix[i][j];
            }
        }
    }

    // Matrix addition
    Matrix operator +(const Matrix& obj) const {
        if (rows != obj.rows || cols != obj.cols) {
            cout << "Invalid operation: Matrices have different dimensions." << endl;
            exit(1);
        }
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
            }
        }
        return temp;
    }

    // Matrix subtraction
    Matrix operator -(const Matrix& obj) const {
        if (rows != obj.rows || cols != obj.cols) {
            cout << "Invalid operation: Matrices have different dimensions." << endl;
            exit(1);
        }
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.matrix[i][j] = matrix[i][j] - obj.matrix[i][j];
            }
        }
        return temp;
    }

    // Matrix multiplication
    Matrix operator *(const Matrix& obj) const {
        if (cols != obj.rows) {
            cout << "Invalid operation: Incompatible matrix dimensions." << endl;
            exit(1);
        }
        Matrix temp(rows, obj.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < obj.cols; j++) {
                temp.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    temp.matrix[i][j] += matrix[i][k] * obj.matrix[k][j];
                }
            }
        }
        return temp;
    }

    // Print matrix
    void printMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Transpose of matrix
    void transposeMatrix() const {
        cout << "\nTranspose of matrix:" << endl;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
    }

    // Scalar multiplication
    Matrix scalarMultiplication(int scalar) const {
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.matrix[i][j] = scalar * matrix[i][j];
            }
        }
        return temp;
    }
};

int main() {
    // Create matrices A and B
    Matrix matrixA(1, 3);
    cout << "Input values for matrix A:" << endl;
    matrixA.input();

    Matrix matrixB(1, 3);
    cout << "Input values for matrix B:" << endl;
    matrixB.input();

    // Scalars X and Y
    int X = 2;
    int Y = -5;

    // Compute XA and YB
    Matrix XA = matrixA.scalarMultiplication(X);
    Matrix YB = matrixB.scalarMultiplication(Y);

    // Compute XA + YB
    Matrix result = XA + YB;

    // Print result
    cout << "\nResult of XA + YB:" << endl;
    result.printMatrix();

    return 0;
}



