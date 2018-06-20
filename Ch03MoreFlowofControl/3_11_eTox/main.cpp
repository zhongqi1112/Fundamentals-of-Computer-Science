#include <iostream>

using namespace std;

int main()
{
    cout << "3_11_e^x" << endl << endl;
    double x;
    double n;
    double top;
    double bot;
    double term;
    double total;
    int i; //lines
    char ans;
    do
    {
        n=1;
        i=0;
        top=1;
        bot=1;
        total=1;
        cout << "Enter X: ";
        cin >> x;
        do
        {
            top *= x;
            bot *= n;
            term = top/bot;
            total += term;
            cout.setf (ios::fixed);
            cout.setf (ios::showpoint);
            cout.precision(10);
            if (i%5==0)
            {
                cout << endl;
            }
            cout << total << " ";
            n++;
            i++;
        } while (n<=100);
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

