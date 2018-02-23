#include <iostream>

using namespace std;

double t (double m, double to);
double c (double to);

int main()
{
    cout << "4_15_vending_machine" << endl;
    cout << "[d]dollar, [q]quarter, [i]dime, [n]nickel" << endl << endl;
    char coin;
    double money, total, change;
    total = 0;
    do
    {
        cout << "Put coin: " << endl;
        cin >> coin;
        switch (coin)
        {
        case 'd': money = 1.00;
            break;
        case 'q': money = 0.25;
            break;
        case 'i': money = 0.10;
            break;
        case 'n': money = 0.05;
            break;
        default: money = 0.00;
            cout << "Put the correct coin." << endl;
            break;
        }
        total = t (money, total);
        cout << "Total: $" << total << endl << endl;
    } while (total < 3.50);
    cout << "Enjoy your deep-fried twinkie" << endl;
    change = c (total);
    cout << "Returned change: $" << change << endl << endl;
    return 0;
}

double t (double m, double to)
{
    return (to+m);
}

double c (double to)
{
    return (to-3.50);
}
