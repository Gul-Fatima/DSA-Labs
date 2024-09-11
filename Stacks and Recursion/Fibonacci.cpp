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
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
    }
    int fibonacci(int term) {
        if (term == 0 || term == 1) {
            return term;
        }
        return fibonacci(term - 1) + fibonacci(term - 2);
    }
    void gen_fib(int limit) {
        for (int i = 1; i <= limit; i++) {
            push(fibonacci(i)); 
        }
        cout << "\nElements of fibonacci series: "<< endl;
        while (top >= 0) {
            cout << pop() << " ";
        }    }
};

int main() {
    GulFatima_Lab03 s;
    s.gen_fib(5);

    return 0;
}
