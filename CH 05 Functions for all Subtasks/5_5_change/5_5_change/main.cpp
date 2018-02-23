#include <iostream>

using namespace std;

void input(double& money);
int change(double& money, int value);
void output(int twen, int ten, int dol, int quar, int dimes, int penney);

int main()
{
    double m;
    cout << "5_5_change" << endl << endl;
    input(m);
    int twenty=change(m,2000);
    int tens=change(m, 1000);
    int ones=change(m,100);
    int quarter=change(m,25);
    int dimes=change(m,10);
    int pennies=change(m,1);
    output(twenty, tens, ones, quarter, dimes, pennies);
    return 0;
}

void input(double& money)
{
    cout << "Input the money: $";
    cin >> money;
    money*=100;
}

int change(double& money, int value)
{
    int c=money/value;
    money = money-c*value;
    return (c);
}

void output(int twen, int ten, int dol, int quar, int dimes, int penney)
{
    cout << "Twenty: " << twen << endl << "Tens:" <<ten<<endl;
    cout << "Dollars: " << dol <<endl<< "Quarters: " << quar<<endl;
    cout << "Dimes: " << dimes<<endl << "Pennies: " << penney<<endl;
}
