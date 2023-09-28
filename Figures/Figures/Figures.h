#pragma once

#include "pch.h"
#include <windows.h>
#include <math.h>
#include <vector>

#ifdef FIGURES_EXPORTS
#define LIB __declspec(dllexport)
#else
#define LIB __declspec(dllimport)
#endif

class LIB Point {
    double X;
    double Y;
    double Z;
public:
    Point();
    Point(double x, double y, double z);
    double GetX();
    double GetY();
    double GetZ();
};

class LIB Figure {
protected:
    double R;
    Point centre;
public:
    Figure();
    Figure(double R1, double X1, double Y1, double Z1);
    virtual ~Figure() {}
    virtual Point GetPoint(double t) = 0;
    virtual std::vector<double> GetDerivatives(double t) = 0;
};

class LIB Circle : public Figure {
public:
    Circle();
    Circle(double R1, double X1, double Y1);
    Point GetPoint(double t) override;
    std::vector<double> GetDerivatives(double t) override;
    double GetRadius();
};

class LIB Ellipses : public Figure {
    double R2;
public:
    Ellipses();
    Ellipses(double R1, double R2_1, double X1, double Y1);
    Point GetPoint(double t) override;
    std::vector<double> GetDerivatives(double t) override;
};

class LIB Helixes : public Figure {
    double step;
    int count_step;
public:
    Helixes();
    Helixes(double R1, double step1, int step_count, double X1, double Y1, double Z1);
    Point GetPoint(double t) override;
    std::vector<double> GetDerivatives(double t) override;
};