#include <iostream>
#include <vector>
using namespace std;


class Matrix {
	int rows, cols;
	int** matrix;
public:
	//constructor:
	Matrix(int r, int c):rows(r),cols(c) {
		matrix = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols];
		}
	}
	~Matrix() {
		for (int i = 0; i < rows; i++)
		{
			delete[]matrix[i];
		}
		delete[] matrix;
	}
	//input value:
	void input() const {
		cout << "Inputting values of matrix" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << "Enter value:";
				cin >> matrix[i][j];
			}
		}
	}
	//Matrix Addition:
	Matrix operator +(const Matrix &obj) {
		cout << "\n \n Matrix Addition:" << endl;
		if (rows != obj.rows or cols != obj.cols)
			cout <<"Invalid operation.";
		Matrix temp = Matrix(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				temp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
			}
		}
		return temp;
	}
	//Matrix Subtraction:
	Matrix operator -(const Matrix& obj) {
		cout << "\n \n Matrix Subtraction:" << endl;
		if (rows != obj.rows or cols != obj.cols)
			cout << "Invalid operation.";
		Matrix temp = Matrix(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				temp.matrix[i][j] = matrix[i][j] -  obj.matrix[i][j];
			}

		}
		return temp;
	}
	// Matrix multiplication:
	Matrix operator *(const Matrix& obj) {
		cout << "\n \n Matrix Multiplication:" << endl;
		if (cols != obj.rows) {
			cout << "Invalid operation.";
			exit(0);
		}
		Matrix temp(rows, obj.cols); 

		// Initializing the temp matrix to zero
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < obj.cols; j++) {
				temp.matrix[i][j] = 0;
			}
		}

		//multiplication
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < obj.cols; j++) {
				for (int k = 0; k < cols; k++) {
					temp.matrix[i][j] += matrix[i][k] * obj.matrix[k][j];
				}
			}
		}

		return temp;
	}

	//Print matrix:
	void printMatrix() {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	//Transpose of matrix:
	void transposeMatrix() const{
		cout << "\n \n Transpose of matrix:" << endl;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix[j][i] << " ";
			}
			cout << endl;
		}
	}

	void scalarMultiplication(int scalar) {
		cout << "\n \n Scalar Multiplication:" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = scalar * matrix[i][j];
			}
		}
	}
	
};

int main() {
	// Input for matrixA
	Matrix matrixA(2, 2);
	matrixA.input();

	// Input for matrixB
	Matrix matrixB(2, 2);
	matrixB.input();

	// Matrix Addition
	Matrix sum = matrixA + matrixB;
	sum.printMatrix();

	// Matrix Subtraction
	Matrix difference = sum - matrixB;
	difference.printMatrix();

	// Matrix Multiplication
	Matrix product = matrixA * matrixB;
	product.printMatrix();

	// Scalar Multiplication
	Matrix scalar(2, 2); 
	scalar.input();
	scalar.scalarMultiplication(5);
	cout << "Result of scalar multiplication:" << endl;
	scalar.printMatrix();

	// Transpose of Matrix
	Matrix transpose(2, 2); 
	transpose.input();
	transpose.transposeMatrix();

	return 0;
}
