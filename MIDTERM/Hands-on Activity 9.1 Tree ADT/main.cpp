#include <iostream>
#include "BST.h"

int main(){
    //root node:
    Tree<char> tree('A');

    //insert child nodes of A
    Tree<char>* B = tree.addChild('B');
    Tree<char>* C = tree.addChild('C');
    Tree<char>* D = tree.addChild('D');
    Tree<char>* E = tree.addChild('E');
    Tree<char>* F = tree.addChild('F');
    Tree<char>* G = tree.addChild('G');

    //child of D
    Tree<char>* H = D->addChild('H');

    //children of E
    Tree<char>* I = E->addChild('I');
    Tree<char>* J = E->addChild('J');

    //children of F
    Tree<char>* K = F->addChild('K');
    Tree<char>* L = F->addChild('L');
    Tree<char>* M = F->addChild('M');

    //child of G
    Tree<char>* N = G->addChild('N');

    //children of J
    Tree<char>* P = J->addChild('P');
    Tree<char>* Q = J->addChild('Q');

    //traversing
    std::cout<< "preorder: ";
    tree.preOrder();
    std::cout<<std::endl;

    std::cout<< "inorder: ";
    tree.inOrder();
    std::cout<<std::endl;

    std::cout<< "postorder: ";
    tree.postOrder();
    std::cout<<std::endl;

    std::cout << std::endl;
    //Table 9-5
    std::cout << "Find H using preorder: ";
    tree.findData(1, 'H');
    std::cout << std::endl;

    std::cout << "Find I using inorder: ";
    tree.findData(2, 'I');
    std::cout << std::endl;

    std::cout << "Find Q using postorder: ";
    tree.findData(3, 'Q');
    std::cout << std::endl;

    std::cout << "Find Z using preorder: ";
    tree.findData(1, 'Z');
    std::cout << std::endl;

    std::cout << std::endl;
    //add O as a child of G
    Tree<char>* O = G->addChild('O');

    std::cout << "Find O using preorder: ";
    tree.findData(1, 'O');
    std::cout << std::endl;

    std::cout << "Find O using inorder: ";
    tree.findData(2, 'O');
    std::cout << std::endl;

    std::cout << "Find O using postorder: ";
    tree.findData(3, 'O');
    std::cout << std::endl;

    return 0;
}