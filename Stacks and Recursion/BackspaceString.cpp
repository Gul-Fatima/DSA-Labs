#include <iostream>
using namespace std;

class GulFatima_Lab03 {
    int size_limit = 10;
    char* stack = new char[size_limit];
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
    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return stack[top--]; 
    }
    void resize() {
        size_limit = 2 * size_limit;
        char* temp = new char[size_limit];
        for (int i = 0; i <= top; i++) {
            temp[i] = stack[i];
        }
        delete[] stack;
        stack = temp;
    }
    void push(char val) {
        if (isFull()) {
            resize();
        }
        stack[++top] = val; 
    }
    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return stack[top];
    }
    void display() {
        cout << "\nElements in stack are: " << endl;
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    string process(string s) {
        for (char i : s) {
            if (i == '#') {
                if (!isEmpty()) {
                    pop();
                }
            }
            else {
                push(i);
            }
        }
        string result = "";
        while (!isEmpty()) {
            result = pop() + result;
        }
        return result;
    }

    bool compare(string s1,string s2) {
        return process(s1) == process(s2);
    }
};

int main() {
    GulFatima_Lab03 s;
    string s1 = "ab#c";
    string t1 = "ad#c";
    cout << (s.compare(s1, t1) ? "true" : "false") << endl; 
    return 0;
}
