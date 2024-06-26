#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <optional>

class Triangle {
private:
    std::optional<double> a, b, c; // Стороны треугольника
    std::optional<double> A, B, C; // Углы треугольника в градусах
    std::optional<double> x1, y1, x2, y2, x3, y3; // Координаты вершин
    std::optional<double> area;    // Площадь треугольника
    std::optional<double> perimeter; // Периметр треугольника

    static constexpr double PI = 3.141592653589793;

    double degreesToRadians(double degrees) const;
    double radiansToDegrees(double radians) const;
    std::optional<double> calculateAngle(double side1, double side2, double side3) const;

    void resetCalculations();
    void calculatePropertiesFromCoordinates();
    void calculatePropertiesFromSides();
    void calculatePropertiesFromAngles();

public:
    Triangle() = default;

    void setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3);
    void setSides(double side_a, double side_b, double side_c);
    void setAngles(double angle_A, double angle_B, double angle_C);
    void setSideAndTwoAngles(double side, double angle1, double angle2);
    void setTwoSidesAndAngle(double side1, double side2, double angle);

    std::optional<double> getArea();
    std::optional<double> getPerimeter();
    void displayProperties() const;
};

#endif // TRIANGLE_H
