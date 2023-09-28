#pragma once
#include<stdio.h>
#include<cstdio>
#include <iostream>
#include <stdlib.h>
#include<string>
#include <iomanip>
#include<math.h>
#include<vector>
#include<list>
#include<algorithm>
#include<ctime>
#include <random>
#include "omp.h"
#include"Figures.h"

#pragma comment(lib, "Figures.lib")

const double PI = 3.14159265358979323846;

std::list<Figure*> list;
std::list<Figure*> list_circle;

double GetDouble(double min, double max, int precision){
    double value;
    value = rand() % (int)pow(10, precision);
    value = min + (value / pow(10, precision)) * (max - min);
    return value;
}

 void AddFigure() {
    int a;
    Figure* c;
    for (int i = 0; i < rand(); i++) {
        a = 1 + rand() % 3;
        switch (a) {
        case 1:
            c = new Circle(GetDouble(0.01, 100, 2), GetDouble(-100, 100, 2), GetDouble(-100, 100, 2));
            list.push_back(c);
            break;
        case 2:
            c = new Ellipses(GetDouble(0.01, 100, 2), GetDouble(0.01, 100, 2), GetDouble(-100, 100, 2), GetDouble(-100, 100, 2));
            list.push_back(c);
            break;
        case 3:
            c = new Helixes(GetDouble(0.01, 100, 2), GetDouble(0.01, 100, 2), (rand() % 50 + 1), GetDouble(-100, 100, 2), GetDouble(-100, 100, 2), GetDouble(-100, 100, 2));
            list.push_back(c);
            break;
        default:
            std::cout << "Неверное значение\n";
            break;
        }
    }
}

void PrintFigure() {
    Point point;
    std::vector<double> vec;
    std::cout << std::left << std::setw(35) << "Точки" << std::setw(35) << "Производные" << std::endl;
    for (Figure* obj : list) {
        for (double j = 0; j < 2 * PI; j += (PI / 4)) {
            char buf1[1000];
            char buf2[1000];
            point = obj->GetPoint(j);
            vec = obj->GetDerivatives(j);
            if (dynamic_cast<Helixes*>(obj) == nullptr) {
                sprintf_s(buf1, sizeof(buf1), "(%.3f; %.3f)", point.GetX(), point.GetY());
                sprintf_s(buf2, sizeof(buf2), "[%.3f; %.3f]", vec.front(), vec.back());
                std::cout << std::left << std::setw(35) << buf1 << std::setw(35) << buf2 << std::endl;
            }
            else {
                sprintf_s(buf1, sizeof(buf1), "(%.3f; %.3f; %.3f)", point.GetX(), point.GetY(), point.GetZ());
                sprintf_s(buf2, sizeof(buf2), "[%.3f; %.3f; %.3f]", vec.front(), vec[1], vec.back());
                std::cout << std::left << std::setw(35) << buf1 << std::setw(35) << buf2 << std::endl;
            }
        }
        std::cout << "\n";
    }
}

bool compare(Figure* A, Figure* B) {
    return dynamic_cast<Circle*>(A)->GetRadius() < dynamic_cast<Circle*>(B)->GetRadius();
}
