#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

class Parallelogram {
public:
    // ������������
    Parallelogram();
    Parallelogram(double a, double b, double alpha);
    Parallelogram(double a, double b, double c, double d);
    Parallelogram(double alpha, double beta, double a, double b);

    // ������� � �������
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double getSideD() const;
    double getAngleA() const;
    double getAngleB() const;
    double getAngleC() const;
    double getAngleD() const;
    void setSides(double a, double b, double c, double d);
    void setAngles(double alpha, double beta, double gamma, double delta);

    // ������ ����������
    double calculateArea() const;
    double calculatePerimeter() const;
    double calculateSide(int index) const;
    double calculateAngle(int index) const;

private:
    double a, b, c, d;
    double alpha, beta, gamma, delta;
};

#endif // PARALLELOGRAM_H
