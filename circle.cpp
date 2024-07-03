#include "circle_h.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <limits>

using namespace std;

const double Pi = 3.141592653589793;

Circle::Circle(double radius) {
    if (radius <= 0) throw std::invalid_argument("Radius must be positive.");
    this->radius = radius;
}

Circle::Circle(double diameter, bool isDiameter) {
    if (diameter <= 0) throw std::invalid_argument("Diameter must be positive.");
    this->radius = diameter / 2.0;
}

Circle::Circle(double circumference, bool isCircumference, bool unused) {
    if (circumference <= 0) throw std::invalid_argument("Circumference must be positive.");
    this->radius = circumference / (2 * Pi);
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double radius) {
    if (radius <= 0) throw std::invalid_argument("Radius must be positive.");
    this->radius = radius;
}

double Circle::getDiameter() const {
    return 2 * radius;
}

void Circle::setDiameter(double diameter) {
    if (diameter <= 0) throw std::invalid_argument("Diameter must be positive.");
    this->radius = diameter / 2.0;
}

double Circle::getCircumference() const {
    return 2 * Pi * radius;
}

void Circle::setCircumference(double circumference) {
    if (circumference <= 0) throw std::invalid_argument("Circumference must be positive.");
    this->radius = circumference / (2 * Pi);
}

double Circle::getArea() const {
    return Pi * radius * radius;
}

double Circle::calculateAreaFromRadius(double radius) const {
    if (radius <= 0) throw std::invalid_argument("Radius must be positive.");
    return Pi * radius * radius;
}

double Circle::calculateAreaFromDiameter(double diameter) const {
    if (diameter <= 0) throw std::invalid_argument("Diameter must be positive.");
    double radius = diameter / 2.0;
    return Pi * radius * radius;
}

double Circle::calculateAreaFromCircumference(double circumference) const {
    if (circumference <= 0) throw std::invalid_argument("Circumference must be positive.");
    double radius = circumference / (2 * Pi);
    return Pi * radius * radius;
}

bool Circle::intersects(const Circle& other) const {
    double distance = std::sqrt(std::pow(this->radius - other.radius, 2));
    return distance <= (this->radius + other.radius);
}

bool Circle::contains(double x, double y) const {
    double distance = std::sqrt(x * x + y * y);
    return distance <= radius;
}

void displayMenu1() {
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
    cout << "10. Вычислить площадь окружности" << endl;
    cout << "0. Выход" << endl;
    cout << "Введите операцию: "; 
}

double getPositiveDouble(const std::string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите положительное число.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void userMenu1() {
    int choice;
    Circle* circle = nullptr;

    while (true) {
        displayMenu1();
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите допустимый номер операции (0-10).\n";
            continue;
        }

        if (choice == 0) break;try {
            switch (choice) {
                case 1: {
                    double radius = getPositiveDouble("Введите радиус: ");
                    circle = new Circle(radius);
                    break;
                }
                case 2: {
                    double diameter = getPositiveDouble("Введите диаметр: ");
                    circle = new Circle(diameter, true);
                    break;
                }
                case 3: {
                    double circumference = getPositiveDouble("Введите длину окружности: ");
                    circle = new Circle(circumference, true, true);
                    break;
                }
                case 4: {
                    if (circle) {
                        double radius = getPositiveDouble("Введите новый радиус: ");
                        circle->setRadius(radius);
                    } else {
                        cout << "Сначала создайте окружность.\n";
                    }
                    break;
                }
                case 5: {
                    if (circle) {
                        double diameter = getPositiveDouble("Введите новый диаметр: ");
                        circle->setDiameter(diameter);
                    } else {
                        cout << "Сначала создайте окружность.\n";
                    }
                    break;
                }
                case 6: {
                    if (circle) {
                        double circumference = getPositiveDouble("Введите новую длину окружности: ");
                        circle->setCircumference(circumference);
                    } else {
                        cout << "Сначала создайте окружность.\n";
                    }
                    break;
                }
                case 7: {
                    if (circle) {
                        double otherRadius = getPositiveDouble("Введите радиус другой окружности: ");
                        Circle otherCircle(otherRadius);
                        bool intersects = circle->intersects(otherCircle);
                        cout << "Окружности " << (intersects ? "пересекаются" : "не пересекаются") << ".\n";
                    } else {
                        cout << "Сначала создайте окружность.\n";
                    }
                    break;
                }
                case 8: {
                    if (circle) {
                        double x = getPositiveDouble("Введите координату x: ");
                        double y = getPositiveDouble("Введите координату y: ");
                        bool contains = circle->contains(x, y);
                        cout << "Точка " << (contains ? "лежит" : "не лежит") << " внутри окружности.\n";
                    } else {
                        cout << "Сначала создайте окружность.\n";
                    }
                    break;
                }
                case 9: {
                    if (circle) {
                        cout << "Радиус: " << circle->getRadius() << "\n";
                        cout << "Диаметр: " << circle->getDiameter() << "\n";
                        cout << "Длина окружности: " << circle->getCircumference() << "\n";
                        cout << "Площадь: " << circle->getArea() << "\n";
                    } else {
                        cout << "Сначала создайте окружность.\n";
                    }
                    break;
                }
                case 10: {
                    if (circle) {
                        int subChoice;
                        cout << "Вычислить площадь через:\n";
                        cout << "1. Радиус\n";
                        cout << "2. Диаметр\n";
                        cout << "3. Длину окружности\n";
                        cout << "Введите операцию: ";
                        cin >> subChoice;switch (subChoice) {
                            case 1: {
                                double radius = getPositiveDouble("Введите радиус: ");
                                cout << "Площадь: " << circle->calculateAreaFromRadius(radius) << "\n";
                                break;
                            }
                            case 2: {
                                double diameter = getPositiveDouble("Введите диаметр: ");
                                cout << "Площадь: " << circle->calculateAreaFromDiameter(diameter) << "\n";
                                break;
                            }
                            case 3: {
                                double circumference = getPositiveDouble("Введите длину окружности: ");
                                cout << "Площадь: " << circle->calculateAreaFromCircumference(circumference) << "\n";
                                break;
                            }
                            default:
                                cout << "Ошибка: введите допустимый номер операции (1-3).\n";
                        }
                    } else {
                        cout << "Сначала создайте окружность.\n";
                    }
                    break;
                }
            }
        } catch (const std::invalid_argument& e) {
            cout << "Ошибка: " << e.what() << "\n";
            continue;
        }
    }

    if (circle) delete circle;
}