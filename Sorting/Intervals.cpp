#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class GulFatima_Lab05 {
    vector<vector<int>> interval;
 public:
    GulFatima_Lab05(int n) {
        interval.resize(n, vector<int>(2)); // Initialize eachsub-vector with size 2
    }
    void input() {
        for (int i = 0; i < interval.size(); i++) {
            cout << "Enter interval " << i + 1 << " (start end): ";
            cin >> interval[i][0] >> interval[i][1];
            // check if input is valid
            while (interval[i][0] > interval[i][1]) {
                cout << "Invalid input. Start should be less than or equal to end.PLease re - enter interval " << i + 1 << ": ";
                cin >> interval[i][0] >> interval[i][1];
            }
        }
    }
    void display(const vector<vector<int>>& toDisplay) {
        for (int i = 0; i < toDisplay.size(); i++) {
            cout << "[" << toDisplay[i][0] << ", " << toDisplay[i][1] << "]";
            if (i < toDisplay.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    // Merge function
    vector<vector<int>> mergeIntervals() {
        // Sort the whole interval array based on interval[0]:
        sort(interval.begin(), interval.end());
        // Creating a temp array merged to save the merged intervals
        vector<vector<int>> merged;
        merged.push_back(interval[0]);
        for (int i = 1; i < interval.size(); i++) {
            // Checking overlapping:
            if (interval[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], interval[i][1]);
            }
            else {
                merged.push_back(interval[i]);
            }
        }
        return merged;
    }

    vector<vector<int>> getIntervals() const {
        return interval;
    }
};
int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
     // Ensure that the input is a valid positive integer
    while (n <= 0) {
        cout << "Please enter a valid number of intervals: ";
        cin >> n;
    }
    GulFatima_Lab05 obj(n);
    obj.input();
    // Display original intervals
    cout << "Original intervals: ";
    obj.display(obj.getIntervals());
    // Merge intervals and display
    vector<vector<int>> mergedIntervals = obj.mergeIntervals();
    cout << "Merged intervals: ";
    obj.display(mergedIntervals);
    return 0;
}
