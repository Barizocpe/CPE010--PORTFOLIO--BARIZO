#include <iostream>
#include <vector>
#include <algorithm>

int getMinSteps (int n, std::vector<int>& memo) {

    if ( n == 1 ) {
        return 0; // base case
    }
    if( memo[n] != -1 ) {
        return memo[n];
        }  // we have solved it already :)
    int r = 1 + getMinSteps( n - 1, memo );  // '-1' step . 'r' will contain the optimal answer finally
    
    if( n%2 == 0 ) {
        r = std::min( r , 1 + getMinSteps( n / 2, memo ) ) ; // '/2' step
    }
    if( n%3 == 0 ) {
        r = std::min( r , 1 + getMinSteps( n / 3, memo ) ) ; // '/3' step
    }
    
    memo[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
    return r;
};

//int main function

int main() {
    int n;

    std::cout<<"Enter a positive integer: ";
    std::cin>>n;

    if (n < 1) {
        std::cout<<"PLease enter a positive integer!";
        return 0;
    };

    std::vector<int> memo(n+1, -1);

    std::cout<<"The minimum steps are: " << getMinSteps(n, memo) << std::endl;

    return 0;

};