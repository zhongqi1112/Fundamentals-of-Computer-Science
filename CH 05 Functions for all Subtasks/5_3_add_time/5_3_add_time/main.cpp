#include <iostream>

using namespace std;

void input(int& h, int& m, int& hw, int& mw);
void conversion(int& h, int& m, int& hw, int& mw, char& ap);
void output(int h, int m, char ap);

int main()
{
    int hour, min, hour_wait, min_wait;
    char ap, ans;
    cout << "5_3_add_time" << endl << endl;
    do
    {
        input(hour, min, hour_wait, min_wait);
        conversion(hour, min, hour_wait, min_wait, ap);
        output(hour, min, ap);
        cout << endl << endl << "Do you want to repeat conversion?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

void input(int& h, int& m, int& hw, int& mw)
{
    cout << "Current hour and minute and waiting hour and minute: " << endl;
    cin >> h >> m;
    cin >> hw >> mw;
}

void conversion(int& h, int& m, int& hw, int& mw, char& ap)
{
    h+=hw;
    m+=mw;
    if (m>59)
    {
        m-=60;
        h+=1;
    }
    if (h<12)
    {
        ap='A';
    }
    if (h>=12)
    {
        h-=12;
        ap='P';
    }
}

void output(int h, int m, char ap)
{
    cout << "After waiting, time is: " << h << ":" << m << ap;
}
