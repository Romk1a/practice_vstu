#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>
#include <cmath>

class Trapezoid {
public:
    // Конструктор
    Trapezoid();
    
    // Методы для задания параметров трапеции
    bool setBasesAndHeight(double a, double b, double h);
    bool setDiagonalsAndAngle(double d1, double d2, double angle);
    bool setMedianAndHeight(double median, double h);
    
    // Метод для вычисления свойств
    void computeProperties();
    
    // Метод для отображения свойств
    void displayProperties() const;
    
    // Метод для проверки равнобедренности трапеции
    bool isIsosceles() const;

    // Геттеры
    double getBase1() const { return base1; }
    double getBase2() const { return base2; }
    double getHeight() const { return height; }
    double getArea() const { return area; }
    double getPerimeter() const { return perimeter; }

private:
    // Свойства трапеции
    double base1, base2, height, diagonal1, diagonal2, angle, median;
    double side, area, perimeter;
    double angleA, angleB, angleC, angleD;

    // Вспомогательные функции
    void computeAngles();
    void resetProperties();
};

// Утилитные функции
bool isValidNumber(double value);
bool isPositive(double value);

// Функция меню
void displayMenu4();

#endif // TRAPEZOID_H
