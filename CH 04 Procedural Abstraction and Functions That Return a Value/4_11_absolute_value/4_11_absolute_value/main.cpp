#include <iostream>

using namespace std;

double abs (double d);
float abs (float f);
int abs (int i);
long abs (long l);

int main()
{
    cout << "4_11_absolute_value" << endl << endl;
    int i=7;
    int abs_i;
    double d=-9;
    double abs_d;
    float f=-3.75;
    float abs_f;
    long l=-1.56;
    long abs_l;
    abs_i = abs (i);
    abs_d = abs (d);
    abs_f = abs (f);
    abs_l = abs (l);
    cout << "Int=7" << endl;
    cout << "Double=-9" << endl;
    cout << "Float=-3.75" << endl;
    cout << "Long=-1.56" << endl;
    cout << endl;
    cout << "Abs(Int) is being called"<<endl;
    cout << "Abs Int:" << abs_i << endl << endl;
    cout << "Abs(Double) is being called"<<endl;
    cout << "Abs Double:" << abs_d << endl << endl;
    cout << "Abs(Float) is being called"<<endl;
    cout << "Abs Float:" << abs_f << endl << endl;
    cout << "Abs(Long) is being called"<<endl;
    cout << "Abs Long:" << abs_l << endl;
    cout << endl;
    return 0;
}

int abs (int i)
{
    if (i<0) return i*(-1);
    else     return i;
}

double abs (double d)
{
    if (d<0) return d*(-1);
    else     return d;
}

float abs (float f)
{
    if (f<0) return f*(-1);
    else     return f;
}

long abs (long l)
{
    if (l<0) return l*(-1);
    else     return l;
}

