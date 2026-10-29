#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

// ==========================================
// PROBLEM 1: Algorithm Unique(A)
// Theoretical Time Complexity: O(n^2)
// ==========================================
bool is_unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] == A[j]) {
                return false; // Found duplicate
            }
        }
    }
    return true; // All elements unique
}

// ==========================================
// PROBLEM 2a: Linear Recursive Power (rpower)
// Theoretical Time Complexity: O(n)
// ==========================================
long long rpower(int x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

// ==========================================
// PROBLEM 2b: Binary Recursive Power (brpower)
// Theoretical Time Complexity: O(log n)
// ==========================================
long long brpower(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

// ==========================================
// EXPERIMENTAL ANALYSIS & DRIVER CODE
// ==========================================
int main() {
    std::cout << "--- PROBLEM 1: ELEMENT UNIQUENESS (O(n^2)) ---\n";
    std::vector<int> sizes = {1000, 5000, 10000};

    for (int n : sizes) {
        // Create an array with unique values
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = i;

        auto start = std::chrono::high_resolution_clock::now();
        bool unique_result = is_unique(arr);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "Input Size N = " << n 
                  << " | Is Unique: " << (unique_result ? "True" : "False")
                  << " | Time: " << duration << " microseconds\n";
    }

    std::cout << "\n--- PROBLEM 2: POWER ALGORITHMS (O(n) vs O(log n)) ---\n";
    int base = 2;
    std::vector<int> exponents = {10, 20, 30};

    for (int exp : exponents) {
        // Measure Linear Recursion (rpower)
        auto start1 = std::chrono::high_resolution_clock::now();
        long long res1 = rpower(base, exp);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();

        // Measure Binary Recursion (brpower)
        auto start2 = std::chrono::high_resolution_clock::now();
        long long res2 = brpower(base, exp);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto dur2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();

        std::cout << "Base: " << base << " | Exp: " << exp << "\n"
                  << "  rpower  (Linear O(n))   : Result = " << res1 << " | Time: " << dur1 << " ns\n"
                  << "  brpower (Binary O(logn)): Result = " << res2 << " | Time: " << dur2 << " ns\n";
    }

    return 0;
}