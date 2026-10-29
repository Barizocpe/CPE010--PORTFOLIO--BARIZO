#include <iostream>
#include "supplementary.h"

int main() {

    // Step 1: Implement a binary search tree with the given values
    // Values: 2, 3, 9, 18, 0, 1, 4, 5
    // First value (2) becomes the root; the rest are inserted after.
    BinarySearchTree<int>* root = new BinarySearchTree<int>(2);

    root->insert(3);
    root->insert(9);
    root->insert(18);
    root->insert(0);
    root->insert(1);
    root->insert(4);
    root->insert(5);

    // Step 3: Compare the different traversal methods

    std::cout << "In-order Traversal: ";
    root->inOrder();
    std::cout << std::endl;

    std::cout << "\nPre-order Traversal: ";
    root->preOrder();
    std::cout << std::endl;

    std::cout << "\nPost-order Traversal: ";
    root->postOrder();
    std::cout << std::endl;

    return 0;
}