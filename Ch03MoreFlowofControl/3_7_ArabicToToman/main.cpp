#include <iostream>

using namespace std;

int main()
{
    cout << "3_7_arabic_to_roman" << endl << endl;
    int arabic;
    char thousands;
    char hundreds;
    char tens;
    char ones;
    double t;
    double h;
    double te;
    double o;
    char ans;
    do
    {
        cout << "Enter four dights Arabic(1000-3000): ";
        cin >> arabic;
        if (arabic == 3000)
        {
            cout << "MMM";
        }
        else
        {
            t = arabic / 1000;
            h = arabic/100 - 10*t;
            te = arabic/10 - 100*t - 10*h;
            o = arabic - 1000*t - 100*h - 10*te;
            thousands = t + '0';
            hundreds = h + '0';
            tens = te + '0';
            ones = o + '0';
            switch (thousands)
            {
            case '1': cout << "M";
                break;
            case '2': cout << "MM";
                break;
            default: cout << "Please input 1000-3000!" << endl;
                break;
            }
            switch (hundreds)
            {
            case '1': cout << "C";
                break;
            case '2': cout << "CC";
                break;
            case '3': cout << "CCC";
                break;
            case '4': cout << "CD";
                break;
            case '5': cout << "D";
                break;
            case '6': cout << "DC";
                break;
            case '7': cout << "DCC";
                break;
            case '8': cout << "DCCC";
                break;
            case '9': cout << "DCCCC";
                break;
            case '0': cout << "";
                break;
            }
            switch (tens)
            {
            case '1': cout << "X";
                break;
            case '2': cout << "XX";
                break;
            case '3': cout << "XXX";
                break;
            case '4': cout << "XL";
                break;
            case '5': cout << "L";
                break;
            case '6': cout << "LX";
                break;
            case '7': cout << "LXX";
                break;
            case '8': cout << "LXXX";
                break;
            case '9': cout << "LXXXX";
                break;
            case '0': cout << "";
                break;
            }
            switch (ones)
            {
            case '1': cout << "I";
                break;
            case '2': cout << "II";
                break;
            case '3': cout << "III";
                break;
            case '4': cout << "IV";
                break;
            case '5': cout << "V";
                break;
            case '6': cout << "VI";
                break;
            case '7': cout << "VII";
                break;
            case '8': cout << "VIII";
                break;
            case '9': cout << "VIIII";
                break;
            case '0': cout << "";
                break;
            }
        }
        cout << endl << endl;
        cout << "Do you want to do again? ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

