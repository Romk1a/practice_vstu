#include <iostream>
#include "circle.cpp"
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");

    double radius;

    cout << "Введите радиус окружности: ";
    cin >> radius;

    Circle circle(radius);

    double perimeter = circle.calculatePerimeter();
    double area = circle.calculateArea();

    cout << "Периметр окружности: " << perimeter << endl;
    cout << "Площадь окружности: " << area << endl;

    return 0;
}