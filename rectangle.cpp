#include "rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() : width(0), height(0) {}

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

bool Rectangle::checkValidity() const {
    return isValid;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setWidth(double w) {
    width = w;
}

void Rectangle::setHeight(double h) {
    height = h;
}

void Rectangle::setWidthAndHeight(double w, double h) {
    width = w;
    height = h;
}

void Rectangle::setWidthAndDiagonal(double w, double d) {
    width = w;
    height = std::sqrt(d * d - w * w);
}

void Rectangle::setHeightAndDiagonal(double h, double d) {
    height = h;
    width = std::sqrt(d * d - h * h);
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

double Rectangle::diagonal() const {
    return std::sqrt(width * width + height * height);
}

void displayMenu() {
    std::cout << "1. Установить ширину и высоту\n";
    std::cout << "2. Установить ширину и диагональ\n";
    std::cout << "3. Установить высоту и диагональ\n";
    std::cout << "4. Получить ширину и высоту\n";
    std::cout << "5. Вычислить площадь\n";
    std::cout << "6. Вычислить периметр\n";
    std::cout << "7. Вычислить диагональ\n";
    std::cout << "8. Выход\n";
}

void handleMenu(Rectangle& rect) {
    int choice;
    double width, height, diagonal;
    while (true) {
        displayMenu();
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите ширину: ";
            std::cin >> width;
            std::cout << "Введите высоту: ";
            std::cin >> height;
            rect.setWidthAndHeight(width, height);
            break;
        case 2:
            std::cout << "Введите ширину: ";
            std::cin >> width;
            std::cout << "Введите диагональ: ";
            std::cin >> diagonal;
            rect.setWidthAndDiagonal(width, diagonal);
            break;
        case 3:
            std::cout << "Введите высоту: ";
            std::cin >> height;
            std::cout << "Введите диагональ: ";
            std::cin >> diagonal;
            rect.setHeightAndDiagonal(height, diagonal);
            break;
        case 4:
            std::cout << "Ширина: " << rect.getWidth() << ", Высота: " << rect.getHeight() << "\n";
            break;
        case 5:
            std::cout << "Площадь: " << rect.area() << "\n";
            break;
        case 6:
            std::cout << "Периметр: " << rect.perimeter() << "\n";
            break;
        case 7:
            std::cout << "Диагональ: " << rect.diagonal() << "\n";
            break;
        case 8:
            return;
        default:
            std::cout << "Неверный выбор. Попробуйте еще раз.\n";
        }
    }
}

void runMenu() {
    Rectangle rect;
    handleMenu(rect);
}
