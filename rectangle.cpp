#include <iostream>
#include <cmath>

class Rectangle {
private:
    double width;
    double height;

public:
    // Конструкторы
    Rectangle() : width(0), height(0) {}
    Rectangle(double w, double h) : width(w), height(h) {}

    // Геттеры и сеттеры
    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }

    // Методы для вычислений
    double area() const {
        return width * height;
    }

    double perimeter() const {
        return 2 * (width + height);
    }

    double diagonal() const {
        return std::sqrt(width * width + height * height);
    }
};

// Точка входа для тестирования библиотеки (опционально)
#ifdef BUILD_TEST

#endif
