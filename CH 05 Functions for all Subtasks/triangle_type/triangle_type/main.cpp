#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int RIGHT=0, ACUTE=1, OBTUSE=2, SCALENE=3, ISOSCELES=4, EQUILATERAL=5;

int types;

void InputTriangle(double& max, double& middle, double& min); //inputs three lengths (three positive doubles) and returns the three lengths in its arguments

void IsValidTriangle(double& validate_a, double& validate_b, double& validate_c); //Send the three lengths to a function to validate. Return true if the triangle is valid, false otherwise.

bool IsRIGHT(double a, double b, double c);

bool IsACUTE(double a, double b, double c);

bool IsOBTUSE(double a, double b, double c);

bool IsSCALENE(double a, double b, double c);

bool IsISOSCELES(double a, double b, double c);

bool IsEQUILATERAL(double a, double b, double c);

int TriangleType(double a, double b, double c); //represents the type of the triangle according to the sides.

void SetBit(int &n, int bitPos);

int Mask (int pos);

bool IsSet(int n, int bitpos);

void Report(int types);

double TriangleArea(double area_a, double area_b, double area_c); //returns the area of a triangle

double TrianglePremeter(double premeter_a, double premeter_b, double premeter_c); //returns the perimeter of the triangle.

double CalculateAngleOfTriangle(double a, double b, double c, double angle); //given the three sides and the angle to compute
//CalculateAngleOfTriangle(a, b, c, A) the angle is facing the one facing the first argument. So, if you want angle B, you must call CalculateAngleOfTriangle(b, a, c, B)

int main()
{
    char ans;
    double side_a, side_b, side_c;
    double angle_A, angle_B, angle_C;
    cout << "Triangle Type" <<endl;
    do
    {
        types=0;
        InputTriangle(side_a, side_b, side_c);
        IsValidTriangle(side_a, side_b, side_c);
        cout << endl << "Three sides: " <<"a="<< side_a <<"  "<<"b="<< side_b <<"  "<<"c="<< side_c << endl;
        angle_A=CalculateAngleOfTriangle(side_a, side_b, side_c, angle_A);
        angle_B=CalculateAngleOfTriangle(side_b, side_a, side_c, angle_B);
        angle_C=CalculateAngleOfTriangle(side_c, side_a, side_b, angle_C);
        cout << "Three angle: A=" <<angle_A << "  "<<"B=" << angle_B << "  "<<"C=" << angle_C << endl;
        TriangleType(side_a,side_b,side_c);
        cout << "Triangle Type: ";
        Report(types);
        cout << "TRIANGLE" << endl;
        cout << "Area: " << TriangleArea(side_a, side_b, side_c) << endl;
        cout << "Premeter: " << TrianglePremeter(side_a, side_b, side_c) << endl << endl;
        cout << "Do you want to repeat calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << endl << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl;
    return 0;
}

void InputTriangle(double& max, double& middle, double& min)
{
    double term;
    cout << "Input correct three sides of a triangle: "<<endl;
    cin >> max;
    cin >> middle;
    cin >> min;
    if(middle>max)
    {
        term=middle;
        middle=max;
        max=term;
    }
    if(min>middle)
    {
        if(min>max)
        {
            term=min;
            min=middle;
            middle=max;
            max=term;
        }
        else
        {
            term=min;
            min=middle;
            middle=term;
        }
    }
}

void IsValidTriangle(double& validate_a, double& validate_b, double& validate_c)
{
    bool positive, sum;
    do
    {
        positive=true;
        sum=true;
        if(validate_a<=0 || validate_b<=0 || validate_c<=0)
        {
            positive=false;
        }
        if(validate_a+validate_b<=validate_c || validate_a+validate_c<=validate_b || validate_b+validate_c<=validate_a)
        {
            sum=false;
        }
        if (positive==false || sum==false)
        {
            InputTriangle(validate_a,validate_b,validate_c);
        }
    }while(positive==false || sum==false);
}

double CalculateAngleOfTriangle(double a, double b, double c, double angle)
{
    double pi=3.141592653589793238462643383279502884197169399375105820974944592307816406;
    double cosA;
    cosA=(pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c);
    angle=acos(cosA)*180/pi;
    return (angle);
}

bool IsRIGHT(double a, double b, double c)
{
    if (pow(a,2)==(pow(b,2)+pow(c,2)))
        return true;
    else return false;
}

bool IsACUTE(double a, double b, double c)
{
    if(pow(a,2)<(pow(b,2)+pow(c,2)))
        return true;
    else return false;
}

bool IsOBTUSE(double a, double b, double c)
{
    if (pow(a,2)>(pow(b,2)+pow(c,2)))
        return true;
    else return false;
}

bool IsSCALENE(double a, double b, double c)
{
    if (a!=b && a!=c && b!=c)
        return true;
    else return false;
}

bool IsISOSCELES(double a, double b, double c)
{
    if (a==b || a==c || b==c)
        return true;
    else return false;
}

bool IsEQUILATERAL(double a, double b, double c)
{
    if (a==b && b==c)
        return true;
    else return false;
}

int TriangleType(double a, double b, double c)
{
    if (IsRIGHT(a, b, c))
    {
        SetBit(types, RIGHT);
    }
    if (IsACUTE(a, b, c))
    {
        SetBit(types, ACUTE);
    }
    if (IsOBTUSE(a, b, c))
    {
        SetBit(types, OBTUSE);
    }
    if (IsSCALENE(a, b, c))
    {
        SetBit(types, SCALENE);
    }
    if (IsISOSCELES(a, b, c))
    {
        SetBit(types, ISOSCELES);
    }
    if (IsEQUILATERAL(a, b, c))
    {
        SetBit(types, EQUILATERAL);
    }
    return (types);
}

void SetBit(int &n, int bitPos)
{
    int mask = Mask(bitPos);
    types = n|mask;
}

int Mask(int pos)
{
    return (1<<pos);
}

bool IsSet(int n, int bitPos)
{
    int mask = Mask(bitPos);
    int anded =  (n & mask);
    if (anded ==mask)
        return true;
    else return false;
}

void Report(int types)
{
    for (int i=0; i<6; i++)
    {
        if (IsSet(types,i))
        {
            if (i==0) cout << "RIGHT ";
            if (i==1) cout << "ACUTE ";
            if (i==2) cout << "OBTUSE ";
            if (i==3) cout << "SCALENE ";
            if (i==4) cout << "ISOSCELES ";
            if (i==5) cout << "EQUILATERAL ";
        }
    }
}

double TriangleArea(double area_a, double area_b, double area_c)
{
    double p, A;
    p=(area_a+area_b+area_c)/2;
    A=p*(p-area_a)*(p-area_b)*(p-area_c);
    return (sqrt(A));
}

double TrianglePremeter(double premeter_a, double premeter_b, double premeter_c)
{
    double premeter;
    premeter=premeter_a+premeter_b+premeter_c;
    return (premeter);
}
