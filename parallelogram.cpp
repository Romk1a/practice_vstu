#include <iostream>
#include <cmath>
#include "Parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double alpha) {
    this->a = a;
    this->b = b;
    this->alpha = alpha * M_PI / 180.0;
    this->beta = M_PI - this->alpha;
    this->c = a;
    this->d = b;
    this->gamma = this->beta;
    this->delta = this->alpha;
}

Parallelogram::Parallelogram(double a, double b, double c, double d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->alpha = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / M_PI;
    this->beta = acos((a * a + d * d - b * b) / (2 * a * d)) * 180.0 / M_PI;
    this->gamma = this->beta;
    this->delta = this->alpha;
}

Parallelogram::Parallelogram(double alpha, double beta, double a, double b) {
    this->a = a;
    this->b = b;
    this->alpha = alpha * M_PI / 180.0;
    this->beta = beta * M_PI / 180.0;
    this->c = a * sin(this->beta) / sin(this->alpha);
    this->d = b * sin(this->alpha) / sin(this->beta);
    this->gamma = this->beta;
    this->delta = this->alpha;
}

// Остальные методы класса Parallelogram...

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
            Parallelogram p1(a, b, alpha);
            std::cout << "Parallelogram characteristics:\n";
            std::cout << "Side A: " << p1.getSideA() << "\n";
            std::cout << "Side B: " << p1.getSideB() << "\n";
            std::cout << "Angle A: " << p1.getAngleA() << "\n";
            std::cout << "Angle B: " << p1.getAngleB() << "\n";
            std::cout << "Area: " << p1.calculateArea() << "\n";
            std::cout << "Perimeter: " << p1.calculatePerimeter() << "\n";
            break;
        case 2:
            std::cout << "Enter side A, side B, side C, and side D: ";
            std::cin >> a >> b >> c >> d;
            Parallelogram p2(a, b, c, d);
            std::cout << "Parallelogram characteristics:\n";
            std::cout << "Side A: " << p2.getSideA() << "\n";
            std::cout << "Side B: " << p2.getSideB() << "\n";
            std::cout << "Side C: " << p2.getSideC() << "\n";
            std::cout << "Side D: " << p2.getSideD() << "\n";
            std::cout << "Angle A: " << p2.getAngleA() << "\n";
            std::cout << "Angle B: " << p2.getAngleB() << "\n";
            std::cout << "Area: " << p2.calculateArea() << "\n";
            std::cout << "Perimeter: " << p2.calculatePerimeter() << "\n";
            break;
        case 3:
            std::cout << "Enter angle A (in degrees), angle B (in degrees), side A, and side B: ";
            std::cin >> alpha >> beta >> a >> b;
            Parallelogram p3(alpha, beta, a, b);
            std::cout << "Parallelogram characteristics:\n";
            std::cout << "Side A: " << p3.getSideA() << "\n";
            std::cout << "Side B: " << p3.getSideB() << "\n";
            std::cout << "Angle A: " << p3.getAngleA() << "\n";
            std::cout << "Angle B: " << p3.getAngleB() << "\n";
            std::cout << "Area: " << p3.calculateArea() << "\n";
            std::cout << "Perimeter: " << p3.calculatePerimeter() << "\n";
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
