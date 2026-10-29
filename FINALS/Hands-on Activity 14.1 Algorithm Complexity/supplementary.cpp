#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <string>
#include "searchingAlgo.h"

std::mutex coutMutex;

// Helper 1: For Binary Search signature (arr, size, target)
template <typename Func, typename T>
void runBinarySearch(std::string name, Func searchFunc, T arr[], int size, T target) {
    auto start = std::chrono::high_resolution_clock::now();
    
    searchFunc(arr, size, target);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout << name << " took: " << elapsed.count() << " ns\n";
}

// Helper 2: For Linear Search signature (size, target, arr)
template <typename Func, typename T>
void runLinearSearch(std::string name, Func searchFunc, int size, T target, T arr[]) {
    auto start = std::chrono::high_resolution_clock::now();
    
    searchFunc(size, target, arr);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::lock_guard<std::mutex> lock(coutMutex);
    std::cout << name << " took: " << elapsed.count() << " ns\n";
}

void testSearchWorstCase(int n) {
    std::cout << "\n=================== Input Size N = " << n << " ===================\n";

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    int target = -1; // Value not present in array forces worst case

    // Lines 37 & 38: Correct parameter orders and explicit template types (int)
    std::thread t1(runBinarySearch<void(int[], int, int), int>, "Binary Search", binarySearchArr<int>, arr, n, target);
    std::thread t2(runLinearSearch<void(int, int, int[]), int>, "Linear Search", linearSearchAR<int>, n, target, arr);

    t1.join();
    t2.join();

    delete[] arr;
}

int main() {
    testSearchWorstCase(1000);
    testSearchWorstCase(10000);
    testSearchWorstCase(100000);

    return 0;
}