#ifndef SORTINGALGO2_H
#define SORTINGALGO2_H
#include <iostream>
#include <vector>

// Prints all elements of the array, 10 per line
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) std::cout << std::endl;
    }
    if (n % 10 != 0) std::cout << std::endl;
}

// Shell Sort
template <typename T>
void shellSort(T arr[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            T temp = arr[i];
            int j = i;
            while (j >= interval && arr[j - interval] > temp) {
                arr[j] = arr[j - interval];
                j -= interval;
            }
            arr[j] = temp;
        }
    }
}

// Merge Sort
template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    std::vector<T> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);          // sort first half recursively
        mergeSort(arr, middle + 1, right);     // sort second half recursively
        merge(arr, left, middle, right);       // merge sorted halves
    }
}

// Quick Sort
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

#endif