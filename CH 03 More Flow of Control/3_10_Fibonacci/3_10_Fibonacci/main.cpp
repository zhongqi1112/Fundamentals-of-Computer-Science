#include <iostream>

using namespace std;

int main()
{
    cout << "3_10_Fibonacci" << endl << endl;
    int pounds; // the initial size of a green crud population (in pounds)
    int days; // number of days
    const int period = 5; // time period of 5 days.
    int count;
    int a;
    int b;
    int c;
    char ans;
    do
    {
        cout << "Enter the initial pounds: ";
        cin >> pounds;
        cout << "Enter days: ";
        cin >> days;
        count = 5;
        a = 0;
        b = pounds;
        while (count <= days)
        {
            c = a + b;
            a = b;
            b = c;
            count += 5;
        }
        cout << "Pounds: " << c << endl;
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

