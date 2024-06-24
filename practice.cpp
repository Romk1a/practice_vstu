#include <iostream>
#include "Geometry.h"

int main()
{
  Circle circle(5.0);
  std::cout << "Периметр окружности: " << circle.getPerimeter() << std::endl;
  std::cout << "Площадь окружности: " << circle.getArea() << std::endl;

  Triangle triangle(3.0, 4.0, 5.0);
  std::cout << "Периметр треугольника: " << triangle.getPerimeter() << std::endl;
  std::cout << "Площадь треугольника: " << triangle.getArea() << std::endl;

  Rectangle rectangle(4.0, 5.0);
  std::cout << "Периметр прямоугольника: " << rectangle.getPerimeter() << std::endl;
  std::cout << "Площадь прямоугольника: " << rectangle.getArea() << std::endl;

  Trapezoid trapezoid(3.0, 4.0, 5.0, 6.0, 2.5);
  std::cout << "Периметр трапеции: " << trapezoid.getPerimeter() << std::endl;
  std::cout << "Площадь трапеции: " << trapezoid.getArea() << std::endl;

  Parallelogram parallelogram(4.0, 5.0, 3.0);
  std::cout << "Периметр параллелограмма: " << parallelogram.getPerimeter() << std::endl;
  std::cout << "Площадь параллелограмма: " << parallelogram.getArea() << std::endl;

  return 0;
}
