#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        cout << "Stack Underflow";
        return -1;
    }
    
    int val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    
    return val;
}

int main() {
    string expr;
    getline(cin, expr);

    stringstream ss(expr);
    string token;

    while (ss >> token) {

        // If operand
        if (isdigit(token[0])) {
            push(stoi(token));
        }
        else {
            int b = pop();
            int a = pop();
            int result;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;

            push(result);
        }
    }

    cout << pop();

    return 0;
}
