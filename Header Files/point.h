#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class  Point
{
public:
    Point();
    Point (double X, double Y);
    void Print();
    double Distance(Point other);
    double Slope(Point other);
    Point MidPoint(Point other);
    void SetX(double X);
    void SetY(double Y);
    double GetX();
    double GetY();
private:
    double x;
    double y;

};

#endif // POINT_H
