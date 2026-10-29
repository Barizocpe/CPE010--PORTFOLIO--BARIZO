#include <iostream>
#include <cmath>

float distanceTwoPoints(float x1, float x2, float y1, float y2);

int main() {
    float x1, x2, y1, y2;
    
    std::cout << "Please Enter your X Variables: " << std::endl;
    std::cout << "x1: ";
    std::cin >> x1;
    std::cout << "x2: ";
    std::cin >> x2;
    
    std::cout << "Please Enter your Y Variables: " << std::endl;
    std::cout << "y1: ";
    std::cin >> y1;
    std::cout << "y2: ";
    std::cin >> y2;
    
    float DistancebetweenTwoPoints = distanceTwoPoints(x1, x2, y1, y2);
    std::cout << "The distance between two points is: " << DistancebetweenTwoPoints<< std::endl;
}

float distanceTwoPoints(float x1, float x2, float y1, float y2) {
    float dx, dy;

    dx = x2 - x1;
    dy = y2 - y1;

    return sqrt(dx * dx + dy * dy);
}