#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) :data(val), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    void swap(Node* a, Node* b) {
        if (!a || !b)return;
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
public:
    DoublyLinkedList() :head(nullptr), tail(nullptr) {}
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void sort() {
        if (!head)return;
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp != nullptr && temp->next != nullptr) {
                if (temp->data > temp->next->data) {
                    swap(temp, temp->next);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }
    void concatenate(DoublyLinkedList& other) {
        if (other.head == nullptr)return;
        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        }
        else {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
    }
};
int main() {
    DoublyLinkedList L;
    for (int i = 2;i <= 10;i += 2)L.insert(i);
    DoublyLinkedList M;
    for (int i = 1;i <= 9;i += 2)M.insert(i);
    DoublyLinkedList N;
    N.concatenate(L);
    N.concatenate(M);
    cout << "List N (before sorting): ";
    N.display();
    N.sort();
    cout << "List N (after sorting): ";
    N.display();
    return 0;
}

