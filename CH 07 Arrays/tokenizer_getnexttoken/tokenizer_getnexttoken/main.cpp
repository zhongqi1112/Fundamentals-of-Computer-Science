#include <iostream>
#include <fstream>
#include <gettoken.h>

using namespace std;

int main()
{
    cout << "Get Token" <<endl<<endl;
    char block[size], token[size], tokentype;
    int pos=0;
    ifstream inFile;
    GetToken(inFile, block, token, tokentype, pos);
    SortFrequency(A, Frequency, TotalWords);
    Print(A, Frequency, TotalWords);
    return 0;
}

