#ifndef Point_H
#define Point_H

#include <iostream>

using namespace std;

class Point
{
public:
    Point();
    Point(int Xo, int Yo);
    void Print();
    double Distance(Point other);
    void SetX(int X);
    void SetY(int Y);
    int GetX();
    int GetY();
private:
    int x;
    int y;
};

#endif // Point_H
