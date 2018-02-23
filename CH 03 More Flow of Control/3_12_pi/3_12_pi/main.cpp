#include <iostream>

using namespace std;

int main()
{
    cout << "3_12_pi" << endl << endl;
    int n;
    double top;
    double bot;
    double term;
    double total;
    int count;
    char ans;
    do
    {
        top = -1;
        bot = -1;
        total = 0;
        count = 0;
        cout << "Enter N: ";
        cin >> n;
        while (count <= n)
        {
            top = (-1) * top;
            bot += 2;
            term = top / bot;
            total += term;
            count++;
            cout.setf (ios::fixed);
            cout.setf (ios::showpoint);
            cout.precision(20);
        }
        cout << "Pi= " << 4*total;
        cout << endl;
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

