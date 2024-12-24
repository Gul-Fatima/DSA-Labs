#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class LinkedList {
private:
    ListNode* head;

    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;

        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
public:
    LinkedList() : head(nullptr) {}
    // Function to check if the linked list is a palindrome
    bool isPalindrome() {
        if (!head || !head->next) return true;
        // Find the middle of the list (Tortoise and Hare method)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse the second half
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;
        // Compare the first and second halves
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
    // Function to insert a new node at the end
    void insert(int val) {
        if (!head) {
            head = new ListNode(val);
            return;
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new ListNode(val);
    }
    // Function to print the linked list
    void printList() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);
    list.insert(4);
    cout << "Original list: ";
    list.printList();
    if (list.isPalindrome()) {
        cout << "The list is a palindrome." << endl;
    }
    else {
        cout << "The list is not a palindrome." << endl;
    }
    cout << endl;
    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(2);
    list2.insert(1);
    cout << "Original list: ";
    list2.printList();
    if (list2.isPalindrome()) {
        cout << "The list is a palindrome." << endl;
    }
    else {
        cout << "The list is not a palindrome." << endl;
    }
        return 0;
}


