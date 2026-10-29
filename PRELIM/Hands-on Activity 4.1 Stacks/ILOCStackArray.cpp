#include <iostream>
#include <string>
using namespace std;

// ---------- STACK USING ARRAYS ----------
class ArrayStack {
private:
    char* arr;
    int capacity;
    int topIndex;

public:
    ArrayStack(int cap = 100) {
        capacity = cap;
        arr = new char[capacity];
        topIndex = -1; // -1 means empty
    }

    ~ArrayStack() {
        delete[] arr;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow." << endl;
            return;
        }
        arr[++topIndex] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow." << endl;
            return '\0';
        }
        return arr[topIndex--];
    }
};

// ---------- SYMBOL HELPERS ----------
bool isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClosing(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// ---------- BALANCE CHECKING ALGORITHM ----------
bool isBalancedArray(const string& expr) {
    ArrayStack stack(expr.length() + 1);

    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];

        // a) ignore non-symbol characters
        if (!isOpening(c) && !isClosing(c)) {
            continue;
        }

        // b) opening symbol -> push
        if (isOpening(c)) {
            stack.push(c);
        }
        // c) closing symbol
        else if (isClosing(c)) {
            // i) report error if stack is empty
            if (stack.isEmpty()) {
                cout << "Error: closing symbol '" << c
                     << "' found with no matching opening symbol." << endl;
                return false;
            }
            // ii) otherwise pop the stack
            char popped = stack.pop();

            // d) if popped symbol does not match, report error
            if (!isMatchingPair(popped, c)) {
                cout << "Error: '" << popped << "' does not match '" << c << "'." << endl;
                return false;
            }
        }
    }

    // 3) at end of input, if stack is not empty, report an error
    if (!stack.isEmpty()) {
        cout << "Error: unmatched opening symbol(s) remain." << endl;
        return false;
    }

    return true;
}

int main() {
    string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    for (const string& expr : expressions) {
        cout << "Expression: " << expr << endl;
        bool result = isBalancedArray(expr);
        cout << "Valid? " << (result ? "Y" : "N") << endl;
        cout << "-------------------------------" << endl;
    }

    return 0;
}