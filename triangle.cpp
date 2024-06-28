#include "triangle.h"
#include <iostream>
#include <cmath>

double Triangle::degreesToRadians(double degrees) const {
    return degrees * PI / 180.0;
}

double Triangle::radiansToDegrees(double radians) const {
    return radians * 180.0 / PI;
}

std::optional<double> Triangle::calculateAngle(double side1, double side2, double side3) const {
    return radiansToDegrees(std::acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2)));
}

void Triangle::resetCalculations() {
    area.reset();
    perimeter.reset();
}

void Triangle::calculatePropertiesFromCoordinates() {
    if (x1 && y1 && x2 && y2 && x3 && y3) {
        a = std::hypot(x2.value() - x1.value(), y2.value() - y1.value());
        b = std::hypot(x3.value() - x2.value(), y3.value() - y2.value());
        c = std::hypot(x3.value() - x1.value(), y3.value() - y1.value());
        calculatePropertiesFromSides();
    }
}

void Triangle::calculatePropertiesFromSides() {
    if (a && b && c) {
        perimeter = a.value() + b.value() + c.value();
        double s = perimeter.value() / 2.0;
        area = std::sqrt(s * (s - a.value()) * (s - b.value()) * (s - c.value()));
        A = calculateAngle(b.value(), c.value(), a.value());
        B = calculateAngle(a.value(), c.value(), b.value());
        C = calculateAngle(a.value(), b.value(), c.value());
    }
}

void Triangle::calculatePropertiesFromAngles() {
    if (a && A && B && C) {
        double angleA = degreesToRadians(A.value());
        double angleB = degreesToRadians(B.value());
        double angleC = degreesToRadians(C.value());
        b = a.value() * std::sin(angleB) / std::sin(angleA);
        c = a.value() * std::sin(angleC) / std::sin(angleA);
        calculatePropertiesFromSides();
    }
}

void Triangle::setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
    resetCalculations();
    calculatePropertiesFromCoordinates();
}

void Triangle::setSides(double side_a, double side_b, double side_c) {
    a = side_a;
    b = side_b;
    c = side_c;
    resetCalculations();
    calculatePropertiesFromSides();
}

void Triangle::setAngles(double angle_A, double angle_B, double angle_C) {
    A = angle_A;
    B = angle_B;
    C = angle_C;
    resetCalculations();
    calculatePropertiesFromAngles();
}

void Triangle::setSideAndTwoAngles(double side, double angle1, double angle2) {
    a = side;
    A = angle1;
    B = angle2;
    C = 180.0 - angle1 - angle2;
    resetCalculations();
    calculatePropertiesFromAngles();
}

void Triangle::setTwoSidesAndAngle(double side1, double side2, double angle) {
    a = side1;
    b = side2;
    A = angle;
    resetCalculations();
    c = std::sqrt(a.value() * a.value() + b.value() * b.value() - 2 * a.value() * b.value() * std::cos(degreesToRadians(A.value())));
    calculatePropertiesFromSides();
}

std::optional<double> Triangle::getArea() {
    if (!area.has_value() && a.has_value() && b.has_value() && c.has_value()) {
        double s = (a.value() + b.value() + c.value()) / 2.0;
        area = std::sqrt(s * (s - a.value()) * (s - b.value()) * (s - c.value()));
    }
    return area;
}

std::optional<double> Triangle::getPerimeter() {
    if (!perimeter.has_value() && a.has_value() && b.has_value() && c.has_value()) {
        perimeter = a.value() + b.value() + c.value();
    }
    return perimeter;
}

void Triangle::displayProperties() const {
    if (a.has_value() && b.has_value() && c.has_value()) {
        std::cout << "Стороны: a = " << a.value() << ", b = " << b.value() << ", c = " << c.value() << "\n";
    }
    if (A.has_value() && B.has_value() && C.has_value()) {
        std::cout << "Углы: A = " << A.value() << " градусов, B = " << B.value() << " градусов, C = " << C.value() << " градусов\n";
    }
    if (area.has_value()) {
        std::cout << "Площадь: " << area.value() << "\n";
    } else {
        std::cout << "Недостаточно данных для вычисления площади.\n";
    }
    if (perimeter.has_value()) {
        std::cout << "Периметр: " << perimeter.value() << "\n";
    } else {
        std::cout << "Недостаточно данных для вычисления периметра.\n";
    }
}
