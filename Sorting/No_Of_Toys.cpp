#include <iostream>
using namespace std;

class GulFatima_Lab04 {
    int* arr;
    int sum = 0, noOfToys = 0, sze;

public:
    GulFatima_Lab04(int size) {
        sze = size;
        arr = new int[sze];
        for (int i = 0; i < sze; i++) {
            arr[i] = 0;
        }
    }

    ~GulFatima_Lab04() {
        delete[] arr;
    }
    void input() const{
        cout << "Enter elements for array:" << endl;
        for (int i = 0; i < sze; i++) {
            cout << "arr[" << i << "]: ";
            cin >> arr[i];
        }
    }
    void sort() {
        for (int i = 0; i < sze - 1; i++) {
            bool flag = false;
            for (int j = 0; j < sze - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    flag = true;
                }
            }
            if (!flag) {
                break;
            }
        }
    }
    void print()const {
        for (int i = 0; i < sze; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int count(int k) {
        sort();  
        for (int i = 0; i < sze; i++) {
            if (sum + arr[i] <= k) {
                sum += arr[i];
                noOfToys++;
            }
            else {
                break;
            }
        }
        return noOfToys;
    }
};

int main() {
    int size, budget;
    cout << "Enter the size of the array: ";
    cin >> size;
    GulFatima_Lab04 obj(size);
    obj.input();  
    cout << "Enter the budget: ";
    cin >> budget;
    cout << "Number of toys that can be bought: " << obj.count(budget) << endl;
    return 0;
}
