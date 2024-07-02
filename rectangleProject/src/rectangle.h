#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double width;
    double height;
    bool isValid;

public:
    // Конструкторы
    Rectangle();
    Rectangle(double w, double h);

    // Геттеры и сеттеры
    double getWidth() const;
    double getHeight() const;
    void setWidth(double w);
    void setHeight(double h);
    void setWidthAndHeight(double w, double h);
    void setWidthAndDiagonal(double w, double d);
    void setHeightAndDiagonal(double h, double d);
    bool checkValidity() const; // Добавлено объявление метода checkValidity

    // Методы для вычислений
    double area() const;
    double perimeter() const;
    double diagonal() const;
};

void displayMenu();
void handleMenu(Rectangle& rect);

#endif // RECTANGLE_H
#pragma once