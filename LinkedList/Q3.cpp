#include<iostream>
using namespace std;
class Stack {
private:
	struct Node {
		int data;
		Node* next;
		Node(int val) : data(val), next(nullptr) {}
	};
	Node* top;
public:
	//constructor
	Stack() : top(nullptr) {}
	//function for empty
	bool isEmpty() {
		return top == nullptr;  //top == -1
	}
	//note : in stack imp by ll, the next points downward the stack
	void push(int val) {
		///creating new node
		Node* newNode = new Node(val);
		//new node made points to top(last node that was top on the stack)
		newNode->next = top;
		//now changing top to point to new node(on the top of stack)
		top = newNode;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Empty " << endl;
			return;
		}
		//deleting top; so first saving it in temp node
		Node* temp = top;
		//modifying top to decreement  ; top--
		top = top->next;
		//now pop
		delete temp;
	}
	void display() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		Node* temp = top;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp ->next;
		}
		cout << endl;
	}
};
int main() {
	Stack s;
	s.push(3);
	s.push(5);
	s.push(3);
	s.push(4);
	s.display();
	s.pop();
	s.display();
	return 0;
}