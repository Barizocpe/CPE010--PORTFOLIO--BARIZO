#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

bool Unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

void test_unique(int n) {
    // Fill array with distinct values (1, 2, ..., n) for worst case
    std::vector<int> A(n);
    std::iota(A.begin(), A.end(), 1);

    auto start = std::chrono::high_resolution_clock::now();
    bool is_unique = Unique(A);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "N = " << n << " | Time: " << duration << " microseconds\n";
}

int main() {
    test_unique(1000);
    test_unique(5000);
    test_unique(10000);
    test_unique(20000);
    return 0;
}