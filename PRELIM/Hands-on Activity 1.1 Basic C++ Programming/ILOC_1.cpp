#include <iostream>

int main() {
    int Var1, Var2;
    int Swapped;
    
    std::cout << "Please Enter Your First Variable: ";
    std::cin >> Var1;
    
    std::cout << "Please Enter Your Second Variable: ";
    std::cin >> Var2;
    
    std::cout << "Your Original Variables are: " << std::endl;
    std::cout << "First Variable:  " << Var1 << std::endl;
    std::cout << "Second Variable: " << Var2 << std::endl;
    
    Swapped = Var1;
    Var1 = Var2;
    Var2 = Swapped;
    
    
    std::cout << "Your Swapped Variables are now: " << std::endl;
    std::cout << "First Variable: " << Var1 << std::endl;
    std::cout << "Second Variable: " << Var2 << std::endl;
    return 0;
}