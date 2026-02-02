#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char *arr;
    int capacity;
    int top;

public:
    Stack(int s) {
        arr = new char[s];
        capacity = s;
        top = -1;
    }

    bool isFull() {
        return (top + 1) == capacity;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow.\n";
            return;  // prevent adding beyond limit
        }
        arr[top] = c;
        top++;
    }

    bool isEmpty() {
        return top == -1;
    }

    char pop(){
        if (isEmpty()) {
            cout << "Stack Underflow.\n";
            return '\0';
        }
        return arr[top];
        top--;
    }

    ~Stack() {
        delete[] arr;
    }
};

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool checkParenthesis(string exp) {
    Stack s(60); // create stack of required size

    for (int i = 0; i<=60; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false; // closing bracket without matching opening
            }

            char top = s.pop();

            if (!isMatching(top, ch)) {
                return false; // mismatched brackets
            }
        }
    }

    return s.isEmpty(); // if stack empty ? all matched
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (checkParenthesis(exp))
        cout << "Parentheses are balanced.\n";
    else
        cout << "Parentheses are NOT balanced.\n";

    return 0;
}