#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

class Parallelogram {
public:
    Parallelogram(double a, double b, double alpha);
    double getSideA() const;
    double getSideB() const;
    double getAngleA() const;
    double getAngleB() const;
    double getArea() const;
    double getPerimeter() const;

private:
    double a, b, alpha;
    double calculateAngleB() const;
};

#endif // PARALLELOGRAM_H
