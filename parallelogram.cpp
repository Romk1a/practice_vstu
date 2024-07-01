#include <cmath>
#include "Parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double alpha) : a(a), b(b), alpha(alpha) {}

double Parallelogram::getSideA() const { return a; }
double Parallelogram::getSideB() const { return b; }
double Parallelogram::getAngleA() const { return alpha; }
double Parallelogram::getAngleB() const { return calculateAngleB(); }

double Parallelogram::getArea() const { return a * b * sin(alpha * M_PI / 180.0); }
double Parallelogram::getPerimeter() const { return 2 * (a + b); }

double Parallelogram::calculateAngleB() const {
    return 180.0 - alpha;
}
