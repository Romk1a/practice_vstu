#include <iostream>
#include "circle.cpp"
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");

    double radius = 5.0;

    Circle circle(radius);

    double perimeter = circle.calculatePerimeter();
    double area = circle.calculateArea();

    cout << "Радиус окружности: " << radius << endl;
    cout << "Периметр окружности: " << perimeter << endl;
    cout << "Площадь окружности: " << area << endl;

    return 0;
}