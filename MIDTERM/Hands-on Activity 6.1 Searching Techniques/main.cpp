#include <iostream>
#include "node.h"
#include "suppsearchingAlgo.h"

int main(){
    std::cout << "================ PROBLEM 1 ================\n";
    std::cout << "List: [15, 18, 2, 19, 18, 0, 8, 14, 19, 14], key = 18\n\n";

    int arr1[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    const int size1 = 10;

    // Array approach
    int arrComparisons = linearSearchAR_countCompares(size1, 18, arr1);
    std::cout << "Array approach: " << arrComparisons << " comparison(s) needed to find 18.\n\n";

    // Linked list approach (same values, in order)
    Node<int>* head1 = new_node(15);
    Node<int>* n2 = new_node(18);
    Node<int>* n3 = new_node(2);
    Node<int>* n4 = new_node(19);
    Node<int>* n5 = new_node(18);
    Node<int>* n6 = new_node(0);
    Node<int>* n7 = new_node(8);
    Node<int>* n8 = new_node(14);
    Node<int>* n9 = new_node(19);
    Node<int>* n10 = new_node(14);
    head1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n5->next = n6; n6->next = n7; n7->next = n8; n8->next = n9; n9->next = n10;
    n10->next = nullptr;

    int llComparisons = linearSearchLL_countCompares(head1, 18);
    std::cout << "Linked list approach: " << llComparisons << " comparison(s) needed to find 18.\n";

    std::cout << "\n================ PROBLEM 2 ================\n";
    std::cout << "Count of repeating instances of key = 18 in the same list\n\n";

    int arrOcc = linearSearchAR_countOccurrences(size1, 18, arr1);
    std::cout << "Array approach: 18 appears " << arrOcc << " time(s).\n";

    int llOcc = linearSearchLL_countOccurrences(head1, 18);
    std::cout << "Linked list approach: 18 appears " << llOcc << " time(s).\n";

    std::cout << "\n================ PROBLEM 3 ================\n";
    std::cout << "Sorted list: [3, 5, 6, 8, 11, 12, 14, 15, 17, 18], key = 8\n\n";

    int arr2[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size2 = 10;
    binarySearchArr_traced(arr2, size2, 8);

    std::cout << "\n================ PROBLEM 4 (Recursive) ================\n";
    std::cout << "Same sorted list, key = 8, using recursive binary search\n\n";

    binarySearchArr_recursive(arr2, 0, size2 - 1, 8);

    return 0;
}