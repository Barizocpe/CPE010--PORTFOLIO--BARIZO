#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Recursive preorder
void preorder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";   // visit root
    preorder(node->left);       // go deep left
    preorder(node->right);      // then right
}

// Iterative preorder (uses a stack, like the DFS in the activity)
void preorderIterative(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* cur = s.top();
        s.pop();
        cout << cur->val << " ";
        if (cur->right) s.push(cur->right);  // push right first
        if (cur->left)  s.push(cur->left);   // so left is popped first
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    preorder(root);            cout << endl;   // 1 2 4 5 3
    preorderIterative(root);   cout << endl;   // 1 2 4 5 3
    return 0;
}