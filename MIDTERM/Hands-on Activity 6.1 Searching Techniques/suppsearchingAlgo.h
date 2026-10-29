#include <iostream>
#include "node.h"

#ifndef SUPPSEARCHINGALGO_H
#define SUPPSEARCHINGALGO_H


//  Base searching algorithms (from Activity 6)


template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){
    int i = 0;
    while(i < size) {
        if(dataFind == array[i]) {
            std::cout << "Searching is successful\n";
            return;
        }
        i++;
    }
    std::cout << "Searching is unsuccessful\n";
}

template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind){
    while (nodes != nullptr){
        if(nodes->data == dataFind){
            std::cout << "The data:  " << nodes->data << " was found successfully.\n";
            return;
        }
        nodes = nodes->next;
    }
    std::cout << "Searching is unsuccessful.\n";
}

template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    while(low <= high){
        middle = (int)((low + high) / 2);
        if(dataFind == data[middle]){
            std::cout << "the data was found\n";
            return;
        }
        else if(dataFind < data[middle]){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }
    std::cout << "The data was not found\n";
}

template<typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end){
    Node<T>* slow = start;
    Node<T>* fast = start;
    while (fast != end && fast->next != end){
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


// SUPPLEMENTARY ACTIVITY


// Problem 1: sequential search that RETURNS the number of comparisons
template <typename T>
int linearSearchAR_countCompares(int size, T dataFind, T array[]){
    int comparisons = 0;
    for(int i = 0; i < size; i++){
        comparisons++;                 // one comparison per element checked
        if(array[i] == dataFind){
            std::cout << "Searching is successful \n";
            return comparisons;
        }
    }
    std::cout << "Searching is unsuccessful \n";
    return comparisons;
}

template <typename T>
int linearSearchLL_countCompares(Node<T> *nodes, T dataFind){
    int comparisons = 0;
    while(nodes != nullptr){
        comparisons++;
        if(nodes->data == dataFind){
            std::cout << "The data: " << nodes->data << " was found successfully (linked list)\n";
            return comparisons;
        }
        nodes = nodes->next;
    }
    std::cout << "Searching is unsuccessful (linked list)\n";
    return comparisons;
}

// Problem 2: sequential search that RETURNS the count of repeating instances of k 
template <typename T>
int linearSearchAR_countOccurrences(int size, T k, T array[]){
    int occurrences = 0;
    for(int i = 0; i < size; i++){
        if(array[i] == k){
            occurrences++;
        }
    }
    return occurrences;
}

template <typename T>
int linearSearchLL_countOccurrences(Node<T> *nodes, T k){
    int occurrences = 0;
    while(nodes != nullptr){
        if(nodes->data == k){
            occurrences++;
        }
        nodes = nodes->next;
    }
    return occurrences;
}

// Problem 3: binary search on an array, tracing every iteration
template <typename T>
void binarySearchArr_traced(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    int iteration = 1;
    while(low <= high){
        middle = (low + high) / 2;
        std::cout << "Iteration " << iteration << ": low=" << low
                   << " high=" << high << " mid=" << middle
                   << " (data[mid]=" << data[middle] << ")\n";
        if(dataFind == data[middle]){
            std::cout << "Search element is found at index " << middle << "!\n";
            return;
        }
        else if(dataFind < data[middle]){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
        iteration++;
    }
    std::cout << "Search element is not found\n";
}

// Problem 4: recursive binary search on an array
template <typename T>
void binarySearchArr_recursive(T data[], int low, int high, T dataFind, int iteration = 1){
    if(low > high){
        std::cout << "Search element is not found\n";
        return;
    }
    int middle = (low + high) / 2;
    std::cout << "Iteration " << iteration << ": low=" << low
               << " high=" << high << " mid=" << middle
               << " (data[mid]=" << data[middle] << ")\n";
    if(dataFind == data[middle]){
        std::cout << "Search element is found at index " << middle << "!\n";
        return;
    }
    else if(dataFind < data[middle]){
        binarySearchArr_recursive(data, low, middle - 1, dataFind, iteration + 1);
    }
    else{
        binarySearchArr_recursive(data, middle + 1, high, dataFind, iteration + 1);
    }
}

#endif