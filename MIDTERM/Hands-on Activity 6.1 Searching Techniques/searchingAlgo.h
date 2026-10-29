#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALHO_H


/*








*/

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){

    //while loop
    int i = 0;

    while(i < size) {
        if(dataFind == array[i]) {
            std::cout<<"Searching is successful\n";
            return;
        }
        i++;
    }
    std::cout<<"Searching is unsuccessful\n";


    for (int j = 0; j < size; j++){
        if(dataFind == array[j]) {
            std::cout<<"Searching is successful\n";
            return;
        }
    }
}



template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind){
    //repeat the loop until the current node is not NULL

    while (nodes != nullptr){

        //check if the time = current node data
        if(nodes->data == dataFind){
            std::cout<<"The data:  " << nodes->data << " was found successfully.\n";
            return;
        }
        //move on to the next noide
        nodes = nodes ->next;
    }
    //display unsucessful
    std::cout << "Searching is unsuccessful.\n";
    
}

//Binary Search
template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    while(low <= high){
        middle = (int)((low + high) / 2);
        if(dataFind == data[middle]){
            std::cout<<"the data was found\n";
            return;
        }
        else if(dataFind < data[middle]){
            high = middle -1;
        }
        else{
            low = middle+1;
        }
    }

    std::cout<<"The data was not found\n";
}

template<typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != end && fast->next!= end){
        slow = slow->next;

        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind) {
    Node<T>* last = nullptr;
    
    while (start != last) {
        Node<T>* middle = getMiddle(start, last);

        if (middle->data == dataFind) {
            std::cout << "Data found\n";
            return;
        }
        else if (middle->data > dataFind) {
            last = middle;
        }
        else {
            start = middle->next; 
        }
    }

    std::cout << "Data not found\n";
}

#endif