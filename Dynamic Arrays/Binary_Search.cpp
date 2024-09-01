#include <iostream>
using namespace std;

int binarySearch(const int arr[], int length, int key) {
    int a = 0;
    int b = length - 1;
    while (a <= b) {
        int middle = a + (b - a) / 2;
        if (arr[middle] == key) {
            return middle;
        }
        else if (arr[middle] < key) {
            a = middle + 1;        }
        else {
            b = middle - 1;
        }
    }
    return -1;
}

int main() {
    int arraySize;
    cout << "Enter the number of elements in the array: ";
    cin >> arraySize;

    int* numbers = new int[arraySize];
    int numElements = 0;

    cout << "Enter " << arraySize << " integers: " << endl;
    for (int i = 0; i < arraySize; ++i) {
        int num;
        cout << "numbers[" << i << "]: ";
        cin >> num;
        //To maintain elements in sorted order:
        int j = numElements - 1;
        while (j >= 0 && numbers[j] > num) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = num;
        numElements++;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Enter the required value:";
    cin >> target;
    
        int index = binarySearch(numbers, numElements, target);
        if (index != -1) {
            cout << "Element " << target<< " found at index: " << index << endl;
        }
        else {
            cout << "Element " << target << " not found in the array." << endl;
        }
    
    delete[] numbers;
    return 0;
}
