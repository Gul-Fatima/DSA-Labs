#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;  // If the list is empty, set both head and tail to the new node
        }
        else {
            tail->next = newNode;  // Link the new node at the end
            newNode->prev = tail;  // Set the previous pointer of the new node
            tail = newNode;        // Move the tail to the new node
        }
    }
    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // Function to concatenate another list to the current list
    void concatenate(DoublyLinkedList& other) {
        if (other.head == nullptr) {
            return;  // If the other list is empty, do nothing
        }
        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        }
        else {
            tail->next = other.head;   // Link the tail of the current list to the head of the other list
            other.head->prev = tail;   // Set the previous pointer of the other list's head
            tail = other.tail;         // Update the tail to be the tail of the other list
        }
    }
};
int main() {
    // Create list L (even numbers from 2 to 10)
    DoublyLinkedList L;
    for (int i = 2; i <= 10; i += 2) {
        L.insert(i);
    }
    // Create list M (odd numbers from 1 to 9)
    DoublyLinkedList M;
    for (int i = 1; i <= 9; i += 2) {
        M.insert(i);
    }
    // Display the lists
    cout << "List L : ";
    L.display();
    cout << "List M: ";
    M.display();
    // Create list N by concatenating L and M
    DoublyLinkedList N;
    N.concatenate(L);
    N.concatenate(M);
    cout << "List N : ";
    N.display();
    return 0;
}
