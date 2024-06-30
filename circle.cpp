#include "circle_h.h"
#include <iostream>
#include <cmath>
#include <limits>

const double PI = 3.141592653589793;

using namespace std;

// Конструктор для задания радиуса
Circle::Circle(double radius) {
    calculateFromRadius(radius);
}

// Конструктор для задания диаметра
Circle::Circle(double diameter, bool isDiameter) {
    if (isDiameter) {
        calculateFromRadius(diameter / 2);
    }
}

// Конструктор для задания длины окружности
Circle::Circle(double circumference, bool isCircumference, bool) {
    if (isCircumference) {
        calculateFromRadius(circumference / (2 * PI));
    }
}

// Метод для вычисления параметров по радиусу
void Circle::calculateFromRadius(double r) {
    radius = r;
}

// Методы для получения параметров окружности
double Circle::getRadius() const {
    return radius;
}

double Circle::getDiameter() const {
    return 2 * radius;
}

double Circle::getCircumference() const {
    return 2 * PI * radius;
}

double Circle::getArea() const {
    return PI * radius * radius;
}

// Методы для изменения параметров окружности
void Circle::setRadius(double r) {
    calculateFromRadius(r);
}

void Circle::setDiameter(double diameter) {
    calculateFromRadius(diameter / 2);
}

void Circle::setCircumference(double circumference) {
    calculateFromRadius(circumference / (2 * PI));
}

// Метод для проверки пересечения с другой окружностью
bool Circle::intersects(const Circle& other) const {
    double distance = sqrt(pow(this->radius - other.radius, 2));
    return distance <= (this->radius + other.radius);
}

// Метод для проверки, лежит ли точка внутри окружности
bool Circle::contains(double x, double y) const {
    double distance = sqrt(x * x + y * y);
    return distance <= radius;
}

// Функция для отображения свойств окружности
void printCircleProperties(const Circle& circle) {
    cout << "Радиус: " << circle.getRadius() << endl;
    cout << "Диаметр: " << circle.getDiameter() << endl;
    cout << "Длина окружности: " << circle.getCircumference() << endl;
    cout << "Площадь: " << circle.getArea() << endl;
}

// Функция для получения положительного числа от пользователя
double getPositiveNumber() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Пожалуйста, введите положительное число: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Функция для отображения меню и выполнения соответствующих действий
void displayMenu() {
    Circle circle(0);

    while (true) {
        cout << "Выберите операцию:" << endl;
        cout << "1. Задать окружность по радиусу" << endl;
        cout << "2. Задать окружность по диаметру" << endl;
        cout << "3. Задать окружность по длине окружности" << endl;
        cout << "4. Изменить радиус окружности" << endl;
        cout << "5. Изменить диаметр окружности" << endl;
        cout << "6. Изменить длину окружности" << endl;
        cout << "7. Проверить пересечение с другой окружностью" << endl;
        cout << "8. Проверить, лежит ли точка внутри окружности" << endl;
        cout << "9. Вывести параметры окружности" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите операцию: ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 0 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный выбор. Пожалуйста, выберите правильный вариант." << endl;
            continue;
        }

        double value;
        double x, y;
        Circle otherCircle(0);

        switch (choice) {
        case 1:
            cout << "Введите радиус окружности: ";
            value = getPositiveNumber();
            circle = Circle(value);
            break;
        case 2:
            cout << "Введите диаметр окружности: ";
            value = getPositiveNumber();
            circle = Circle(value, true);
            break;
        case 3:
            cout << "Введите длину окружности: ";
            value = getPositiveNumber();
            circle = Circle(value, true, true);
            break;
        case 4:
            cout << "Введите новый радиус окружности: ";
            value = getPositiveNumber();
            circle.setRadius(value);
            break;
        case 5:
            cout << "Введите новый диаметр окружности: ";
            value = getPositiveNumber();
            circle.setDiameter(value);
            break;
        case 6:
            cout << "Введите новую длину окружности: ";
            value = getPositiveNumber();
            circle.setCircumference(value);
            break;
        case 7:
            cout << "Введите радиус другой окружности: ";
            value = getPositiveNumber();
            otherCircle = Circle(value);
            if (circle.intersects(otherCircle)) {
                cout << "Окружности пересекаются." << endl;
            }
            else {
                cout << "Окружности не пересекаются." << endl;
            }
            break;
        case 8:
            cout << "Введите координаты точки (x и y): ";
            cin >> x >> y;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Неверный ввод. Пожалуйста, введите числовые значения для x и y." << endl;
            }
            else {
                if (circle.contains(x, y)) {
                    cout << "Точка лежит внутри окружности." << endl;
                }
                else {
                    cout << "Точка не лежит внутри окружности." << endl;
                }
            }
            break;
        case 9:
            printCircleProperties(circle);
            break;
        case 0:
            return;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите правильный вариант." << endl;
            break;
        }
    }
}