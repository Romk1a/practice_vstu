#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>

class Circle {
private:
    double radius;

public:
    // ����������� �� �������
    Circle(double radius);
    // ����������� �� ��������
    Circle(double diameter, bool isDiameter);
    // ����������� �� ����� ����������
    Circle(double circumference, bool isCircumference, bool unused);

    // ��������� �������
    double getRadius() const;
    // ��������� �������
    void setRadius(double radius);

    // ��������� ��������
    double getDiameter() const;
    // ��������� ��������
    void setDiameter(double diameter);

    // ��������� ����� ����������
    double getCircumference() const;
    // ��������� ����� ����������
    void setCircumference(double circumference);

    // ��������� �������
    double getArea() const;

    // �������� ����������� � ������ �����������
    bool intersects(const Circle& other) const;
    // �������� �� ��������� �����
    bool contains(double x, double y) const;
};

void displayMenu();
double getPositiveDouble(const std::string& prompt);
void userMenu();

#endif // CIRCLE_H