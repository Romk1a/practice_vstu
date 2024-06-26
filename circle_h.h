#ifndef CIRC_GEOMETRY_H
#define CIRC_GEOMETRY_H

#ifdef _WIN64
#ifdef CIRC_GEOMETRY_EXPORTS
#define CIRC_GEOMETRY_API __declspec(dllexport)
#else
#define CIRC_GEOMETRY_API __declspec(dllimport)
#endif
#else
#define CIRC_GEOMETRY_API
#endif

class CIRC_GEOMETRY_API Circle {
public:
    Circle(double radius);
    double calculatePerimeter() const;
    double calculateArea() const;

private:
    double radius;
    static constexpr double PI = 3.14159265358979323846;
};

#endif // CIRC_GEOMETRY_H