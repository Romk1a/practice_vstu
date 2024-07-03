#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>

using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double radius);
    Circle(double diameter, bool isDiameter);
    Circle(double circumference, bool isCircumference, bool unused);

    double getRadius() const;
    void setRadius(double radius);

    double getDiameter() const;
    void setDiameter(double diameter);

    double getCircumference() const;
    void setCircumference(double circumference);

    double getArea() const;
    double calculateAreaFromRadius(double radius) const;
    double calculateAreaFromDiameter(double diameter) const;
    double calculateAreaFromCircumference(double circumference) const;

    bool intersects(const Circle& other) const;
    bool contains(double x, double y) const;
};

void displayMenu1();
double getPositiveDouble(const std::string& prompt);
void userMenu1();

#endif // CIRCLE_H