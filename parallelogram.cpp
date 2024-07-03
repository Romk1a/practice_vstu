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

void showMenu5() {
    int choice;
    double a, b, c, d, alpha, beta;

    do {
        std::cout << "Выберите способ создания параллелограмма:\n";
        std::cout << "1. Две стороны и угол\n";
        std::cout << "2. Четыре стороны\n";
        std::cout << "3. Два угла и две стороны\n";
        std::cout << "4. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите сторону A, сторону B и угол A (в градусах): ";
            std::cin >> a >> b >> alpha;
            {
                Parallelogram p1(a, b, alpha);
                std::cout << "Площадь: " << p1.calculateArea() << "\n";
                std::cout << "Периметр: " << p1.calculatePerimeter() << "\n";
            }
            break;
        case 2:
            std::cout << "Введите сторону A, сторону B, сторону C и сторону D: ";
            std::cin >> a >> b >> c >> d;
            {
                Parallelogram p2(a, b, c, d, 0);
                std::cout << "Площадь: " << p2.calculateArea() << "\n";
                std::cout << "Периметр: " << p2.calculatePerimeter() << "\n";
            }
            break;
        case 3:
            std::cout << "Введите сторону A, сторону B, угол A (в градусах) и угол B (в градусах): ";
            std::cin >> a >> b >> alpha >> beta;
            {
                Parallelogram p3(alpha * M_PI / 180.0, beta * M_PI / 180.0, a, b);
                std::cout << "Площадь: " << p3.calculateArea() << "\n";
                std::cout << "Периметр: " << p3.calculatePerimeter() << "\n";
            }
            break;
        case 4:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте еще раз.\n";
            break;
        }
    } while (choice != 4);
}
