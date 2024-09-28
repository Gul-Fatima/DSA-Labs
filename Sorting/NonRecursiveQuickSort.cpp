#include<iostream>
#include<stack>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
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
    void quickSort() {
        stack<int> st;
        st.push(0);
        st.push(sze - 1);
        while (!st.empty()) {
            int hi = st.top();
            st.pop();
            int low = st.top();
            st.pop();
            if (low >= hi)
                continue;
            // Choosing the pivot : first element
            int pvt = arr[low];
            int i = low + 1;
            // Partition the array 
            for (int j = low + 1; j <= hi; j++) {
                if (arr[j] < pvt) {
                    swap(arr[i], arr[j]);
                    i++;
                }
            } 
            // Placing the pivot in the correct position
            swap(arr[low], arr[i - 1]);
            int partitionIndex = i - 1;
            // Push sub-arrays onto the stack
            if (partitionIndex - 1 > low) {
                st.push(low);
                st.push(partitionIndex - 1);
            }
            if (partitionIndex + 1 < hi) {
                st.push(partitionIndex + 1);
                st.push(hi);
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
    obj.quickSort();
    cout << "Sorted array: " << endl;
    obj.display();
    return 0;
}




