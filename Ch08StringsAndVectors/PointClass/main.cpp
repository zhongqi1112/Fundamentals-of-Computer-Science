#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    cout << "Point Class" <<endl<<endl;
    Point p1(5,4);
    Point p2;
    p1.Print();
    cout<<endl;
    p2.Print();
    cout<<endl;
    cout<<p1.Distance(p2)<<endl<<endl;
    return 0;
}
