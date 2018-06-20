#include <iostream>
#include <fstream>
#include <frequencies.h>

using namespace std;

int main()
{
    cout << "Frequencies" <<endl<<endl;
    int Array[size], Count[size], numused=-1;
    char where;
    cout<<"Read this array from the [K]eyboard or from a [F]ile? ";
    cin>>where;
    if(where=='k' || where=='K')
    {
        Keyboard(Array, Count, numused);
        Show(Array, Count, numused);
    }
    else
    {
        File(Array, Count, numused);
        Show(Array, Count, numused);
    }
    return 0;
}
