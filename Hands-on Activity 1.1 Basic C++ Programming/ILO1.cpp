#include <iostream>

//Function that will take two numbers and display the sum
int sumOfTwoNumbers(int fNum, int sNum);
//Function that will return that ineqaulity of the two numbers
bool isGreater(int A, int B);
//Function that returns two Boolean values and display the result of all logical operations then return true if it was a success.
bool comparingBools(bool Num1, bool Num2);


int main () {
    
    int number1, number2;

    std::cout << "Enter first number: " << std::endl;
    std::cin >> number1;

    std::cout << "Enter second number: " << std::endl;
    std::cin >> number2;


    std::cout << "The sum of the two numbers is: " << sumOfTwoNumbers(number1, number2) << std::endl;
    std::cout << "is the first number greater than the second number? " << (isGreater(number1, number2)? "Yes" : "No") << std::endl;

    bool boolResult = comparingBools(true, false);
    std::cout << "Was the comparison successful? " << (boolResult ? "Yes" : "No") << std::endl;

    return 0;
}

int sumOfTwoNumbers(int fNum, int sNum) {

    int sum = fNum + sNum;
    return sum;
}

bool isGreater(int A, int B) {

return A > B;
}

bool comparingBools(bool Num1, bool Num2) {
    std::cout << "AND: " << (Num1 && Num2) << std::endl;
    std::cout << "OR: " << (Num1 || Num2) << std::endl;
    std::cout << "NOT A: " << (!Num1) << std::endl;
    std::cout << "NOT B: " << (!Num2) << std::endl;
    return true;
}