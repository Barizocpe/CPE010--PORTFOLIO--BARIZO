#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <cstddef>
#include <utility>

template<typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no elements were swapped in inner loop, array is sorted
        if (!swapped) break;
    }     
}

template <typename T>
void insertionSort(T arr[], size_t arrSize) {
    for (size_t k = 1; k < arrSize; k++) {
        T temp = arr[k];
        int j = k - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

#endif