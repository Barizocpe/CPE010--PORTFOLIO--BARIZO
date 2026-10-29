#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main () {
    //create an array with unsorted list
    int unsortedArr[maxSize] = {};

    //use time (0) as the seed
    srand(time(0));
    //populate the array
    for (int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }
    //display the randomly generated array
    std::cout<<"Unsorted Arr: \n";
    displayArr(unsortedArr);

    std::cout<<"\nBubble Sort: \n";
    bubbleSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    std::cout<<"\nSelection Sort: \n";
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    std::cout<<"\nInsertion Sort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
}

void displayArr(int arr[]) {
    for(int i = 0; i < maxSize; i++) {
        std::cout<<arr[i]<< " ";
    }
    std::cout<<std::endl;
}
