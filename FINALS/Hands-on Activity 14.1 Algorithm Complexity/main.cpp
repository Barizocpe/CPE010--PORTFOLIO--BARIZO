#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
#include "sortingAlgo.h"

std::mutex coutMutex;

template <typename Func, typename T>
void runAndMeasure(std::string name, Func sortFunc, T arr[], size_t size) {
    auto start = std::chrono::high_resolution_clock::now();
    
    sortFunc(arr, size);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout << name << " took: " << elapsed.count() << " ns\n";
}

void testCases(size_t n) {
    std::cout << "\n== N = " << n << "==\n";
    
    int* arr1 = new int[n];
    int* arr2 = new int[n];

    // --- BEST CASE: Already Sorted (0 to n-1) ---
    for (size_t i = 0; i < n; i++) {
        arr1[i] = i;
        arr2[i] = i;
    }

    std::cout << "--- BEST CASE ---\n";
    std::thread t1(runAndMeasure<void(int[], size_t), int>, "Bubble Sort", bubbleSort<int>, arr1, n);
    std::thread t2(runAndMeasure<void(int[], size_t), int>, "Insertion Sort", insertionSort<int>, arr2, n);
    t1.join();
    t2.join();

    // --- WORST CASE: Reverse Sorted (n-1 down to 0) ---
    for (size_t i = 0; i < n; i++) {
        int val = n - i - 1;
        arr1[i] = val;
        arr2[i] = val;
    }

    std::cout << "--- WORST CASE ---\n";
    std::thread t3(runAndMeasure<void(int[], size_t), int>, "Bubble Sort", bubbleSort<int>, arr1, n);
    std::thread t4(runAndMeasure<void(int[], size_t), int>, "Insertion Sort", insertionSort<int>, arr2, n);
    t3.join();
    t4.join();

    delete[] arr1;
    delete[] arr2;
}

int main() {
    // Run tests for all three required sizes
    testCases(100);
    testCases(1000);
    testCases(10000);

    return 0;
}