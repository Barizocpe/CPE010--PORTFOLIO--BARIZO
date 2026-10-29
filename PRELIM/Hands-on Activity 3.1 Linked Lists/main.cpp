#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main () {
    // create a list "C P E"

    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    //traversal
    std::cout<< "Testing the DLL Traversal"<<std::endl;
    dllTraverse(head);

    //testing insert at the head
    std::cout<<"Testing the insertion at the head node\n";
    dllInsertHead('X', &head);
    dllTraverse(head);

    //testing the insertion at the end
    std::cout<<"Testing the insertion at the end\n"<<std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

    // GENERAL INSERT 
    std::cout<<"\nTesting the General Insertion\n"<<std::endl;
    dllGenInsert('L', second);
    dllTraverse(head);

    // DELETE A NODE
    std::cout<<"\nTesting the deletion of a node\n"<<std::endl;
    dllDeleteNode('L', &head);
    dllTraverse(head);

    return 0;
}