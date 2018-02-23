#include "point.h"
#include <math.h>

Point::Point()
{
    x=y=0;
}

Point::Point(double X, double Y)
{
    x=X;
    y=Y;
}

void Point::Print()
{
    cout<<"("<<x<<", "<<y<<") \n";
}

double Point::Distance(Point other)
{
    double D;
    D=sqrt((pow(other.x-x,2)+pow(other.y-y,2)));
    return D;
}

double Point::Slope(Point other)
{
    double S;
    S=(y-other.y)/(x-other.x);
    return S;
}

Point Point::MidPoint(Point other)
{
    Point C (((other.x+x)/2.0),((other.y+y)/2.0));
    return C;
}

void Point::SetX(double X)
{
    x = X;
}

void Point::SetY(double Y)
{
    y = Y;
}

double Point::GetX()
{
    return x;
}

double Point::GetY()
{
    return y;
}
