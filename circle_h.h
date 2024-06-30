#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>

class Circle {
private:
    double radius;

public:
    // Конструктор по радиусу
    Circle(double radius);
    // Конструктор по диаметру
    Circle(double diameter, bool isDiameter);
    // Конструктор по длине окружности
    Circle(double circumference, bool isCircumference, bool unused);

    // Получение радиуса
    double getRadius() const;
    // Установка радиуса
    void setRadius(double radius);

    // Получение диаметра
    double getDiameter() const;
    // Установка диаметра
    void setDiameter(double diameter);

    // Получение длины окружности
    double getCircumference() const;
    // Установка длины окружности
    void setCircumference(double circumference);

    // Получение площади
    double getArea() const;

    // Проверка пересечения с другой окружностью
    bool intersects(const Circle& other) const;
    // Проверка на вхождение точки
    bool contains(double x, double y) const;
};

void displayMenu();
double getPositiveDouble(const std::string& prompt);
void userMenu();

#endif // CIRCLE_H