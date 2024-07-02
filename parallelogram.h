#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

class Parallelogram {
public:
    Parallelogram(double a, double b, double alpha);
    Parallelogram(double a, double b, double c, double d);
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
    double calculateSide(int index) const;
    double calculateAngle(int index) const;

private:
    double a, b, c, d;
    double alpha, beta, gamma, delta;
};

void showMenu();

#endif // PARALLELOGRAM_H
