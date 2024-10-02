#include <iostream>
using namespace std;
class 	GulFatima_Lab06 {
	int* queue = new int[capacity];
	int front;
	int rear;
	int capacity;
public:
	GulFatima_Lab06(int n) {
		capacity = n;
		front = -1;
		rear = -1;
	}
	bool isFull() {
		return front == 0 && rear == capacity-1;
	}
	bool isEmpty() {
		return front == -1 && rear== -1;
	}
	//print
	void print() {
		cout << "Queue: ";
		for (int i = front; i <= rear; i++)
		{
			cout << queue[i] << " ";
		}
		cout << endl;
	}
	void enque(int val) {
		if (isFull()) {
			cout << "Queue is full.";
			return;
		}
		queue[++rear] = val;
		if (front == -1) front++;
	}
	int dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty";
			return -1;
		}
		int data = queue[front];
		front++;
		return data;
	}
	int dequeueRear() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return -1;
		}
		int data = queue[rear];
		if (front == rear) {
			front = rear = -1;
		}
		else {
			rear--;
		}
		return data;
	}
	int enqueueFront(int val) {
		if (isFull()) {
			cout << "Queue is full." << endl;
			return -1;
		}
		queue[--front] = val;
	}
	
	int size() {
		if (isEmpty()) {
			cout << "Queue is empty";
			return -1;
		}
		return (rear - front + 1);
	}
};


int main() {
	int size;
	cout << "Enter the size of queue: ";
	cin >> size;
	GulFatima_Lab06 queue(size);
	queue.enque(5);
	queue.enque(4);
	queue.enque(8);
	queue.enque(1);
	queue.print();
	queue.dequeue();
	queue.dequeue();
	cout << "The size of queue is: " << queue.size() << endl;
	queue.print();
	queue.enqueueFront(6);
	queue.print();
	queue.dequeueRear();
	queue.print();

	return 0;
}
