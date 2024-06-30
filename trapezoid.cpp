#include "trapezoid.h"
#include <iostream>
#include <array>
#include <cmath>

Trapezoid::Trapezoid() : a(0), b(0), c(0), d(0), alpha(0), beta(0), gamma(0), delta(0), height(0), area(0), perimeter(0), e(0), f(0), theta(0) {}

// Функция проверки валидности трапеции по углам
bool isValidTrapezoidByAngles(double angle_A, double angle_B, double angle_C, double angle_D) {
    return (angle_A + angle_B + angle_C + angle_D) == 360;
}

bool Trapezoid::isValidTrapezoidBySidesAndAngles() const {
    if (a > 0 && b > 0 && c > 0 && d > 0) {
        if (a > b && (alpha + beta >= 180)) return false;
        if (b > a && (gamma + delta >= 180)) return false;
        if (a < b && (gamma + delta >= 180)) return false;
        if (b < a && (alpha + beta >= 180)) return false;
        return true;
    }
    return false;
}

void Trapezoid::setVerticesCoordinates(const std::array<double, 8>& vertices) {
    a = std::sqrt(std::pow(vertices[2] - vertices[0], 2) + std::pow(vertices[3] - vertices[1], 2));
    b = std::sqrt(std::pow(vertices[6] - vertices[4], 2) + std::pow(vertices[7] - vertices[5], 2));
    c = std::sqrt(std::pow(vertices[4] - vertices[0], 2) + std::pow(vertices[5] - vertices[1], 2));
    d = std::sqrt(std::pow(vertices[6] - vertices[2], 2) + std::pow(vertices[7] - vertices[3], 2));
    height = std::abs(vertices[5] - vertices[1]);
    if (!isValidTrapezoidBySidesAndAngles()) {
        std::cerr << "Ошибка: координаты не образуют валидную трапецию." << std::endl;
        a = b = c = d = 0;
    }
}

void Trapezoid::setSides(double a, double b, double c, double d) {
    if (a > 0 && b > 0 && c > 0 && d > 0) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        if (!isValidTrapezoidBySidesAndAngles()) {
            std::cerr << "Ошибка: стороны не образуют валидную трапецию." << std::endl;
            this->a = this->b = this->c = this->d = 0;
        }
    } else {
        std::cerr << "Ошибка: стороны должны быть положительными числами." << std::endl;
    }
}

void Trapezoid::setAngles(double angle_A, double angle_B, double angle_C, double angle_D) {
    if (isValidTrapezoidByAngles(angle_A, angle_B, angle_C, angle_D)) {
        alpha = angle_A; 
        beta = angle_B;  
        gamma = angle_C;
        delta = angle_D; 
        std::cout << "Углы задают существующую трапецию.\n";
        std::cerr << "Недостаточно данных для вычисления сторон, периметра и площади.\n";
    } else {
        std::cerr << "Ошибка: углы задают несуществующую трапецию или сумма углов не равна 360 градусам.\n";
    }
}

void Trapezoid::calculateFromDiagonalsAndAngle(double diagonal_e, double diagonal_f, double angle_theta) {
    if (diagonal_e > 0 && diagonal_f > 0 && angle_theta > 0 && angle_theta < 180) {
        this->e = diagonal_e;
        this->f = diagonal_f;
        this->theta = angle_theta;
        a = sqrt(pow(e, 2) + pow(f, 2) - 2 * e * f * cos(theta));
        b = sqrt(pow(e, 2) + pow(f, 2) - 2 * e * f * cos(M_PI - theta));
        
        if (a <= 0 || b <= 0) {
            std::cerr << "Ошибка: неверные значения для диагоналей и угла. Основания не могут быть вычислены." << std::endl;
            a = b = 0;
        } else {
            std::cout << "Основание a: " << a << " единиц" << std::endl;
            std::cout << "Основание b: " << b << " единиц" << std::endl;
            std::cout << "Недостаточно данных для вычисления боковых сторон и углов трапеции." << std::endl;
        }
    } else {
        std::cerr << "Ошибка: диагонали и угол должны быть положительными числами, угол должен быть меньше 180 градусов." << std::endl;
    }
}

void Trapezoid::setSidesAndHeight(double a, double b, double height) {
    if (a > 0 && b > 0 && height > 0) {
        this->a = a;
        this->b = b;
        this->height = height;
    } else {
        std::cerr << "Ошибка: стороны и высота должны быть положительными числами." << std::endl;
    }
}

