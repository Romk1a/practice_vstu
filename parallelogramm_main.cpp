#include <iostream>
#include "Parallelogram.h"

int main() {
    double a, b, alpha;
    std::cout << "Enter the sides (a, b) and angle (alpha) of the parallelogram: ";
    std::cin >> a >> b >> alpha;

    Parallelogram p(a, b, alpha);

    std::cout << "Parallelogram properties:" << std::endl;
    std::cout << "Side A: " << p.getSideA() << std::endl;
    std::cout << "Side B: " << p.getSideB() << std::endl;
    std::cout << "Angle A: " << p.getAngleA() << " degrees" << std::endl;
    std::cout << "Angle B: " << p.getAngleB() << " degrees" << std::endl;
    std::cout << "Area: " << p.getArea() << std::endl;
    std::cout << "Perimeter: " << p.getPerimeter() << std::endl;

    return 0;
}
