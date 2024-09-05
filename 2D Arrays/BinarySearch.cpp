#include <iostream>
using namespace std;
class Search {
    int rows, cols;
    int** matrix;
public:
    // Constructor
    Search(int r, int c) : rows(r), cols(c) {
        matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }
    // Destructor
    ~Search() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    // Input values
    void input() const {
        cout << "Inputting values of matrix" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter value for matrix[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }    }
    // Binary search
    bool bSearch(int target) const {
        int left = 0;
        int right = (rows * cols) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / cols][mid % cols];
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
};
int main() {
    int target;
    cout << "Enter target: ";
    cin >> target;

    Search mat(2, 2);
    mat.input();
    if (mat.bSearch(target)) {
        cout << "Element found" << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
    return 0;
}
