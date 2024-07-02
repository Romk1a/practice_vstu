#include <cmath>
#include "Parallelogram.h"

// Конструкторы
Parallelogram::Parallelogram() : a(0), b(0), c(0), d(0), alpha(0), beta(0), gamma(0), delta(0) {}
Parallelogram::Parallelogram(double a, double b, double alpha) : a(a), b(b), alpha(alpha), beta(180.0 - alpha), c(a), d(b) {}
Parallelogram::Parallelogram(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {
    alpha = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / M_PI;
    beta = acos((a * a + d * d - c * c) / (2 * a * d)) * 180.0 / M_PI;
    gamma = 180.0 - alpha;
    delta = 180.0 - beta;
}
Parallelogram::Parallelogram(double alpha, double beta, double a, double b) : alpha(alpha), beta(beta), a(a), b(b) {
    c = sqrt(a * a + b * b - 2 * a * b * cos((alpha + beta) * M_PI / 180.0));
    d = sqrt(a * a + b * b + 2 * a * b * cos((alpha + beta) * M_PI / 180.0));
    gamma = 180.0 - alpha;
    delta = 180.0 - beta;
}

// Геттеры и сеттеры
double Parallelogram::getSideA() const { return a; }
double Parallelogram::getSideB() const { return b; }
double Parallelogram::getSideC() const { return c; }
double Parallelogram::getSideD() const { return d; }
double Parallelogram::getAngleA() const { return alpha; }
double Parallelogram::getAngleB() const { return beta; }
double Parallelogram::getAngleC() const { return gamma; }
double Parallelogram::getAngleD() const { return delta; }
void Parallelogram::setSides(double a, double b, double c, double d) { this->a = a; this->b = b; this->c = c; this->d = d; }
void Parallelogram::setAngles(double alpha, double beta, double gamma, double delta) { this->alpha = alpha; this->beta = beta; this->gamma = gamma; this->delta = delta; }

// Методы вычислений
double Parallelogram::calculateArea() const { return a * b * sin(alpha * M_PI / 180.0); }
double Parallelogram::calculatePerimeter() const { return a + b + c + d; }
double Parallelogram::calculateSide(int index) const {
    switch (index) {
    case 0: return a;
    case 1: return b;
    case 2: return c;
    case 3: return d;
    default: return 0.0;
    }
}
double Parallelogram::calculateAngle(int index) const {
    switch (index) {
    case 0: return alpha;
    case 1: return beta;
    case 2: return gamma;
    case 3: return delta;
    default: return 0.0;
    }
}
