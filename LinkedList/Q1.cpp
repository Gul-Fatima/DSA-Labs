#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int d) {
		this->data = d;
		this->next = nullptr;
	}
};
class LinkedList {
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}

	void insert(int val) {
		//creating new node
		Node* newNode = new Node(val);
		//condition for empty list
		if (head == nullptr) {
			head = newNode;
		}

		else{
			//creating temp var and assigning address of head to it to traverse ll
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void deleteNode(int key) {
		Node* temp = head;
		Node* prev = nullptr;
		//condition to delete 1 node
		if (temp != nullptr && temp->data == key) {
			head = temp->next;
			delete temp;
			return;
		}
		while (temp != nullptr && temp ->data != key) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == nullptr)return;//condition for out of bound
		prev->next = temp->next; //skipping node (one that need to be deleted)
		delete temp;
	}

	bool search(int key) {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->data == key) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "Null" << endl;
	}
};

int main() {
	return 0;
}