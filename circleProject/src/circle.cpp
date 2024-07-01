#include "circle_h.h"
#include <iostream>
#include <cmath>
#include <limits>

const double PI = 3.141592653589793;

using namespace std;

// ����������� ��� ������� �������
Circle::Circle(double radius) {
    calculateFromRadius(radius);
}

// ����������� ��� ������� ��������
Circle::Circle(double diameter, bool isDiameter) {
    if (isDiameter) {
        calculateFromRadius(diameter / 2);
    }
}

// ����������� ��� ������� ����� ����������
Circle::Circle(double circumference, bool isCircumference, bool) {
    if (isCircumference) {
        calculateFromRadius(circumference / (2 * PI));
    }
}

// ����� ��� ���������� ���������� �� �������
void Circle::calculateFromRadius(double r) {
    radius = r;
}

// ������ ��� ��������� ���������� ����������
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

// ������ ��� ��������� ���������� ����������
void Circle::setRadius(double r) {
    calculateFromRadius(r);
}

void Circle::setDiameter(double diameter) {
    calculateFromRadius(diameter / 2);
}

void Circle::setCircumference(double circumference) {
    calculateFromRadius(circumference / (2 * PI));
}

// ����� ��� �������� ����������� � ������ �����������
bool Circle::intersects(const Circle& other) const {
    double distance = sqrt(pow(this->radius - other.radius, 2));
    return distance <= (this->radius + other.radius);
}

// ����� ��� ��������, ����� �� ����� ������ ����������
bool Circle::contains(double x, double y) const {
    double distance = sqrt(x * x + y * y);
    return distance <= radius;
}

// ������� ��� ����������� ������� ����������
void printCircleProperties(const Circle& circle) {
    cout << "������: " << circle.getRadius() << endl;
    cout << "�������: " << circle.getDiameter() << endl;
    cout << "����� ����������: " << circle.getCircumference() << endl;
    cout << "�������: " << circle.getArea() << endl;
}

// ������� ��� ��������� �������������� ����� �� ������������
double getPositiveNumber() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "����������, ������� ������������� �����: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// ������� ��� ����������� ���� � ���������� ��������������� ��������
void displayMenu() {
    Circle circle(0);

    while (true) {
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

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 0 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�������� �����. ����������, �������� ���������� �������." << endl;
            continue;
        }

        double value;
        double x, y;
        Circle otherCircle(0);

        switch (choice) {
        case 1:
            cout << "������� ������ ����������: ";
            value = getPositiveNumber();
            circle = Circle(value);
            break;
        case 2:
            cout << "������� ������� ����������: ";
            value = getPositiveNumber();
            circle = Circle(value, true);
            break;
        case 3:
            cout << "������� ����� ����������: ";
            value = getPositiveNumber();
            circle = Circle(value, true, true);
            break;
        case 4:
            cout << "������� ����� ������ ����������: ";
            value = getPositiveNumber();
            circle.setRadius(value);
            break;
        case 5:
            cout << "������� ����� ������� ����������: ";
            value = getPositiveNumber();
            circle.setDiameter(value);
            break;
        case 6:
            cout << "������� ����� ����� ����������: ";
            value = getPositiveNumber();
            circle.setCircumference(value);
            break;
        case 7:
            cout << "������� ������ ������ ����������: ";
            value = getPositiveNumber();
            otherCircle = Circle(value);
            if (circle.intersects(otherCircle)) {
                cout << "���������� ������������." << endl;
            }
            else {
                cout << "���������� �� ������������." << endl;
            }
            break;
        case 8:
            cout << "������� ���������� ����� (x � y): ";
            cin >> x >> y;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "�������� ����. ����������, ������� �������� �������� ��� x � y." << endl;
            }
            else {
                if (circle.contains(x, y)) {
                    cout << "����� ����� ������ ����������." << endl;
                }
                else {
                    cout << "����� �� ����� ������ ����������." << endl;
                }
            }
            break;
        case 9:
            printCircleProperties(circle);
            break;
        case 0:
            return;
        default:
            cout << "�������� �����. ����������, �������� ���������� �������." << endl;
            break;
        }
    }
}