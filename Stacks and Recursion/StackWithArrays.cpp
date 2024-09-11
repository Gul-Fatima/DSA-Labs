#include <iostream>
using namespace std;

class GulFatima_Lab03 {
    int size_limit = 10;
    int* stack = new int[size_limit];
    int top = -1;
public:
    int size() const {
        return top + 1;
    }
    bool isFull() const {
        return top + 1 == size_limit;
    }
    bool isEmpty() const {
        return top == -1;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        int temp = stack[top];
        top--;
        cout << "Element deleted from the stack." << endl;
        return temp;
    }
    void resize() {
        size_limit = 2 * size_limit;
        int* temp = new int[size_limit];
        for (int i = 0; i <= top; i++) {
            temp[i] = stack[i];
        }
        delete[] stack;
        stack = temp;
    }
    void push(int val) {
        if (isFull()) {
            resize();
        }
        ++top;
        stack[top] = val;
        cout << "Element added to the stack." << endl;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stack[top];
    }
    void display() {
        cout << "\nElements in stack are: " << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
    }
};

int main() {
    GulFatima_Lab03 s;
    s.push(7);
    s.push(4);
    s.push(8);
    s.pop();
    cout << "Element at the top is: "<< s.peek()<< endl;
    s.display();
    return 0;
}
