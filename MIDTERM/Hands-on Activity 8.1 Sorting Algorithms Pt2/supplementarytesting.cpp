#include <iostream>
#include "sortingAlgo2.h"

int main() {
    int arr[] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int n = 15;

    std::cout << "Original array:\n";
    printArray(arr, n);

    //partition once, using quick sort's partition method
    int pivotIndex = partition(arr, 0, n - 1);

    std::cout << "\nAfter one partition (pivot = " << arr[pivotIndex]
               << ", now at index " << pivotIndex << "):\n";
    printArray(arr, n);

    //sort the left and right sub-lists using SHELL SORT instead of quick sort
    if (pivotIndex - 1 > 0)
        shellSort(arr, pivotIndex);          // left sub-list: arr[0 .. pivotIndex-1]
    if (n - (pivotIndex + 1) > 1)
        shellSort(arr + pivotIndex + 1, n - pivotIndex - 1); // right sub-list

    std::cout << "\nFinal array after sorting sub-lists with Shell Sort:\n";
    printArray(arr, n);

    return 0;
}