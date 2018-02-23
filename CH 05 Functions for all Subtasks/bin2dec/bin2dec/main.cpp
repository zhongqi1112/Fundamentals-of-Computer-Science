#include <iostream>

using namespace std;

char ch;

long Binary2Decimal(char ch);

int main()
{
    cout << "Binary to Decimal" << endl << endl;
    cout << "Input Binary: ";
    ch = cin.get();
    Binary2Decimal(ch);
    cout << "Deciaml: " << Binary2Decimal(ch) << endl << endl;
    cout << "========================================" <<endl << endl;
    return 0;
}

long Binary2Decimal(char ch)
{
    int di, total=0;
    while (ch == '1'|| ch=='0')
    {
        di=ch-'0';
        total=total*2+di;
        ch = cin.get();
    }
    return (total);
}
