#include <iostream>

using namespace std;

int main()
{
    cout << "2_3_annual_salary" << endl << endl;
    const double pay_increase = 0.076;
    double previous_annual_salary;
    double retroactive_pay;
    double new_annual_salary;
    double new_monthly_salary;
    char ans;
    do
    {
        cout << "Previous Annual Salary: $";
        cin >> previous_annual_salary;
        retroactive_pay = (previous_annual_salary / 2) * pay_increase;
        new_annual_salary = previous_annual_salary * (1 + pay_increase);
        new_monthly_salary = new_annual_salary / 12;
        cout << "Retroactive Pay: $" << retroactive_pay << endl;
        cout << "New Annual Salary: $" << new_annual_salary << endl;
        cout << "New Monthly Salary: $" << new_monthly_salary << endl;
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

