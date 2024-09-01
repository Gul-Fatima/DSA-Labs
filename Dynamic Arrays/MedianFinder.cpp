#include <iostream>
using namespace std;

class MedianFinder {
    int* nums;
    int size;
    int capacity;
public:
    // Constructor
    MedianFinder() : size(0), capacity(1), nums(new int[capacity]) {}

    //// Destructor
    //~MedianFinder() {
    //    delete[] nums;
    //}

    void addNum(int value) {
        if (size == capacity) {
            int* temp = new int[capacity * 2];
            capacity *= 2;

            // Copy elements from nums to temp
            for (int i = 0; i < size; i++) {
                temp[i] = nums[i];
            }
            //delete[] nums;
            nums = temp;
        }

        // Inserting value in a sorted order
        int i = size - 1;
        while (i >= 0 && nums[i] > value) {
            nums[i + 1] = nums[i];
            i--;
        }
        nums[i + 1] = value;
        size++;
    }

    double findMedian() {
        if (size % 2 != 0) {
            return nums[size / 2];
        }
        else {
            return (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
        }
    }
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl; // Output: 1.5
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl; // Output: 2
    return 0;
}
