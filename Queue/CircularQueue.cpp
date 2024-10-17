#include <iostream>
using namespace std;
class GulFatima_Lab06 {
    int* queue;
    int front;
    int rear;
    int capacity;
    int count;
public:
    GulFatima_Lab06(int n) {
        capacity = n;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        count = 0;
        for (int i = 0; i < capacity; i++) {
            queue[i] = 0;
        }
    }
    ~GulFatima_Lab06() {
        delete[] queue;
    }
    bool isFull() {
        return count == capacity;
    }
    bool isEmpty() {
        return count == 0;
    }
    // Print
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << endl;
    }
    void enque(int val) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = val;
        count++;
        if (front == -1) front = 0;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int data = queue[front];
        if (front == rear) {
            front = rear = -1;  // Queue is now empty
        }
        else {
            front = (front + 1) % capacity;
        }
        count--;
        return data;
    }
    int size() {
        return count;
    }
    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queue[front];
    }
    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queue[rear];
    }
};
int main() {
    int size;
    cout << "Enter the size of queue: ";
    cin >> size;
    GulFatima_Lab06 queue(size);
    queue.enque(5);
    queue.enque(10);
    queue.enque(15);
    queue.enque(20);
    queue.print();
    cout << "The size of queue is: " << queue.size() << endl;
    queue.dequeue();
    queue.dequeue();
    cout << "The size of queue is: " << queue.size() << endl;
    queue.print();
    return 0;
}
