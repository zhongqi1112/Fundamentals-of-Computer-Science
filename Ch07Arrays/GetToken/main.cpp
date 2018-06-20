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
    cout<<"There are no more tokens to process."<<endl<<endl;
    cout<<"A report with information:"<<endl;
    cout<<"Number of Words in the file: "<<num_words<<endl;
    cout<<"Number of Numbers in the file: "<<num_numbers<<endl;
    cout<<"Number of Punctuation in the file: "<<num_punc<<endl<<endl;
    return 0;
}

