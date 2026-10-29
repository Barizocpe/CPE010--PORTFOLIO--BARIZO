#ifndef TREE_H
#define TREE_H

#include <iostream>

template <typename T>
class Tree
{
private:
    // create a key
    T key;
    Tree<T>* firstChild;
    Tree<T>* nextChild;

public:
    // constructor
    Tree(T value);

    // add child
    Tree<T>* addChild(T value);

    // traversing
    void preOrder();
    void postOrder();
    void inOrder();

    // searching
    void findData(int CHOICE, T KEY);
};

// Constructor
template <typename T>
Tree<T>::Tree(T value)
{
    key = value;
    firstChild = nullptr;
    nextChild = nullptr;
}
// Add child
template <typename T>
Tree<T>* Tree<T>::addChild(T value)
{
    Tree<T>* newNode = new Tree<T>(value);


    if (firstChild == nullptr){
        firstChild = newNode;
    } else {
        Tree<T>* temp = firstChild;
        while (temp->nextChild != nullptr){
            temp = temp->nextChild;
        }
        temp->nextChild = newNode;
    }

    return newNode;
}


// Preorder
template <typename T>
void Tree<T>::preOrder(){
    // current node
    std::cout << key << " ";
    // first child
    if(firstChild != nullptr){
        firstChild->preOrder();
    }
    if(nextChild != nullptr){
        nextChild->preOrder();
    }
}


// Inorder
template <typename T>
void Tree<T>::inOrder(){
    // first child
    if(firstChild != nullptr){
        firstChild->inOrder();
    }
    // current node
    std::cout << key << " ";
    if(nextChild != nullptr){
        nextChild->inOrder();
    }
}


// Postorder
template <typename T>
void Tree<T>::postOrder(){
    Tree<T>* child = firstChild;

    while(child != nullptr){
        child->postOrder();
        child = child->nextChild;
    }
    // current node
    std::cout << key << " ";
}

// Find Data
template <typename T>
void Tree<T>::findData(int CHOICE, T KEY){

    // preorder
    if(CHOICE == 1){

        if(key == KEY){
            std::cout << KEY << " was found!";
            return;
        }
        // first child
        if(firstChild != nullptr){
            firstChild->findData(CHOICE, KEY);
        }
        if(nextChild != nullptr){
            nextChild->findData(CHOICE, KEY);
        }
    }


    // inorder
    else if(CHOICE == 2){
        // first child
        if(firstChild != nullptr){
            firstChild->findData(CHOICE, KEY);
        }
        // current node
        if(key == KEY){
            std::cout << KEY << " was found!";
            return;
        }
        if(nextChild != nullptr){
            nextChild->findData(CHOICE, KEY);
        }
    }

    // postorder
    else if(CHOICE == 3){
        // first child
        if(firstChild != nullptr){
            firstChild->findData(CHOICE, KEY);
        }
        if(nextChild != nullptr){
            nextChild->findData(CHOICE, KEY);
        }
        // current node
        if(key == KEY){
            std::cout << KEY << " was found!";
            return;
        }
    }
}

#endif