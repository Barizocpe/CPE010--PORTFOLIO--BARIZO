#include <iostream>
#include <chrono>

long long rpower(long long x, int n) {
    if (n == 0) return 1; // base case
    return x * rpower(x, n - 1); // linear reduction
}

long long brpower(long long x, int n) {
    if (n == 0) return 1; // base case
    if (n % 2 != 0) {
        long long y = brpower(x, (n - 1) / 2); // divide exponent by 2
        return x * y * y; // odd exponent multiplication
    } else {
        long long y = brpower(x, n / 2); // divide exponent by 2[cite: 5]
        return y * y; // even exponent multiplication[cite: 5]
    }
}

void compare_power(long long x, int n) {
    // Measure rpower
    auto start1 = std::chrono::high_resolution_clock::now();
    long long res1 = rpower(x, n);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();

    // Measure brpower
    auto start2 = std::chrono::high_resolution_clock::now();
    long long res2 = brpower(x, n);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto dur2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();

    std::cout << "Exponent (N) = " << n 
              << " | rpower: " << dur1 << " ns"
              << " | brpower: " << dur2 << " ns\n";
}

int main() {
    compare_power(2, 10);
    compare_power(2, 100);
    compare_power(2, 1000);
    compare_power(2, 10000);
    return 0;
}