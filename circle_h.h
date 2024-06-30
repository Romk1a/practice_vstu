#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    // Конструкторы
    Circle(double radius);
    Circle(double diameter, bool isDiameter);
    Circle(double circumference, bool isCircumference, bool);

    // Методы для получения параметров
    double getRadius() const;
    double getDiameter() const;
    double getCircumference() const;
    double getArea() const;

    // Методы для изменения параметров
    void setRadius(double radius);
    void setDiameter(double diameter);
    void setCircumference(double circumference);

    // Методы для проверки пересечений и включений
    bool intersects(const Circle& other) const;
    bool contains(double x, double y) const;

private:
    double radius;
    void calculateFromRadius(double r);
};

// Функция для отображения меню и выполнения соответствующих действий
void displayMenu();

#endif