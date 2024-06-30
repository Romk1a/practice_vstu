#include "circle_h.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <limits>

using namespace std;

const double PI = 3.141592653589793;

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
    this->radius = circumference / (2 * PI);
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
    return 2 * PI * radius;
}

void Circle::setCircumference(double circumference) {
    if (circumference <= 0) throw std::invalid_argument("Circumference must be positive.");
    this->radius = circumference / (2 * PI);
}

double Circle::getArea() const {
    return PI * radius * radius;
}

bool Circle::intersects(const Circle& other) const {
    double distance = std::sqrt(std::pow(this->radius - other.radius, 2));
    return distance <= (this->radius + other.radius);
}

bool Circle::contains(double x, double y) const {
    double distance = std::sqrt(x * x + y * y);
    return distance <= radius;
}

void displayMenu() {
    cout << "�������� ��������:" << endl;
    cout << "1. ������ ���������� �� �������" << endl;
    cout << "2. ������ ���������� �� ��������" << endl;
    cout << "3. ������ ���������� �� ����� ����������" << endl;
    cout << "4. �������� ������ ����������" << endl;
    cout << "5. �������� ������� ����������" << endl;
    cout << "6. �������� ����� ����������" << endl;
    cout << "7. ��������� ����������� � ������ �����������" << endl;
    cout << "8. ���������, ����� �� ����� ������ ����������" << endl;
    cout << "9. ������� ��������� ����������" << endl;
    cout << "0. �����" << endl;
    cout << "������� ��������: "; 
}

double getPositiveDouble(const std::string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������: ������� ������������� �����.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void userMenu() {
    int choice;
    Circle* circle = nullptr;

    while (true) {
        displayMenu();
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������: ������� ���������� ����� �������� (0-9).\n";
            continue;
        }

        if (choice == 0) break;

        try {
            switch (choice) {
                case 1: {
                    double radius = getPositiveDouble("������� ������: ");
                    circle = new Circle(radius);
                    break;
                }
                case 2: {
                    double diameter = getPositiveDouble("������� �������: ");
                    circle = new Circle(diameter, true);
                    break;
                }
                case 3: {
                    double circumference = getPositiveDouble("������� ����� ����������: ");
                    circle = new Circle(circumference, true, true);
                    break;
                }
                case 4: {
                    if (circle) {
                        double radius = getPositiveDouble("������� ����� ������: ");
                        circle->setRadius(radius);
                    } else {
                        cout << "������� �������� ����������.\n";
                    }
                    break;
                }
                case 5: {
                    if (circle) {
                        double diameter = getPositiveDouble("������� ����� �������: ");
                        circle->setDiameter(diameter);
                    } else {
                        cout << "������� �������� ����������.\n";
                    }
                    break;
                }
                case 6: {
                    if (circle) {
                        double circumference = getPositiveDouble("������� ����� ����� ����������: ");
                        circle->setCircumference(circumference);
                    } else {
                        cout << "������� �������� ����������.\n";
                    }
                    break;
                }
                case 7: {
                    if (circle) {
                        double otherRadius = getPositiveDouble("������� ������ ������ ����������: ");
                        Circle otherCircle(otherRadius);
                        bool intersects = circle->intersects(otherCircle);
                        cout << "���������� " << (intersects ? "������������" : "�� ������������") << ".\n";
                    } else {
                        cout << "������� �������� ����������.\n";
                    }
                    break;
                }
                case 8: {
                    if (circle) {
                        double x = getPositiveDouble("������� ���������� x: ");
                        double y = getPositiveDouble("������� ���������� y: ");
                        bool contains = circle->contains(x, y);
                        cout << "����� " << (contains ? "�����" : "�� �����") << " ������ ����������.\n";
                    } else {
                        cout << "������� �������� ����������.\n";
                    }
                    break;
                }
                case 9: {
                    if (circle) {
                        cout << "������: " << circle->getRadius() << "\n";
                        cout << "�������: " << circle->getDiameter() << "\n";
                        cout << "����� ����������: " << circle->getCircumference() << "\n";
                        cout << "�������: " << circle->getArea() << "\n";
                    } else {
                        cout << "������� �������� ����������.\n";
                    }
                    break;
                }
            }
        } catch (const std::invalid_argument& e) {
            cout << "������: " << e.what() << "\n";
            continue;
        }
    }

    if (circle) delete circle;
}