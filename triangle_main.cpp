#include <iostream>
#include "triangle.h"

void displayMenu() {
    std::cout << "Калькулятор свойств треугольника\n";
    std::cout << "1. Задать координаты вершин\n";
    std::cout << "2. Задать стороны\n";
    std::cout << "3. Задать углы\n";
    std::cout << "4. Задать одну сторону и два угла\n";
    std::cout << "5. Задать две стороны и один угол\n";
    std::cout << "6. Вычислить свойства\n";
    std::cout << "7. Выйти\n";
}

int main() {
    Triangle triangle;
    int choice;
    bool exit = false;

    while (!exit) {
        displayMenu();
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double x1, y1, x2, y2, x3, y3;
                std::cout << "Введите координаты первой вершины (x1 y1): ";
                std::cin >> x1 >> y1;
                std::cout << "Введите координаты второй вершины (x2 y2): ";
                std::cin >> x2 >> y2;
                std::cout << "Введите координаты третьей вершины (x3 y3): ";
                std::cin >> x3 >> y3;
                triangle.setCoordinates(x1, y1, x2, y2, x3, y3);
                break;
            }
            case 2: {
                double a, b, c;
                std::cout << "Введите сторону a: ";
                std::cin >> a;
                std::cout << "Введите сторону b: ";
                std::cin >> b;
                std::cout << "Введите сторону c: ";
                std::cin >> c;
                triangle.setSides(a, b, c);
                break;
            }
            case 3: {
                double A, B, C;
                bool validAngles = false;
                while (!validAngles) {
                    std::cout << "Введите угол A (в градусах): ";
                    std::cin >> A;
                    std::cout << "Введите угол B (в градусах): ";
                    std::cin >> B;
                    std::cout << "Введите угол C (в градусах): ";
                    std::cin >> C;
                    if (A + B + C == 180.0) {
                        validAngles = true;
                        triangle.setAngles(A, B, C);
                    } else {
                        std::cout << "Ошибка: сумма углов должна быть равна 180 градусам. Попробуйте снова.\n";
                    }
                }
                break;
            }
            case 4: {
                double side, angle1, angle2;
                std::cout << "Введите сторону: ";
                std::cin >> side;
                std::cout << "Введите первый угол (в градусах): ";
                std::cin >> angle1;
                std::cout << "Введите второй угол (в градусах): ";
                std::cin >> angle2;
                triangle.setSideAndTwoAngles(side, angle1, angle2);
                break;
            }
            case 5: {
                double side1, side2, angle;
                std::cout << "Введите первую сторону: ";
                std::cin >> side1;
                std::cout << "Введите вторую сторону: ";
                std::cin >> side2;
                std::cout << "Введите угол (в градусах): ";
                std::cin >> angle;
                triangle.setTwoSidesAndAngle(side1, side2, angle);
                break;
            }
            case 6: {
                triangle.displayProperties();
                break;
            }
            case 7: {
                exit = true;
                break;
            }
            default: {
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
        }
    }

    return 0;
}
