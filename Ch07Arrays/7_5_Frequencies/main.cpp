#include <iostream>
#include <fstream>
#include <gettoken.h>

using namespace std;

int main()
{
    ifstream inFile;
    int *pNum = NULL;
    int *pCount = NULL;
    char PNum=NULL;
    char where;
    char filename[50];
    cout << "7_5_frequencies" <<endl<<endl;
    cout<<"Read this array from the [K]eyboard or from a [F]ile? ";
    cin>>where;
    if(where=='k')
    {
        Keyboard(pNum, pCount);
    }
    else
    {
        cout<<"Enter a file name: ";
        cin>>filename;        
        File(PNum, pCount, filename);
    }
    return 0;
}


