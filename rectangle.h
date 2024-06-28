#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double width;
    double height;

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

    // Методы для вычислений
    double area() const;
    double perimeter() const;
    double diagonal() const;
};

void displayMenu();
void handleMenu(Rectangle& rect);

#endif // FIGURA_H
