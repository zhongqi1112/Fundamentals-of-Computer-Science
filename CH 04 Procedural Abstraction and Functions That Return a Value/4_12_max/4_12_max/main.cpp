#include <iostream>

using namespace std;

double max (double a, double b);

int main()
{
    double num_a, num_b, num_c, big, two;
    cout << "4_12_max" << endl << endl;
    cout << "Input A: ";
    cin >> num_a;
    cout << "Input B: ";
    cin >> num_b;
    big = max (num_a, num_b);
    cout << "The max is: " << big << endl << endl;
    cout << "Input A: ";
    cin >> num_a;
    cout << "Input B: ";
    cin >> num_b;
    cout << "Input C: ";
    cin >> num_c;
    two = max (num_a, num_b);
    big = (two, num_c);
    cout << "The max is: " << big << endl << endl;
    return 0;
}

double max (double a, double b)
{
    if (a>b)
        return (a);
    else
        return (b);
}
