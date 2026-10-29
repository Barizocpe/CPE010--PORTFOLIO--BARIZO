#include <iostream>
#include <thread>
#include "sortingAlgo2.h"

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10, 55, 1, 67, 22, 90, 14, 5, 76, 31};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mid = (n - 1) / 2;

    std::cout << "Before sorting:" << std::endl;
    printArray(arr, n);

    // one thread per half
    std::thread t1(mergeSort<int>, arr, 0, mid);
    std::thread t2(mergeSort<int>, arr, mid + 1, n - 1);
    t1.join();
    t2.join();

    // combine the two sorted halves
    merge(arr, 0, mid, n - 1);

    std::cout << "After sorting:" << std::endl;
    printArray(arr, n);

    return 0;
}
