#include <iostream>

using namespace std;

double inflation (double past, double today);

int main()
{
    cout << "4_4_rate_of_inflation" << endl << endl;
    double past_price, today_price, rate_inflation;
    char ans;
    do
    {
        cout << "Input the price of last year: $";
        cin >> past_price;
        cout << "Input the price of today: $";
        cin >> today_price;
        rate_inflation = inflation (past_price, today_price);
        cout.setf (ios::fixed);
        cout.setf (ios::showpoint);
        cout.precision(2);
        cout << "Rate of Inflation: " << rate_inflation << "%" << endl;
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

double inflation (double past, double today)
{
    return (((today-past)/past)*100);
}
