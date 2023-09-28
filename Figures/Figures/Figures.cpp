#include "pch.h"
#include "Figures.h"

Point::Point() { X = Y = Z = 0; }
Point::Point(double x, double y, double z) { X = x; Y = y; Z = z; }
double Point::GetX() { return X; }
double Point::GetY() { return Y; }
double Point::GetZ() { return Z; }

Figure::Figure() { R = 1; Point(); }
Figure::Figure(double R1, double X1, double Y1, double Z1) { R = R1; centre = Point(X1, Y1, Z1); }

Circle::Circle() :Figure() {}
Circle::Circle(double R1, double X1, double Y1) : Figure(R1, X1, Y1, 0) {}
double Circle::GetRadius() { return R; }
Point Circle::GetPoint(double t) {
    double x = centre.GetX() + R * cos(t);
    double y = centre.GetY() + R * sin(t);
    return Point(x, y, 0);
}
std::vector<double> Circle::GetDerivatives(double t) {
    double dx = -R * sin(t);
    double dy = R * cos(t);
    return std::vector<double>{dx, dy};
}

Ellipses::Ellipses() : Figure() { R2 = 1; }
Ellipses::Ellipses(double R1, double R2_1, double X1, double Y1) : Figure(R1, X1, Y1, 0) { R2 = R2_1; }
Point Ellipses::GetPoint(double t) {
    double x = centre.GetX() + R * cos(t);
    double y = centre.GetY() + R2 * sin(t);
    return Point(x, y, 0);
}
std::vector<double> Ellipses::GetDerivatives(double t) {
    double dx = -R * sin(t);
    double dy = R2 * cos(t);
    return std::vector<double>{dx, dy};
}

Helixes::Helixes() : Figure() {
    step = 1;
    count_step = 5;
}
Helixes::Helixes(double R1, double step1, int step_count, double X1, double Y1, double Z1) : Figure(R1, X1, Y1, Z1) {
    step = step1;
    count_step = step_count;
}
Point Helixes::GetPoint(double t) {
    double x = centre.GetX() + R * cos(t);
    double y = centre.GetY() + R * sin(t);
    double z = step * t;
    return Point(x, y, z);
}
std::vector<double> Helixes::GetDerivatives(double t) {
    double dx = -R * sin(t);
    double dy = R * cos(t);
    double dz = step;
    return std::vector<double>{dx, dy, dz};
}
