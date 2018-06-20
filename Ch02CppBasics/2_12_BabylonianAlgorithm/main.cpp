#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "2_12_babylonian_algorithm" << endl << endl;
    int n;
    double r, guess, error;
    char ans;
    do
    {
        cout << "Input a number: ";
        cin >> n;
        do
        {
            r = n / guess;
            guess = (guess + r) / 2;
            error = fabs(guess-sqrt(n))/sqrt(n);
        } while (error>0.01);
        cout << "The Square Root is: " << guess << endl << endl;
        cout << "Do you want to repeat calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << endl << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl;

    return 0;
}

