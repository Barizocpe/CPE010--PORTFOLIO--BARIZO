#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo2.h"

int main() {
    const int maxSize = 100;
    int original[maxSize];

    // generate 100 random, unsorted values
    srand(time(0));
    for (int i = 0; i < maxSize; i++) {
        original[i] = rand() % 1000;
    }

    std::cout << "Unsorted Arr" << std::endl;
    printArray(original, maxSize);

    //  Shell Sort
    int shellArr[maxSize];
    for (int i = 0; i < maxSize; i++) {
        shellArr[i] = original[i];
    }
    shellSort(shellArr, maxSize);
    std::cout << "\nShell Sort" << std::endl;
    printArray(shellArr, maxSize);

    //  Merge Sort
    int mergeArr[maxSize];
    for (int i = 0; i < maxSize; i++) {
        mergeArr[i] = original[i];
    }
    mergeSort(mergeArr, 0, maxSize - 1);
    std::cout << "\nMerge Sort" << std::endl;
    printArray(mergeArr, maxSize);

    //  Quick Sort
    int quickArr[maxSize];
    for (int i = 0; i < maxSize; i++) {
        quickArr[i] = original[i];
    }
    quickSort(quickArr, 0, maxSize - 1);
    std::cout << "\nQuick Sort" << std::endl;
    printArray(quickArr, maxSize);

    return 0;
}