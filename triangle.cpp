#include "triangle.h"
#include <cmath>
#include <limits>

const double PI = 3.141592653589793;

Triangle::Triangle() : a(0), b(0), c(0), A(0), B(0), C(0), x1(0), y1(0), x2(0), y2(0), x3(0), y3(0), area(0), perimeter(0) {}

double Triangle::degreesToRadians(double degrees) const {
    return degrees * PI / 180.0;
}

double Triangle::radiansToDegrees(double radians) const {
    return radians * 180.0 / PI;
}

double Triangle::calculateAngle(double side1, double side2, double side3) const {
    return radiansToDegrees(std::acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2)));
}

void Triangle::resetCalculations() {
    area = 0;
    perimeter = 0;
}

void Triangle::calculatePropertiesFromCoordinates() {
    a = std::hypot(x2 - x1, y2 - y1);
    b = std::hypot(x3 - x2, y3 - y2);
    c = std::hypot(x3 - x1, y3 - y1);

    if (isValidTriangleBySides(a, b, c)) {
        calculatePropertiesFromSides();
    } else {
        std::cerr << "Ошибка: координаты задают несуществующий треугольник.\n";
    }
}

void Triangle::calculatePropertiesFromSides() {
    if (isValidTriangleBySides(a, b, c)) {
        perimeter = a + b + c;
        double s = perimeter / 2.0;
        area = std::sqrt(s * (s - a) * (s - b) * (s - c));
        A = calculateAngle(b, c, a);
        B = calculateAngle(a, c, b);
        C = calculateAngle(a, b, c);
    } else {
        std::cerr << "Ошибка: стороны задают несуществующий треугольник.\n";
    }
}

void Triangle::calculatePropertiesFromAngles() {
    double angleA = degreesToRadians(A);
    double angleB = degreesToRadians(B);
    double angleC = degreesToRadians(C);
    b = a * std::sin(angleB) / std::sin(angleA);
    c = a * std::sin(angleC) / std::sin(angleA);
    calculatePropertiesFromSides();
}

bool Triangle::isValidTriangleBySides(double side_a, double side_b, double side_c) const {
    return side_a > 0 && side_b > 0 && side_c > 0 &&
           side_a + side_b > side_c && side_a + side_c > side_b && side_b + side_c > side_a;
}

bool Triangle::isValidTriangleByAngles(double angle_A, double angle_B, double angle_C) const {
    return angle_A > 0 && angle_B > 0 && angle_C > 0 &&
           std::abs(angle_A + angle_B + angle_C - 180.0) < 1e-9;
}

bool Triangle::isValidAngle(double angle) const {
    return angle > 0 && angle < 180;
}

void Triangle::setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
    resetCalculations();
    calculatePropertiesFromCoordinates();
}

void Triangle::setSides(double side_a, double side_b, double side_c) {
    if (isValidTriangleBySides(side_a, side_b, side_c)) {
        a = side_a;
        b = side_b;
        c = side_c;
        resetCalculations();
        calculatePropertiesFromSides();
    } else {
        std::cerr << "Ошибка: стороны задают несуществующий треугольник.\n";
    }
}

void Triangle::setAngles(double angle_A, double angle_B, double angle_C) {
    if (isValidTriangleByAngles(angle_A, angle_B, angle_C)) {
        A = angle_A;
        B = angle_B;
        C = angle_C;
        if (A == 60 && B == 60 && C == 60) {
            std::cout << "Данный треугольник может соответствовать любому правильному треугольнику.\n";
        }
        std::cerr << "Недостаточно данных для вычисления сторон, периметра и площади.\n";
    } else {
        std::cerr << "Ошибка: углы задают несуществующий треугольник или сумма углов не равна 180 градусам.\n";
    }
}

void Triangle::setSideAndTwoAngles(double side, double angle1, double angle2) {
    if (side > 0 && isValidAngle(angle1) && isValidAngle(angle2) && (angle1 + angle2) < 180) {
        a = side;
        A = angle1;
        B = angle2;
        C = 180.0 - angle1 - angle2;
        resetCalculations();
        calculatePropertiesFromAngles();
    } else {
        std::cerr << "Ошибка: введены некорректные значения для стороны или углов.\n";
    }
}

