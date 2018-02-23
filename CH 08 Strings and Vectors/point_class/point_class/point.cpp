#include <iostream>
#include <cmath>
#include "Point.h"

Point::Point()
{
    x=y=0;
}

Point::Point(int Xo, int Yo)
{
    x = Xo;
    y = Yo;
}

void Point::Print()
{
    cout<<"=======>> ("<<x<<", "<<y<<") <<=======";
}

double Point::Distance(Point other)
{
    double D;
    cout<<"Distance between two points: ";
    D=sqrt((pow(other.x-x,2)+pow(other.y-y,2)));
    return D;
}

void Point::SetX(int X)
{
    x = X;
}

void Point::SetY(int Y)
{
    y = Y;
}

int Point::GetX()
{
    return x;
}

int Point::GetY()
{
    return y;
}
