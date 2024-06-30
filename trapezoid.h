#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <array>
#include <cmath>

class Trapezoid {
public:
    double a, b, c, d; // Стороны трапеции
    double alpha, beta, gamma, delta; // Углы при основаниях
    double height; // Высота трапеции
    double area; // Площадь трапеции
    double perimeter; // Периметр трапеции
    double e, f; // Диагонали трапеции
    double theta; // Угол между диагоналями

public:
    Trapezoid(); // Конструктор по умолчанию

    // Методы для установки значений
    void setVerticesCoordinates(const std::array<double, 8>& vertices);
    void setSides(double a, double b, double c, double d);
    void setAngles(double angle_A, double angle_B, double angle_C, double angle_D);
    void setSidesAndHeight(double a, double b, double height);
    void setDiagonalsAndAngle(double diag1, double diag2, double angle);
    void setMiddleLineAndHeight(double m, double height);
    void calculateFromDiagonalsAndAngle(double diagonal_e, double diagonal_f, double angle_theta);

    // Методы для вычисления свойств
    void calculateProperties();
    void calculateAnglesFromSides();
    void calculateAreaAndPerimeter();

    // Вывод свойств трапеции
    void printProperties() const;

    // Меню для взаимодействия с пользователем
    void menu();
    bool isValidTrapezoidBySidesAndAngles() const;
};

// Функция проверки валидности трапеции по углам
bool isValidTrapezoidByAngles(double angle_A, double angle_B, double angle_C, double angle_D);

#endif // TRAPEZOID_H
