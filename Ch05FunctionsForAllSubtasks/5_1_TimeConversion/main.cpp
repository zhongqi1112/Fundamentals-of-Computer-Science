#include <iostream>

using namespace std;

void input (int& h, int& m);
void conversion (int& h, char& ap);
void output (int h, int m, char ap);

int main()
{
    int hour, min;
    char ap, ans;
    cout << "5_1_time_conversion" << endl << endl;
    do
    {
        input(hour,min);
        conversion (hour, ap);
        output (hour, min, ap);
        cout << endl << endl << "Do you want to repeat conversion?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

void input (int& h, int& m)
{
    cout << "Input hour and minute: ";
    cin >> h >> m;
}

void conversion (int& h, char& ap)
{
    if (h>12)
    {
        ap='P';
        h -=12;
    }
    else
    {
        ap='A';
    }
}

void output (int h, int m, char ap)
{
    cout << h << ":" << m << ap;
}
