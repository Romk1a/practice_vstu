

#include "rectangle.cpp"

int main() {
    // Создание объекта прямоугольника
    Rectangle rect(7.0, 4.0);

    // Вывод результатов
    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Height: " << rect.getHeight() << std::endl;
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;
    std::cout << "Diagonal: " << rect.diagonal() << std::endl;

    return 0;
}
