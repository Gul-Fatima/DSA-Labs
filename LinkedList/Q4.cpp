#include <iostream>
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
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }
    // Function to insert a new node at the end of the list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    // Function to delete duplicates in a sorted linked list
    Node* deleteDuplicates(Node* head) {
        if (!head) return nullptr;

        Node* prev = head;
        Node* current = head->next;

        while (current != nullptr) {
            if (prev->data == current->data) {
                // Duplicate found, skip current
                prev->next = current->next;
                delete current;  // delete current (duplicate)
                current = prev->next;
            }
            else {
                // Move `prev` and `current` pointers forward
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
    void display(Node* node) {
        while (node != nullptr) {
            cout << node->data << "->";
            node = node->next;
        }
        cout << "Null" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(3);
    list.insert(4);
    cout << "Original list: ";
    list.display(list.head);
    list.head = list.deleteDuplicates(list.head);
    cout << "List after removing duplicates: ";
    list.display(list.head);
    return 0;
}


