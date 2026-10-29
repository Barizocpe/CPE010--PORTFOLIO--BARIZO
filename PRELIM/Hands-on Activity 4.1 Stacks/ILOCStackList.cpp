#include <iostream>
#include <string>
using namespace std;

// ---------- STACK USING LINKED LISTS ----------
class Node {
public:
    char data;
    Node* next;
};

class ListStack {
private:
    Node* head;

public:
    ListStack() {
        head = nullptr;
    }

    ~ListStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(char c) {
        Node* newNode = new Node();
        newNode->data = c;
        newNode->next = head;
        head = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow." << endl;
            return '\0';
        }
        Node* temp = head;
        char val = temp->data;
        head = head->next;
        delete temp;
        return val;
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
bool isBalancedList(const string& expr) {
    ListStack stack;

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
        bool result = isBalancedList(expr);
        cout << "Valid? " << (result ? "Y" : "N") << endl;
        cout << "-------------------------------" << endl;
    }

    return 0;
}