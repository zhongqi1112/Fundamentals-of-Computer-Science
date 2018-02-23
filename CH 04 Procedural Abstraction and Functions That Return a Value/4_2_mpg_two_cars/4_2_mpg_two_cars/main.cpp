#include <iostream>

using namespace std;

const double rate = 0.264179;
double consume (double mile, double gallon);

int main()
{
    cout << "4_2_mpg_two_cars" << endl << endl;
    double liters_consumed_1, mile_traveled_1, miles_gallon_1;
    double liters_consumed_2, mile_traveled_2, miles_gallon_2;
    char ans;
    do
    {
        cout << "Car 1:" << endl;
        cout << "Input the number of liters of gasoline (in liters): ";
        cin >> liters_consumed_1;
        cout << "Input the number of miles: ";
        cin >> mile_traveled_1;
        miles_gallon_1 = consume(mile_traveled_1, liters_consumed_1);
        cout << endl;
        cout << "Car 2:" << endl;
        cout << "Input the number of liters of gasoline (in liters): ";
        cin >> liters_consumed_2;
        cout << "Input the number of miles: ";
        cin >> mile_traveled_2;
        miles_gallon_2 = consume(mile_traveled_2, liters_consumed_2);
        cout << endl;
        cout << "Car 1: Mile per gallon: " << miles_gallon_1 << endl;
        cout << "Car 2: Mile per gallon: " << miles_gallon_2 << endl;
        cout << endl;
        if (miles_gallon_1 > miles_gallon_2)
        {
            cout << "Car 1 has the best fuel efficiency." << endl;
        }
        else
        {
            cout << "Car 2 has the best fuel efficiency." << endl;
        }
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

double consume (double mile, double gallon)
{
    return (mile / (gallon * rate));
}

