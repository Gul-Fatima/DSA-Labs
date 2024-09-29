#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GulFatima_Lab05 {
public:
    vector<int> nums;
    void takeInput() {
        int n;
        cout << "Enter the number of elements in the array: ";
        cin >> n;
        nums.resize(n);
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
    }
    // Function to find the length of the longest harmonious subsequence
    int findLHS() {
        // Sorting the array
        sort(nums.begin(), nums.end());
        int maxLength = 0;
        int start = 0;
        for (int i = 1; i < nums.size(); ++i) {
            // If the difference between nums[i] and nums[start] is greater than 1, moving start forward
            while (nums[i] - nums[start] > 1) {
                start++;
            }
            // If the difference is exactly 1, checking the length of this subsequence
            if (nums[i] - nums[start] == 1) {
                maxLength = max(maxLength, i - start + 1);
            }
        }
        return maxLength;
    }
};
int main() {
     GulFatima_Lab05 harr;
    harr.takeInput();
    cout << "Length of the longest harmonious subsequence is: " << harr.findLHS() << endl;
    return 0;
}
