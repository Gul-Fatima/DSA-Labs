#include <iostream>
using namespace std;

class GulFatima_Lab06 {
    int* queue;
    int front;
    int rear;
    int size;
    int actualsize;
public:
    GulFatima_Lab06(int n) {
        actualsize = n;
        size = n;
        queue = new int[size];
        front = 0;
        rear = size - 1;

        // Initialize the queue with friend numbers from 1 to n
        for (int i = 0; i < size; ++i) {
            queue[i] = i + 1;
        }
    }
    ~GulFatima_Lab06() {
        delete[] queue;
    }
    bool isEmpty() {
        return size == 0;
    }
    int dequeueAt(int index) {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = queue[index];
        // Shifting elements to fill the gap
        for (int i = index; i < size - 1; ++i) {
            queue[i] = queue[i + 1];        }
        size--;
        return data;
    }

    int process(int k) {
        int index = 0;
        while (size > 1) {
            index = (index + k - 1) % size;
            cout << "Friend " << queue[index] << " is eliminated." << endl;
            dequeueAt(index);
        }
        return queue[0]; // after all the elemnts are eliminated and only one element exist it would auto be at a[0]
    }
};

int main() {
    int size, k;
    cout << "Enter the number of friends: ";
    cin >> size;
    cout << "Enter the count: ";
    cin >> k;
    GulFatima_Lab06 queue(size);
    cout << "The winner is friend number: " << queue.process(k);

    return 0;
}
