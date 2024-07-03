#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

class Parallelogram {
public:
    // Конструктор с двумя сторонами и углом
    Parallelogram(double a, double b, double alpha);
    // Конструктор с четырьмя сторонами
    Parallelogram(double a, double b, double c, double d, int);
    // Конструктор с двумя сторонами и двумя углами
    Parallelogram(double alphaRad, double betaRad, double a, double b);

    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double getSideD() const;
    double getAngleA() const;
    double getAngleB() const;
    double getAngleC() const;
    double getAngleD() const;

    double calculateArea() const;
    double calculatePerimeter() const;

private:
    double a, b, c, d;
    double alpha, beta, gamma, delta;
};

void showMenu5();

#endif // PARALLELOGRAM_H
