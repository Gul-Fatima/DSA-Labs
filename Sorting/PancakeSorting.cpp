#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class GulFatima_Lab04 {
    int* arr;
    int sze;
public:
    GulFatima_Lab04(int size) {
        sze = size;
        arr = new int[sze];
        for (int i = 0; i < sze; i++) {
            arr[i] = 0;
        }
    }
    // Destructor
    ~GulFatima_Lab04() {
        delete[] arr;
    }
    // Input array elements
    void input() {
        cout << "Enter elements for array:" << endl;
        for (int i = 0; i < sze; i++) {
            cout << "arr[" << i << "]: ";
            cin >> arr[i];
        }
    }
    // Generate random input for the array
    void randomInput(int range) {
        srand(time(0));
        for (int i = 0; i < sze; i++) {
            arr[i] = rand() % range;
        }
    }
    // Pancake Sorting Algorithm 
    void pancakeSort(int& flips, vector<int>& flipSequence) {
        for (int size = sze; size > 1; size--) {
            // Find the index of the maximum element in arr
            int maxIdx = findMax(size);
            // Move the maximum element to the end of the array 
            if (maxIdx != size - 1) {
                // Flip to move the maximum element to the front
                if (maxIdx != 0) {
                    flip(maxIdx + 1);
                    flipSequence.push_back(maxIdx + 1);
                    flips++;
                    print(); 
                }
                flip(size);
                flipSequence.push_back(size);
                flips++;
                print();  
            }
        }
    }
    // function to flip the array 
    void flip(int k) {
        int start = 0;
        while (start < k - 1) {
            swap(arr[start], arr[k - 1]);
            start++;
            k--;
        }
    }
     // function to find the index of the maximum element 
    int findMax(int size) {
        int maxIdx = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    // Print array
    void print() const {
        cout << "\nArray: ";
        for (int i = 0; i < sze; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Display results for Pancake Sort
    void result(int pancakeFlips, const vector<int>& flipSequence) {
        cout << "\nPancake Sort:\n";
        cout << "\tNumber of flips: " << pancakeFlips << endl;
        cout << "\tFlip sequence: ";
        for (int k : flipSequence) {
            cout << k << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    int pancakeFlips = 0;
    vector<int> flipSequence;
    cout << "Enter the size of the array: ";
    cin >> size;
    GulFatima_Lab04 arr1(size);
    int x;
    cout << "Enter:\n\t1: Input elements for array\n\t2: Generate random array\n";
    cin >> x;
    if (x == 1) {
        arr1.input();
    }
    else {
        arr1.randomInput(10);
    }
    arr1.print();
    // Pancake Sort
    arr1.pancakeSort(pancakeFlips, flipSequence);
    // The result for Pancake Sort
    arr1.result(pancakeFlips, flipSequence);
    return 0;}
