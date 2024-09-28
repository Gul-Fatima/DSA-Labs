#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class GulFatima_Lab05 {
    int sze;
    vector<int> arr;
public:
    GulFatima_Lab05(int size) {
        sze = size;
        arr.resize(sze);
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
    void merge(int low, int mid, int high) {
        vector<int> temp(sze); // Use sze as the size of the temporary array
        int i = low;
        int j = mid + 1;
        int k = low;

        while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                temp[k] = arr[i];
                i++;
            }
            else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while (j <= high) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i];
        }
    }
    void NRMS() {
        for (int s = 1; s < sze; s *= 2) {
            for (int l = 0; l < sze - s; l += 2 * s) {
                int mid = l + s - 1;
                int right = min(l + 2 * s - 1, sze - 1);
                if (mid < right) {
                    merge(l, mid, right);
                }
            }
        }
    }
    void display() {
        for (int i = 0; i < sze; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    GulFatima_Lab05 obj(6);
    obj.randomInput(9);
    cout << "Unsorted array: " << endl;
    obj.display();
    obj.NRMS();
    cout << "Sorted array: " << endl;
    obj.display();
    return 0;
}
