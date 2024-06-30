#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

class Triangle {
private:
    double a, b, c; // Стороны треугольника
    double A, B, C; // Углы треугольника в градусах
    double x1, y1, x2, y2, x3, y3; // Координаты вершин
    double area;    // Площадь треугольника
    double perimeter; // Периметр треугольника

    double degreesToRadians(double degrees) const;
    double radiansToDegrees(double radians) const;
    double calculateAngle(double side1, double side2, double side3) const;

    void resetCalculations();
    void calculatePropertiesFromCoordinates();
    void calculatePropertiesFromSides();
    void calculatePropertiesFromAngles();

public:
    Triangle();

    void setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3);
    void setSides(double side_a, double side_b, double side_c);
    void setAngles(double angle_A, double angle_B, double angle_C);
    void setSideAndTwoAngles(double side, double angle1, double angle2);
    void setTwoSidesAndAngle(double side1, double side2, double angle);

    double getArea();
    double getPerimeter();
    void displayProperties() const;

    bool isValidTriangleBySides(double side_a, double side_b, double side_c) const;
    bool isValidTriangleByAngles(double angle_A, double angle_B, double angle_C) const;
    bool isValidAngle(double angle) const;
};

void menu();

#endif // TRIANGLE_H
