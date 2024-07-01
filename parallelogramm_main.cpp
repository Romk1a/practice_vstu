#include <iostream>
#include "Parallelogram.h"

int main() {
    int choice;
    double a, b, c, d, alpha, beta, gamma, delta;

    do {
        std::cout << "Choose how to define the parallelogram:" << std::endl;
        std::cout << "1. By sides (a, b) and angle (alpha)" << std::endl;
        std::cout << "2. By all four sides (a, b, c, d)" << std::endl;
        std::cout << "3. By angles (alpha, beta) and sides (a, b)" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter side a, side b, and angle alpha (in degrees): ";
            std::cin >> a >> b >> alpha;
            Parallelogram p1(a, b, alpha);
            displayParallelogramInfo(p1);
            break;
        case 2:
            std::cout << "Enter all four sides (a, b, c, d): ";
            std::cin >> a >> b >> c >> d;
            Parallelogram p2(a, b, c, d);
            displayParallelogramInfo(p2);
            break;
        case 3:
            std::cout << "Enter angles alpha, beta (in degrees) and sides a, b: ";
            std::cin >> alpha >> beta >> a >> b;
            Parallelogram p3(alpha, beta, a, b);
            displayParallelogramInfo(p3);
            break;
        case 4:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 4);

    return 0;
}

void displayParallelogramInfo(const Parallelogram& p) {
    std::cout << "Parallelogram properties:" << std::endl;
    std::cout << "Side A: " << p.getSideA() << std::endl;
    std::cout << "Side B: " << p.getSideB() << std::endl;
    std::cout << "Side C: " << p.getSideC() << std::endl;
    std::cout << "Side D: " << p.getSideD() << std::endl;
    std::cout << "Angle A: " << p.getAngleA() << " degrees" << std::endl;
    std::cout << "Angle B: " << p.getAngleB() << " degrees" << std::endl;
    std::cout << "Angle C: " << p.getAngleC() << " degrees" << std::endl;
    std::cout << "Angle D: " << p.getAngleD() << " degrees" << std::endl;
    std::cout << "Area: " << p.calculateArea() << std::endl;
    std::cout << "Perimeter: " << p.calculatePerimeter() << std::endl;
    std::cout << std::endl;
}