void Trapezoid::setDiagonalsAndAngle(double diag1, double diag2, double angle) {
    if (diag1 > 0 && diag2 > 0 && angle > 0 && angle < 180) {
        if (a == 0 || b == 0) {
            std::cerr << "Ошибка: основания a и b не могут быть равны нулю." << std::endl;
            return;
        }
        double diagAngleRad = angle * M_PI / 180; 
        double s = diag1 * diag2 * std::sin(diagAngleRad) / 2; 
        height = 2 * s / (a + b); 
    } else {
        std::cerr << "Ошибка: диагонали и угол должны быть положительными числами, угол должен быть меньше 180 градусов." << std::endl;
    }
}

void Trapezoid::setMiddleLineAndHeight(double m, double height) {
    if (m > 0 && height > 0) {
        this->a = this->b = m;  
        this->height = height;
    } else {
        std::cerr << "Ошибка: средняя линия и высота должны быть положительными числами." << std::endl;
    }
}

void Trapezoid::calculateProperties() {
    calculateAreaAndPerimeter();
}

void Trapezoid::calculateAnglesFromSides() {
    if (a > 0 && b > 0 && c > 0 && d > 0) {
        double cos_alpha = (pow(c, 2) + pow(a, 2) - pow(d, 2)) / (2 * c * a);
        alpha = acos(cos_alpha) * (180.0 / M_PI); 

        double cos_beta = (pow(d, 2) + pow(a, 2) - pow(c, 2)) / (2 * d * a);
        beta = acos(cos_beta) * (180.0 / M_PI);

        double cos_gamma = (pow(c, 2) + pow(b, 2) - pow(a, 2)) / (2 * c * b);
        gamma = acos(cos_gamma) * (180.0 / M_PI);

        double cos_delta = (pow(d, 2) + pow(b, 2) - pow(a, 2)) / (2 * d * b);
        delta = acos(cos_delta) * (180.0 / M_PI);
    } else {
        std::cerr << "Ошибка: стороны должны быть положительными числами для вычисления углов." << std::endl;
    }
}

void Trapezoid::calculateAreaAndPerimeter() {
    if (a > 0 && b > 0 && height > 0) {
        area = (a + b) / 2 * height;
        perimeter = a + b + c + d;
    } else {
        std::cerr << "Ошибка: основания и высота должны быть положительными числами для вычисления площади и периметра." << std::endl;
    }
}

void Trapezoid::printProperties() const {
    std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
    std::cout << "Углы: alpha = " << alpha << ", beta = " << beta << ", gamma = " << gamma << ", delta = " << delta << std::endl;
    std::cout << "Высота: " << height << std::endl;
    std::cout << "Площадь: " << area << std::endl;
    std::cout << "Периметр: " << perimeter << std::endl;
}

void Trapezoid::menu() {
    int choice;
    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Задать координаты вершин" << std::endl;
        std::cout << "2. Задать стороны" << std::endl;
        std::cout << "3. Задать углы" << std::endl;
        std::cout << "4. Задать две стороны и высоту" << std::endl;
        std::cout << "5. Задать две диагонали и угол" << std::endl;
        std::cout << "6. Задать по средней линии и высоте" << std::endl;
        std::cout << "7. Вычислить свойства" << std::endl;
        std::cout << "8. Выйти из программы" << std::endl;
        std::cin >> choice;

        std::array<double, 8> vertices;
        double side_a, side_b, side_c, side_d;
        double angle_A, angle_B, angle_C, angle_D;
        double height, m, diag1, diag2, angle;

        switch (choice) {
            case 1:
                std::cout << "Введите координаты вершин (x1, y1, x2, y2, x3, y3, x4, y4): ";
                for (auto& v : vertices) {
                    std::cin >> v;
                }
                setVerticesCoordinates(vertices);
                break;
            case 2:
                std::cout << "Введите длины сторон a, b, c, d: ";
                std::cin >> side_a >> side_b >> side_c >> side_d;
                setSides(side_a, side_b, side_c, side_d);
                break;
            case 3:
                std::cout << "Введите углы alpha, beta, gamma, delta: ";
                std::cin >> angle_A >> angle_B >> angle_C >> angle_D;
                setAngles(angle_A, angle_B, angle_C, angle_D);
                break;
            case 4:
                std::cout << "Введите длины двух сторон и высоту: ";
                std::cin >> side_a >> side_b >> height;
                setSidesAndHeight(side_a, side_b, height);
                break;
            case 5:
                std::cout << "Введите длины двух диагоналей и угол между ними: ";
                std::cin >> diag1 >> diag2 >> angle;
                calculateFromDiagonalsAndAngle(diag1, diag2, angle);
                break;
            case 6:
                std::cout << "Введите длину средней линии и высоту: ";
                std::cin >> m >> height;
                setMiddleLineAndHeight(m, height);
                break;
            case 7:
                calculateProperties();
                printProperties();
                break;
            case 8:
                std::cout << "Завершение работы программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите действие из списка." << std::endl;
        }
    } while (choice != 8); 
}
