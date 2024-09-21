#include <iostream>
#include <cstdlib>
using namespace std;

class GulFatima_Lab04 {
    int* arr;
    int* originalArr;  // Backup of the original array
    int sze;

public:
    GulFatima_Lab04(int size) {
        sze = size;
        arr = new int[sze];
        originalArr = new int[sze];  
        for (int i = 0; i < sze; i++) {
            arr[i] = 0;
            originalArr[i] = 0;
        }
    }

    ~GulFatima_Lab04() {
        delete[] arr;
        delete[] originalArr;  
    }

    void input() {
        cout << "Enter elements for array:" << endl;
        for (int i = 0; i < sze; i++) {
            cout << "arr[" << i << "]: ";
            cin >> arr[i];
            originalArr[i] = arr[i];  
        }
    }

    // Random input
    void randomInput(int range) {
        srand(time(0));
        for (int i = 0; i < sze; i++) {
            arr[i] = rand() % range;
            originalArr[i] = arr[i];  
        }
    }

    // Restore original array
    void restoreOriginalArray() {
        for (int i = 0; i < sze; i++) {
            arr[i] = originalArr[i];
        }
    }
    //bubble sorting
    void bubbleSort(int& c, int& s) {
        for (int i = 0; i < sze - 1; i++) {
            bool flag = false;
            for (int j = 0; j < sze - i - 1; j++) {
                c++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    s++;
                    flag = true;
                }
            }
            if (!flag) {
                break;
            }
        }
    }
    //selection sort
    void selectionSort(int& c, int& s) {
        for (int i = 0; i < sze - 1; i++) {
            int min = i;
            for (int j = i + 1; j < sze; j++) {
                c++;
                if (arr[min] > arr[j]) {
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
            s++;
        }    }
    //insertion sort
    void insertionSort(int& c, int& s) {
        for (int i = 1; i < sze; i++) {
            int value = arr[i];
            int j = i - 1;
            c++;
            while (j >= 0 && arr[j] > value) {
                arr[j + 1] = arr[j];
                j--;
                s++;
                c++;
            }
            arr[j + 1] = value;
        }
    }
    //function to print result
    void result(int bubbleComparision, int bubbleSwaps, int selectionComparision, 
            int selectionSwaps, int insertionComparision, int insertionSwaps) {
        cout << "\nNo of comparisons and swaps:" << endl;
        cout << "Bubble Sort:\n";
        cout << "\tComparisons: " << bubbleComparision << endl;
        cout << "\tSwaps: " << bubbleSwaps << endl;

        cout << "Selection Sort:\n";
        cout << "\tComparisons: " << selectionComparision << endl;
        cout << "\tSwaps: " << selectionSwaps << endl;

        cout << "Insertion Sort:\n";
        cout << "\tComparisons: " << insertionComparision << endl;
        cout << "\tSwaps: " << insertionSwaps << endl;
    }
    //function to compare sorting algo
    void performAnalysis(int bubbleComparision, int bubbleSwaps, int selectionComparision, int selectionSwaps, int insertionComparision, int insertionSwaps) {
        cout << "\nPerformance Analysis: \n";
        int best = min({ bubbleComparision, selectionComparision, insertionComparision });
        int worst = max({ bubbleComparision, selectionComparision, insertionComparision });

        cout << "Bubble Sort: " << bubbleComparision << " Comparisons, " << bubbleSwaps << " Swaps\n";
        cout << "Selection Sort: " << selectionComparision << " Comparisons, " << selectionSwaps << " Swaps\n";
        cout << "Insertion Sort: " << insertionComparision << " Comparisons, " << insertionSwaps << " Swaps\n";
        //best algo
        if (bubbleComparision == best) cout << "Bubble Sort is the best in terms of comparisons.\n";       
        if (selectionComparision == best) cout << "Selection Sort is the best in terms of comparisons.\n";
        if (insertionComparision == best) cout << "Insertion Sort is the best in terms of comparisons.\n";
        //worst algo
        if (bubbleComparision == worst) cout << "Bubble Sort is the worst in terms of comparisons.\n";
        if (selectionComparision == worst) cout << "Selection Sort is the worst in terms of comparisons.\n";
        if (insertionComparision == worst) cout << "Insertion Sort is the worst in terms of comparisons.\n";
    }
    //print functions
    void print() const {
        cout << "\nArray: " << endl;
        for (int i = 0; i < sze; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    int bubbleComparision = 0, bubbleSwaps = 0;
    int selectionComparision = 0, selectionSwaps = 0;
    int insertionComparision = 0, insertionSwaps = 0;
    cout << "Enter the size of the array: ";
    cin >> size;
    GulFatima_Lab04 arr1(size);
    int x;
    cout << "Enter: \n\t1 : Input elements for array\n\t2: Generate random array\n";
    cin >> x;
    if (x == 1) {
        arr1.input();
    }
    else {
        arr1.randomInput(10);
    }
    arr1.print();
    // Run all three sorting algorithms on the same unsorted array
    arr1.restoreOriginalArray();
    arr1.bubbleSort(bubbleComparision, bubbleSwaps);
    arr1.restoreOriginalArray();
    arr1.selectionSort(selectionComparision, selectionSwaps);
    arr1.restoreOriginalArray();
    arr1.insertionSort(insertionComparision, insertionSwaps);
    // Show the result for each sorting algorithm
    arr1.result(bubbleComparision, bubbleSwaps, selectionComparision, selectionSwaps,
                insertionComparision, insertionSwaps);
    // Sorting algorithm comparison
    int y;
    cout << "Do you want to know about the best or worst algorithms? Enter 1 for Yes, 0 for No: ";
    cin >> y;
    if (y == 1) {
        arr1.performAnalysis(bubbleComparision, bubbleSwaps, selectionComparision,
                selectionSwaps, insertionComparision, insertionSwaps);
    }
    return 0;
}
