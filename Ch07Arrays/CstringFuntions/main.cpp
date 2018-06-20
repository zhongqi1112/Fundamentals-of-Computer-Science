#include <iostream>
#include "mycstrings.h"

using namespace std;

int main()
{
    const int size=40;
    int Pos, limit=5;
    char dest[size];
    char str1[]="0123456789";
    char str2[]="abcd54321efgh";
    cout<<"CString 1: "<<str1<<endl<<"CString 2: "<<str2<<endl<<endl;
    cout<<"Length: CString 1: "<<StrLen(str1)<<endl;
    cout<<"Length: CString 2: "<<StrLen(str2)<<endl<<endl;
    int startnum=FindAny(str2, str1, Pos);
    int endnum=FindNotAny(str2, str1, startnum+1);
    cout<<"Start: "<<startnum<<endl;
    cout<<"End: "<<endnum<<endl;
    SubStr(str2, dest, startnum, endnum);
    cout<<"Index range: "<<dest<<endl<<endl;
    StrCmp(str1, str2);
    if(StrCmp(str1, str2)==0)
    {
        cout<<"The strings are the same."<<endl<<endl;
    }
    else if(StrCmp(str1, str2)<0)
    {
        cout<<"CString 1 is less than CString 2."<<endl<<endl;
    }
    else if(StrCmp(str1, str2)>0)
    {
        cout<<"CString 1 is greater than CString 2."<<endl<<endl;
    }
    StrNCpy(str1, str2, limit);
    cout<<"After StrNCpy:"<<endl<<"str1: "<<str1<<endl<<"str2: "<<str2<<endl<<endl;
    StrNCat(str1, str2, limit);
    cout<<"After StrNCat: "<<endl<<"str1: "<<str1<<endl<<"str2: "<<str2<<endl<<endl;
    StrCpy(str1, str2);
    cout<<"After StrCpy:"<<endl<<"str1: "<<str1<<endl<<"str2: "<<str2<<endl<<endl;
    StrCat(str1,str2);
    cout<<"After StrCat: "<<endl<<"str1: "<<str1<<endl<<"str2: "<<str2<<endl<<endl;
    cout<<"Show: CString 1, Marker=4:"<<endl;
    int Marker=4;
    Show(str1, Marker);
    cout<<"Show: CString 2, Marker=8:"<<endl;
    Marker=8;
    Show(str2, Marker);
    char Upper[]="ABCDEFG", upper[size];
    char Lower[]="hijklmn", lower[size];
    cout<<"Upper:"<<Upper<<endl<<"Lower:"<<Lower<<endl;
    ToLower(Upper, lower);
    cout<<"Convert the cstring to lower case:"<<endl<<lower<<endl;
    ToUpper(Lower, upper);
    cout<<"Convert the cstring to upper case:"<<endl<<upper<<endl<<endl;
    return 0;
}
