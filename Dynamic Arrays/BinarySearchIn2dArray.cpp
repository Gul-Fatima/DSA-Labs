#include <iostream>
using namespace std;

bool searchMatrix(int** matrix, int m, int n, int target) {
    if (m == 0 || n == 0) return false; // to check for an empty array

    int left = 0;
    int right = m * n - 1; //gives last index, if we consider our 2d array as 1d

    while (left <= right) {
        int mid = left + (right - left) / 2;  
        int mid_value = matrix[mid / n][mid % n];  //mid/n : row ; mid%n : cols

        if (mid_value == target) {
            return true; 
        }
        else if (mid_value < target) {
            left = mid + 1;  
        }
        else {
            right = mid - 1; 
        }
    }
    return false;  
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int** matrix = new int* [m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];    }
    // Inputing elements
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    // Search for the target
    bool result = searchMatrix(matrix, m, n, target);
    cout << (result ? "true" : "false") << endl; 

    // Deallocateingmemory
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
