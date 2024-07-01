#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    // ������������
    Circle(double radius);
    Circle(double diameter, bool isDiameter);
    Circle(double circumference, bool isCircumference, bool);

    // ������ ��� ��������� ����������
    double getRadius() const;
    double getDiameter() const;
    double getCircumference() const;
    double getArea() const;

    // ������ ��� ��������� ����������
    void setRadius(double radius);
    void setDiameter(double diameter);
    void setCircumference(double circumference);

    // ������ ��� �������� ����������� � ���������
    bool intersects(const Circle& other) const;
    bool contains(double x, double y) const;

private:
    double radius;
    void calculateFromRadius(double r);
};

// ������� ��� ����������� ���� � ���������� ��������������� ��������
void displayMenu();

#endif