#include <iostream>

using namespace std;

char HEX[]="0123456789ABCDEF";
int size=5;
void Input(char n1[], char n2[]);
void StrCpy(char dest[], char src[]);
void Add(char n1[], char n2[], char result[], int base); //Add Decimal and Binary Numbers
int FindAny(char source[], char dights[], int Pos);
int StrChr(char source, char dights[]); //Returns a pointer to the first occurrence of character in the source
void Reverse(char dest[], char src[]); //reverse the strings to line up the numbers
int StrLen(char s[]); //Returns an integer equal to the length of S
void Show(char n1[], char n2[], char result[]);
bool overflew=false;

int main()
{
    int base;
    char ans, number1[size], number2[size], result[size], type;
    cout << "Add numbers at any base" <<endl<<endl;
    do
    {
        cout<<"[D]ecimal, [B]inary, [H]ex"<<endl;
        cin>>type;
        switch (type)
        {
        case 'd':
            base=10;
            break;
        case 'b':
            base=2;
            break;
        case 'h':
            base=16;
            break;
        default:
            break;
        }
        cout<<"Enter two Numbers:"<<endl;
        Input(number1, number2);
        Add(number1, number2, result, base);
        Show(number1, number2, result);
        cout<<"Do you want to repeat calculation?(y/n) ";
        cin>>ans;
    }while (ans == 'y' || ans == 'Y');
    cout << endl << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl;
    return 0;
}

void Input(char n1[], char n2[])
{
    bool rewrite;
    char empty[]="\0";
    do
    {
        cout<<"Number 1: ";
        cin>>n1;
        cout<<"Number 2: ";
        cin>>n2;
        if(StrLen(n1)>size || StrLen(n2)>size)
        {
            cout<<"Size is: "<<size<<". Overflew. Enter again."<<endl;
            StrCpy(n1, empty);
            StrCpy(n2, empty);
            rewrite=true;
        }
        else
        {
            rewrite=false;
        }
    }while(rewrite);
}

void StrCpy(char dest[], char src[])
{
    int i=0;
    for(i=0; i<StrLen(src); i++)
    {
        dest[i]=src[i];
    }
    dest[i]='\0';
}

void Add(char n1[], char n2[], char result[], int base)
{
    int num1dight, num2dight, resultanswer, resultdight, carry=0;
    char n1_reverse[size], n2_reverse[size], result_reverse[size];
    Reverse(n1_reverse, n1);
    Reverse(n2_reverse, n2);
    int i;
    for(i=0; i<size; i++)
    {
        if(base==10 || base==2)
        {
            num1dight=n1_reverse[i]-48;
            num2dight=n2_reverse[i]-48;
        }
        else
        {
            num1dight=FindAny(n1_reverse, HEX, i);
            num2dight=FindAny(n2_reverse, HEX, i);
        }
        resultanswer=num1dight+num2dight+carry;
        resultdight=resultanswer%base;
        carry=resultanswer/base;
        if(base==10 || base==2)
        {
            result_reverse[i]=resultdight+48;
        }
        else
        {
            result_reverse[i]=HEX[resultdight];
        }
    }
    if(carry==1)
    {
        overflew=true;
    }
    else
    {
        overflew=false;
    }
    result_reverse[size]='\0';
    Reverse(result, result_reverse);
}

int FindAny(char source[], char dights[], int Pos)
{
    char Source;
    Source=source[Pos];
    if(StrChr(Source, dights)>0)
    {
        Pos=StrChr(Source, dights);
        return Pos;
    }
}

int StrChr(char source, char dights[])
{
    for (int i=0; i<StrLen(dights); i++)
    {
        if(dights[i]==source)
        {
            return i;
        }
    }
    return (-1);
}

void Reverse(char dest[], char src[])
{
    int i, j=StrLen(src)-1;
    for(i=0; i<StrLen(src); i++)
    {
        dest[i]=src[j];
        j--;
    }
    for(int i=StrLen(src); i<size; i++)
    {
        dest[i]='0';
    }
    dest[size]='\0';
}

int StrLen(char s[])
{
    int i=0;
    while (s[i]!='\0')
    {
        i++;
    }
    return i;
}

void Show(char n1[], char n2[], char result[])
{
    int Pos;
    cout<<n1<<" + "<<n2<<" = ";
    if(overflew)
    {
        cout<<"Addition Overflew"<<endl<<endl;
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            if(result[i]!='0')
            {
                Pos=i;
                i=size;
            }
        }
        for(int j=Pos; j<size; j++)
        {
            cout<<result[j];
        }
        cout<<endl<<endl;
    }
}
