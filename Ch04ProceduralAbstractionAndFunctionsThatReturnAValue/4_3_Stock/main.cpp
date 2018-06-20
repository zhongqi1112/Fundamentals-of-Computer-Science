#include <iostream>

using namespace std;

double price(double whole, double numer, double denom, int shares);

int main()
{
    cout << "4_3_stock" << endl << endl;
    int number_shares, whole, numerator, denominator;
    double price_share;
    char ans, slash;
    do
    {
        cout << "Input the number of shares: ";
        cin >> number_shares;
        cout << "Input the price per share: ";
        cin >> whole >> numerator >> slash >> denominator;
        price_share = price(whole, numerator, denominator, number_shares);
        cout.setf (ios::fixed);
        cout.setf (ios::showpoint);
        cout.precision(4);
        cout << "Value of Share: " << price_share<< endl;
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

double price(double whole, double numer, double denom, int shares)
{
    double price;
    price = (whole*denom+numer)/denom;
    return (price*shares);
}
