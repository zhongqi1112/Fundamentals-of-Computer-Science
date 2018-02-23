#include "line.h"
#include <math.h>
#include "point.h"

Line::Line()
{
    Point p(0,0);
    A=B=p;
}

Line::Line(Point p1, Point p2)
{
    A=p1;
    B=p2;
}

Line::Line(double x1, double y1, double x2, double y2)
{
    Point p1(x1,y1);
    Point p2(x2,y2);
    A=p1;
    B=p2;
}

void Line::Print()
{
   A.Print();
   B.Print();
}

double Line::Length()
{
    return A.Distance(B);
}

double Line::Slope()
{
   return A.Slope(B);
}

Point Line::MidPoint()
{
    Point M=A.MidPoint(B);
    return M;
}

void Line::SetA(double x1,double y1)
{
   A.SetX(x1);
   A.SetY(y1);
}

void Line::SetB(double x2,double y2)
{
    B.SetX(x2);
    B.SetY(y2);
}

Point Line::GetA()
{
    return A;
}

Point Line::GetB()
{
    return B;
}