void Triangle::setTwoSidesAndAngle(double side1, double side2, double angle) {
    if (side1 > 0 && side2 > 0 && isValidAngle(angle)) {
        a = side1;
        b = side2;
        A = angle;
        resetCalculations();
        c = std::sqrt(a * a + b * b - 2 * a * b * std::cos(degreesToRadians(A)));
        calculatePropertiesFromSides();
    } else {
        std::cerr << "Ошибка: введены некорректные значения для сторон или угла.\n";
    }
}

double Triangle::getArea() {
    if (area == 0 && a != 0 && b != 0 && c != 0) {
        double s = (a + b + c) / 2.0;
        area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    return area;
}

double Triangle::getPerimeter() {
    if (perimeter == 0 && a != 0 && b != 0 && c != 0) {
        perimeter = a + b + c;
    }
    return perimeter;
}

void Triangle::displayProperties() const {
    if (a != 0 && b != 0 && c != 0) {
        std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << "\n";
    }
    if (A != 0 && B != 0 && C != 0) {
        std::cout << "Углы: A = " << A << " градусов, B = " << B << " градусов, C = " << C << " градусов\n";
    }
    if (area != 0) {
        std::cout << "Площадь: " << area << "\n";
    } else {
        std::cout << "Недостаточно данных для вычисления площади.\n";
    }
    if (perimeter != 0) {
        std::cout << "Периметр: " << perimeter << "\n";
    } else {
        std::cout << "Недостаточно данных для вычисления периметра.\n";
    }
}

void displayMenu2() {
    std::cout << "Меню: Выберите способ задания треугольника\n";
    std::cout << "1. Задать координаты вершин\n";
    std::cout << "2. Задать стороны\n";
    std::cout << "3. Задать углы\n";
    std::cout << "4. Задать одну сторону и два угла\n";
    std::cout << "5. Задать две стороны и один угол\n";
    std::cout << "6. Вычислить свойства\n";
    std::cout << "7. Выйти\n";
}

void clearInput() {
    std::cin.clear(); // clear the error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
}

void menu2() {
    Triangle triangle;
    int choice;
    bool exit = false;

    while (!exit) {
        displayMenu2();
        std::cout << "Выберите опцию: ";
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1: {
                double x1, y1, x2, y2, x3, y3;
                std::cout << "Введите координаты первой вершины (x1 y1): ";
                std::cin >> x1 >> y1;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введены некорректные значения. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                std::cout << "Введите координаты второй вершины (x2 y2): ";
                std::cin >> x2 >> y2;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введены некорректные значения. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                std::cout << "Введите координаты третьей вершины (x3 y3): ";
                std::cin >> x3 >> y3;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введены некорректные значения. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                triangle.setCoordinates(x1, y1, x2, y2, x3, y3);
                break;
            }
            case 2: {
                double a, b, c;
                std::cout << "Введите сторону a: ";
                std::cin >> a;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                std::cout << "Введите сторону b: ";
                std::cin >> b;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                std::cout << "Введите сторону c: ";
                std::cin >> c;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                triangle.setSides(a, b, c);
                break;
            }
            case 3: {
                double A, B, C;
                bool validAngles = false;
                while (!validAngles) {
                    std::cout << "Введите угол A (в градусах): ";
                    std::cin >> A;
                    if (std::cin.fail()) {
                        std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                        clearInput();
                        continue;
                    }
                    std::cout << "Введите угол B (в градусах): ";
                    std::cin >> B;
                    if (std::cin.fail()) {
                        std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                        clearInput();
                        continue;
                    }
                    std::cout << "Введите угол C (в градусах): ";
                    std::cin >> C;
                    if (std::cin.fail()) {
                        std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                        clearInput();
                        continue;
                    }
                    if (triangle.isValidTriangleByAngles(A, B, C)) {
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
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                std::cout << "Введите первый угол (в градусах): ";
                std::cin >> angle1;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                std::cout << "Введите второй угол (в градусах): ";
                std::cin >> angle2;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                triangle.setSideAndTwoAngles(side, angle1, angle2);
                break;
            }
            case 5: {
                double side1, side2, angle;
                std::cout << "Введите первую сторону: ";
                std::cin >> side1;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                std::cout << "Введите вторую сторону: ";
                std::cin >> side2;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
                std::cout << "Введите угол (в градусах): ";
                std::cin >> angle;
                if (std::cin.fail()) {
                    std::cerr << "Ошибка: введено некорректное значение. Попробуйте снова.\n";
                    clearInput();
                    continue;
                }
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
}

