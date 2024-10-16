#include <iostream>
using namespace std;
class 	GulFatima_Lab06{
	int* queue = new int[capacity];
	int front;
	int rear;
	int capacity;
public:
	GulFatima_Lab06(int n) {
		capacity = n;
		front = -1;
		rear = -1;
		for (int i = 0; i < capacity; i++)
		{
			queue[i] = 0;
		}
	}	
	bool isFull() {
		return capacity == rear;
	}
	bool isEmpty() {
		return front == rear;
	}
	//print
	void print() {
		cout << "Queue: ";
		for (int i = front; i <=rear; i++)
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
	int frontElement() {
		if (isEmpty()) {
			cout << "Queue is empty";
			return -1;
		}
		return queue[front];
	}
	int rearElement() {
		if (isEmpty()) {
			cout << "Queue is empty";
			return -1;
		}
		return queue[rear];
	}
	int size() {
		if (isEmpty()) {
			cout << "Queue is empty";
			return - 1;
		}
		return rear - front;
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
	cout << "Front elemnt of queue is :" << queue.frontElement()<< endl;
	cout << "Rear elemnt of queue is :" << queue.rearElement()<< endl;
	cout << "The size of queue is: " << queue.size()<< endl;
	queue.print();

	return 0;
}
