#include<iostream>
#include<cmath>

using namespace std;

void input (int& decimal);
int conversion (int decimal);

int main()
{
    cout << "Decimal to Binary" <<endl << endl;
    int dec;
    char ans;
    do
    {
        input(dec);
        conversion (dec);
        cout << "Binary: " << conversion(dec) << endl;
        cout << endl << "Do you want to repeat conversion?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl;
    return 0;
}

void input (int& decimal)
{
    cout << "Input Decimal: ";
    cin >> decimal;
}

int conversion(int decimal)
{
    int power=0, n=0, bi=0;
    while (decimal>=power)
    {
        power=pow(2,n);
        n++;
    }
    n-=2;
    while (n>=0)
    {
        power=pow(2,n);
        if (decimal>=power)
        {
            decimal=decimal-pow(2,n);
            bi=bi*10+1;
        }
        else
        {
            bi=bi*10+0;
        }
        n--;
    }
    return (bi);
}
