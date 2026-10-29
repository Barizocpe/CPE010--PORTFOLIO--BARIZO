#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]) {
    for (int j = 0; j < size; j++) {
        if (dataFind == array[j]) {
            // std::cout << "Searching is successful\n";
            return;
        }
    }
    // std::cout << "Searching is unsuccessful\n";
}

template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind) {
    int low = 0, high = arrSize - 1, middle;
    while (low <= high) {
        middle = low + (high - low) / 2;
        if (dataFind == data[middle]) {
            // std::cout << "the data was found\n";
            return;
        }
        else if (dataFind < data[middle]) {
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    // std::cout << "The data was not found\n";
}

#endif