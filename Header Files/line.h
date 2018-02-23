#ifndef LINE_H
#define LINE_H
#include <iostream>
#include "point.h"

class Line
{
public:
    Line();
    Line(Point p1, Point p2);
    Line(double x1, double y1, double x2, double y2);
    void Print();
    double Length();
    double Slope();
    Point MidPoint();
    void SetA(double x1, double y1);
    void SetB(double x2,double y2);
    Point GetA();
    Point GetB();
private:
    Point A;
    Point B;
};

#endif // LINE_H
