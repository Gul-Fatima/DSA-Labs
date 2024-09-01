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




#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int binarySearch(int* nums, int size, int target) {
//    int left = 0;
//    int right = size - 1;
//
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//
//        if (nums[mid] == target) {
//            return mid;
//        }
//        else if (nums[mid] < target) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//
//    return -1;
//}
//
//void inputArray(int* arr, int size) {
//    cout << "Enter " << size << " integers for the array:" << endl;
//    for (int i = 0; i < size; i++) {
//        cin >> arr[i];
//    }
//}
//
//void printArray(int* arr, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    int size;
//    cout << "Enter the size of the array: ";
//    cin >> size;
//
//    int* arr = new int[size];
//
//    inputArray(arr, size);
//
//    // Sort the array
//    sort(arr, arr + size);
//
//    cout << "Sorted array:" << endl;
//    printArray(arr, size);
//
//    int target;
//    cout << "Enter the value to search for: ";
//    cin >> target;
//
//    int index = binarySearch(arr, size, target);
//    if (index != -1) {
//        cout << "Value found at index: " << index << endl;
//    }
//    else {
//        cout << "Value not found in the array." << endl;
//    }
//
//    delete[] arr;
//    return 0;
//}

