#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>

class Circle {
public:
    Circle(double radius) : radius(radius) {}

    double getRadius() const { return radius; }
    double getPerimeter() const { return 2 * M_PI * radius; }
    double getArea() const { return M_PI * radius * radius; }

private:
    double radius;
};

class Triangle {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        double s = getPerimeter() / 2;
        area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getPerimeter() const { return a + b + c; }
    double getArea() const { return area; }

private:
    double a, b, c;
    double area;
};

class Rectangle {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double getPerimeter() const { return 2 * (width + height); }
    double getArea() const { return width * height; }

private:
    double width, height;
};

class Trapezoid {
public:
    Trapezoid(double a, double b, double c, double d, double height) 
        : a(a), b(b), c(c), d(d), height(height) {}

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getD() const { return d; }
    double getHeight() const { return height; }
    double getPerimeter() const { return a + b + c + d; }
    double getArea() const { return ((a + b) / 2) * height; }

private:
    double a, b, c, d, height;
};

class Parallelogram {
public:
    Parallelogram(double base, double side, double height) 
        : base(base), side(side), height(height) {}

    double getBase() const { return base; }
    double getSide() const { return side; }
    double getHeight() const { return height; }
    double getPerimeter() const { return 2 * (base + side); }
    double getArea() const { return base * height; }

private:
    double base, side, height;
};

#endif // GEOMETRY_H
