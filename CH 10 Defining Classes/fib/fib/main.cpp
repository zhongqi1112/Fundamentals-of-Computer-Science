#include <iostream>

using namespace std;

int Fibonacci(int n);

int main()
{
    //Write a recursive function that will return the nth Fibonacci function
    cout << "fib()" << endl << endl;
    int nth;
    do
    {
        cout << "How many numbers will display? ";
        cin >> nth;
        cout << "Fibonacci:" << endl;
        for(int i=0; i<nth; i++)
            cout << Fibonacci(i) << " ";
        cout << endl << endl;
    }while(true);
    return 0;
}

int Fibonacci(int n)
{
    int F;
    if ( n < 2 )
        return 1;
    F=Fibonacci(n-1)+Fibonacci(n-2); //Will call Fibonacci but with (n-1)
    return F;
}
