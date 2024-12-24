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
    Node* merge(Node* list1, Node* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        Node* mergedHead = nullptr;
        if (list1->data < list2->data) {
            mergedHead = list1;
            mergedHead->next = merge(list1->next, list2);
        }
        else {
            mergedHead = list2;
            mergedHead->next = merge(list1, list2->next);
        }
        return mergedHead;
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
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(4);
    cout << "First list: " << endl;
    list1.display(list1.head);
    LinkedList list2;
    list2.insert(1);
    list2.insert(3);
    list2.insert(4);
    cout << "Second list: " << endl;
    list2.display(list2.head);
    LinkedList mergedList;
    mergedList.head = mergedList.merge(list1.head, list2.head);

    cout << "Merged List: ";
    mergedList.display(mergedList.head);

    return 0;
}

