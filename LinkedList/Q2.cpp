#include<iostream>
using namespace std;
class CircularQueue {
private:
	struct Node {
		int data;
		Node* next;
		Node(int x) : data(x), next(nullptr) {}
	};
	Node* front;
	Node* rear;
public:
	CircularQueue() : front(nullptr), rear(nullptr) {}
	bool isEmpty() {
		return front == nullptr;
	}
	void enqueue(int data) {
		//creating a new node 
		Node* newNode = new Node(data);
		if (isEmpty()) {
			front = rear = newNode;
			//to maintain circular structure 
			rear->next = front;
		}
		else {
			//first connecting new node to rear
			rear ->next = newNode;
			//modifying rear , so it points to new node
			rear = newNode;
			//now NN is rear so r.next = front for circular structure
			rear->next = front;
		}
	}

	void dequeue() {
		//first checking for empty
		if (isEmpty()) {
			cout << "Empty Queue" << endl;
			return;
		}
		//checking if only 1 element exist
		if (front == rear) {
			delete front;
			front = rear = nullptr;
		}
		else {
			//saving front(to be del) in temp
			Node* temp = front;
			//shifting front to nn
			front = front ->next;
			//modifying rear also so it points to new front
			rear ->next = front;
			//deleting (previous) front element
			delete temp;
		}
	}

	void display() {
		if (isEmpty()) {
			cout << "Empty Queue" << endl;
			return;
		}
		Node* temp = front;
		do {
			cout << temp ->data << " ";
			temp = temp ->next;
		} while (temp != front);
		cout <<endl;
	}
};
int main() {
	CircularQueue q;
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(7);
	q.enqueue(9);
	q.display();
	q.dequeue();
	q.display();
}