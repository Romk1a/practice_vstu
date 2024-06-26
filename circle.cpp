#include "Circle_h.h"
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::calculatePerimeter() const {
    return 2 * PI * radius;
}

double Circle::calculateArea() const {
    return PI * radius * radius;
}