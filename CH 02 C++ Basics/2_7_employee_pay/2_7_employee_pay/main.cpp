#include <iostream>

using namespace std;

int main()
{
    cout << "2_7_employee_pay" << endl << endl;
    const double rate = 16.78; // per hours for the first 40 hours
    const double overtime_rate = 16.78*1.5; // over 40 hours
    int hours; // numbers of hours worked
    int dependent; // number of dependents
    double gross_pay;
    double social; // social security tax
    const double social_rate = 0.06;
    double federal; // federal income tax
    const double federal_rate = 0.14;
    double state; // state income tax
    const double state_rate = 0.05;
    const int union_dues = 10;
    const int health = 35;
    double takehome_pay;
    char ans;
    do
    {
        cout << "The number of hours worked: ";
        cin >> hours;
        cout << "The number of dependents: ";
        cin >> dependent;
        if (hours <= 40)
        {
            gross_pay = hours*rate;
        }
        else
        {
            gross_pay = 40*rate + (hours-40)*overtime_rate;
        }
        social = gross_pay * social_rate;
        federal = gross_pay * federal_rate;
        state = gross_pay * state_rate;
        cout << "Gross pay: $" << gross_pay << endl;
        cout << "Social Security Tax: $" << social << endl;
        cout << "Federal Income Tax: $" << federal << endl;
        cout << "State Income Tax: $" << state << endl;
        cout << "Union Dues: $" << union_dues << endl;
        if (dependent >= 3)
        {
            takehome_pay = gross_pay - social - federal - state - union_dues - health;
            cout << "The Extra Cost of Health Insurance: $" << health << endl;
            cout << "The Net Take-home Pay: $" << takehome_pay << endl;
        }
        else
        {
            takehome_pay = gross_pay - social - federal - state - union_dues;
            cout << "The Extra Cost of Health Insurance: $0" << endl;
            cout << "The Net Take-home Pay: $" << takehome_pay << endl;
        }
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

