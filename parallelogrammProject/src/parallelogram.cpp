#include <iostream>
#include <cmath>
#include "parallelogram.h"

// Конструктор с двумя сторонами и углом
Parallelogram::Parallelogram(double a, double b, double alpha)
    : a(a), b(b), alpha(alpha * M_PI / 180.0), beta(M_PI - alpha * M_PI / 180.0),
      c(a), d(b), gamma(beta), delta(alpha * M_PI / 180.0) {}

// Конструктор с четырьмя сторонами
Parallelogram::Parallelogram(double a, double b, double c, double d, int)
    : a(a), b(b), c(c), d(d) {
    alpha = acos((a * a + b * b - c * c) / (2 * a * b));
    beta = acos((a * a + d * d - b * b) / (2 * a * d));
    gamma = beta;
    delta = alpha;
}

// Конструктор с двумя сторонами и двумя углами
Parallelogram::Parallelogram(double alphaRad, double betaRad, double a, double b)
    : a(a), b(b), alpha(alphaRad), beta(betaRad),
      c(a * sin(betaRad) / sin(alphaRad)), d(b * sin(alphaRad) / sin(betaRad)),
      gamma(betaRad), delta(alphaRad) {}

double Parallelogram::getSideA() const {
    return a;
}

double Parallelogram::getSideB() const {
    return b;
}

double Parallelogram::getSideC() const {
    return c;
}

double Parallelogram::getSideD() const {
    return d;
}

double Parallelogram::getAngleA() const {
    return alpha * 180.0 / M_PI;
}

double Parallelogram::getAngleB() const {
    return beta * 180.0 / M_PI;
}

double Parallelogram::getAngleC() const {
    return gamma * 180.0 / M_PI;
}

double Parallelogram::getAngleD() const {
    return delta * 180.0 / M_PI;
}

double Parallelogram::calculateArea() const {
    return a * b * sin(alpha);
}

double Parallelogram::calculatePerimeter() const {
    return 2 * (a + b);
}

void showMenu() {
    int choice;
    double a, b, c, d, alpha, beta;

    do {
        std::cout << "Choose how to create a parallelogram:\n";
        std::cout << "1. Two sides and an angle\n";
        std::cout << "2. Four sides\n";
        std::cout << "3. Two angles and two sides\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter side A, side B, and angle A (in degrees): ";
            std::cin >> a >> b >> alpha;
            {
                Parallelogram p1(a, b, alpha);
                std::cout << "Area: " << p1.calculateArea() << "\n";
                std::cout << "Perimeter: " << p1.calculatePerimeter() << "\n";
            }
            break;
        case 2:
            std::cout << "Enter side A, side B, side C, and side D: ";
            std::cin >> a >> b >> c >> d;
            {
                Parallelogram p2(a, b, c, d, 0);
                std::cout << "Area: " << p2.calculateArea() << "\n";
                std::cout << "Perimeter: " << p2.calculatePerimeter() << "\n";
            }
            break;
        case 3:
            std::cout << "Enter side A, side B, angle A (in degrees), and angle B (in degrees): ";
            std::cin >> a >> b >> alpha >> beta;
            {
                Parallelogram p3(alpha * M_PI / 180.0, beta * M_PI / 180.0, a, b);
                std::cout << "Area: " << p3.calculateArea() << "\n";
                std::cout << "Perimeter: " << p3.calculatePerimeter() << "\n";
            }
            break;
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);
}
