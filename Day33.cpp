#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix;
    cin >> infix;

    stack<char> st;
    string postfix = "";

    for (char c : infix) {

        // If operand
        if (isalnum(c)) {
            postfix += c;
        }

        // If '('
        else if (c == '(') {
            st.push(c);
        }

        // If ')'
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        // Operator
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << postfix;

    return 0;
}
