#include <iostream>
#include <thread>
#include <chrono>

int globalValue = 0;

void add(int value) {
    std::this_thread::sleep_for(std::chrono::milliseconds(value * 20)); // small delay so the joins are visible
    globalValue += value;
}

int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << "Display: " << globalValue << std::endl;
    T1.join();
    std::cout << "Display: " << globalValue << std::endl;
    T2.join();
    std::cout << "Display: " << globalValue << std::endl;
    T3.join();
    std::cout << "Display: " << globalValue << std::endl;

    return 0;
}
