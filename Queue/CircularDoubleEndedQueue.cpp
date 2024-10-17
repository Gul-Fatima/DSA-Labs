#include <iostream>
using namespace std;
class 	GulFatima_Lab07 {
	int* queue;
	int front;
	int rear;
	int capacity;
public:
	GulFatima_Lab07(int n) {
		capacity = n;
		queue = new int[n];
		front = -1;
		rear = -1;
		
	}
	bool isFull() {
		return (front == 0 && rear == capacity - 1)|| (front == rear +1);
	}
	bool isEmpty() {
		return front == -1;
	}
	void insertRear(int val) {
		if (isFull()) {
			cout << "Queue is full";
			return;
		}
		if (front == -1) {
			front = rear = 0;
		}
		else if (rear == capacity - 1) {
			rear = 0;
		}
		else {
			rear++;
		}
		queue[rear] = val;
	}
	void deleteFront() {
		if (isEmpty()) {
			cout << "Queue is empty";
			return;
		}
		if (front == rear)
			front = rear = -1;
		else if (front == capacity - 1)
			front = 0;
		else
			front++;
		
	}
	int getFront() {
		if (isEmpty()) {
			cout << "Queue is empty";
			return -1;
		}
		return queue[front];
	}
	void deleteRear() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return;
		}
		if (front == rear)
			front = rear = -1;
		else if (rear == 0) {
			rear = capacity-1;
		}
		else {
			rear--;
		}
	}
	int getRear() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return -1;
		}
		return queue[rear];
		
	}
	void insertFront(int val) {
		if (isFull()) {
			cout << "Queue is full." << endl;
			return ;
		}
		if (front == -1)
			front = rear = 0;
		else if (front == 0)
			front = capacity - 1;
		else
			front--;
		queue[front] = val;
	}
	void display() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Queue is:\t";
		if (rear >= front) {
			for (int i =front; i <=rear; i++)
			{
				cout << queue[i] << " ";
			}
		}
		
		else {
			for (int i = front; i <capacity; i++)
			{
				cout << queue[i] << " ";
			}
			for (int i = 0; i <= rear; i++)
			{
				cout << queue[i] << " ";
			}
		}
		cout << endl;
	}
};


int main() {
	int size;
	cout << "Enter the size of queue: ";
	cin >> size;
	GulFatima_Lab07 queue(size);
	queue.insertRear(5);
	queue.display();
	queue.insertRear(4);
	queue.display();
	queue.insertRear(8);
	queue.display();
	queue.insertFront(1);
	queue.display();
	queue.deleteRear();
	queue.display();
	queue.deleteFront();
	cout << "Element at front:\t" << queue.getFront() << endl;
	cout << "Element at rear:\t" << queue.getRear() << endl;
	return 0;
}
