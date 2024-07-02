#include "trapezoid.h"
#include <limits>

// Конструктор
Trapezoid::Trapezoid() {
    resetProperties();
}

bool Trapezoid::setBasesAndHeight(double a, double b, double h) {
    resetProperties();
    if (!isPositive(a) || !isPositive(b) || !isPositive(h)) {
        std::cerr << "Основания и высота должны быть положительными значениями.\n";
        return false;
    }
    base1 = a;
    base2 = b;
    height = h;
    computeProperties();
    return true;
}

bool Trapezoid::setDiagonalsAndAngle(double d1, double d2, double ang) {
    resetProperties();
    if (!isPositive(d1) || !isPositive(d2) || !isPositive(ang) || ang >= 180.0 || ang <= 0.0) {
        std::cerr << "Диагонали должны быть положительными, а угол должен быть в диапазоне от 0 до 180 градусов.\n";
        return false;
    }
    if (d1 != d2) {
        std::cerr << "Диагонали должны быть равными для равнобедренной трапеции.\n";
        return false;
    }
    diagonal1 = d1;
    diagonal2 = d2;
    angle = ang;
    area = 0.5 * d1 * d2 * sin(angle * M_PI / 180);
    return true;
}

bool Trapezoid::setMedianAndHeight(double m, double h) {
    resetProperties();
    if (!isPositive(m) || !isPositive(h)) {
        std::cerr << "Средняя линия и высота должны быть положительными значениями.\n";
        return false;
    }
    median = m;
    height = h;
    computeProperties();
    return true;
}

void Trapezoid::computeProperties() {
    if (base1 != 0 && base2 != 0 && height != 0) {
        area = ((base1 + base2) / 2) * height;
        side = sqrt(pow((base1 - base2) / 2, 2) + pow(height, 2));
        perimeter = base1 + base2 + 2 * side;
        computeAngles();
    } else if (median != 0 && height != 0) {
        area = median * height;
    }
}

void Trapezoid::computeAngles() {
    angleA = atan(height / ((base1 - base2) / 2)) * 180 / M_PI;
    angleB = 180 - angleA;
    angleC = angleA;
    angleD = angleB;
}

void Trapezoid::displayProperties() const {
    if (base1 != 0 && base2 != 0 && height != 0) {
        std::cout << "Основание 1: " << base1 << "\n";
        std::cout << "Основание 2: " << base2 << "\n";
        std::cout << "Высота: " << height << "\n";
        std::cout << "Сторона: " << side << "\n";
        std::cout << "Площадь: " << area << "\n";
        std::cout << "Периметр: " << perimeter << "\n";
        std::cout << "Углы: " << angleA << ", " << angleB << ", " << angleC << ", " << angleD << "\n";
    } else if (diagonal1 != 0 && diagonal2 != 0 && angle != 0) {
        std::cout << "Диагональ 1: " << diagonal1 << "\n";
        std::cout << "Диагональ 2: " << diagonal2 << "\n";
        std::cout << "Угол: " << angle << "\n";
        std::cout << "Площадь: " << area << "\n";
        std::cout << "Недостаточно данных для вычисления периметра, боковых сторон и углов.\n";
    } else if (median != 0 && height != 0) {
        std::cout << "Сумма оснований: " << 2 * median << "\n";
        std::cout << "Высота: " << height << "\n";
        std::cout << "Площадь: " << area << "\n";
        std::cout << "Недостаточно данных для вычисления периметра, боковых сторон и углов.\n";
    } else {
        std::cout << "Недостаточно данных для вычисления свойств трапеции.\n";
    }
}

bool Trapezoid::isIsosceles() const {
    return (base1 == base2 && side != 0);
}

void Trapezoid::resetProperties() {
    base1 = base2 = height = diagonal1 = diagonal2 = angle = median = 0;
    side = area = perimeter = 0;
    angleA = angleB = angleC = angleD = 0;
}

bool isValidNumber(double value) {
    return !std::isnan(value) && !std::isinf(value);
}

bool isPositive(double value) {
    return isValidNumber(value) && value > 0;
}

// Функция меню
void displayMenu() {
    Trapezoid trapezoid;
    int choice = 0;
    double a, b, h, d1, d2, ang, m;

    while (true) {
        std::cout << "1. Задать основания и высоту\n";
        std::cout << "2. Задать диагонали и угол\n";
        std::cout << "3. Задать среднюю линию и высоту\n";
        std::cout << "4. Вычислить свойства\n";
        std::cout << "5. Выйти\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Ошибка: введите число.\n";
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Введите основание 1, основание 2 и высоту: ";
                std::cin >> a >> b >> h;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Ошибка: введите корректные числа.\n";
                    continue;
                }
                if (trapezoid.setBasesAndHeight(a, b, h)) {
                    std::cout << "Трапеция задана успешно.\n";
                }
                break;
            case 2:
                std::cout << "Введите диагональ 1, диагональ 2 и угол: ";
                std::cin >> d1 >> d2 >> ang;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Ошибка: введите корректные числа.\n";
                    continue;
                }
                if (trapezoid.setDiagonalsAndAngle(d1, d2, ang)) {
                    std::cout << "Трапеция задана успешно.\n";
                }
                break;
            case 3:
                std::cout << "Введите среднюю линию и высоту: ";
                std::cin >> m >> h;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Ошибка: введите корректные числа.\n";
                    continue;
                }
                if (trapezoid.setMedianAndHeight(m, h)) {
                    std::cout << "Трапеция задана успешно.\n";
                }
                break;
            case 4:
                trapezoid.displayProperties();
                break;
            case 5:
                std::cout << "Выход...\n";
                return;
            default:
                std::cerr << "Неверная опция. Попробуйте снова.\n";
                break;
        }
    }
}
