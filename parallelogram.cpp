#include <iostream>
#include <cmath>
#include "parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double alpha)
    : a(a), b(b), alpha(alpha* M_PI / 180.0), beta(M_PI - alpha * M_PI / 180.0),
    c(a), d(b), gamma(beta), delta(alpha* M_PI / 180.0) {}

Parallelogram::Parallelogram(double a, double b, double c, double d)
    : a(a), b(b), c(c), d(d) {
    alpha = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / M_PI;
    beta = acos((a * a + d * d - b * b) / (2 * a * d)) * 180.0 / M_PI;
    gamma = beta;
    delta = alpha;
}

Parallelogram::Parallelogram(double alphaRad, double betaRad, double a, double b)
    : a(a), b(b), alpha(alphaRad), beta(betaRad),
    c(a* sin(beta) / sin(alpha)), d(b* sin(alpha) / sin(beta)),
    gamma(beta), delta(alpha) {}

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
            {
                Parallelogram p1(a, b, alpha);
                // Вывод характеристик параллелограмма p1
            }
            break;
        case 2:
            std::cout << "Enter side A, side B, side C, and side D: ";
            std::cin >> a >> b >> c >> d;
            {
                Parallelogram p2(a, b, c, d);
                // Вывод характеристик параллелограмма p2
            }
            break;
        case 3:
            std::cout << "Enter angle A (in degrees), angle B (in degrees), side A, and side B: ";
            std::cin >> alpha >> beta >> a >> b;
            {
                Parallelogram p3(alpha * M_PI / 180.0, beta * M_PI / 180.0, a, b);
                // Вывод характеристик параллелограмма p3
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
