#include <iostream>

using namespace std;

int size=10;
void Input(char n1[], char n2[]);
void Add(char n1[], char n2[], char result[], int base); //Add Decimal Numbers
void Reverse(char dest[], char src[]); //reverse the strings to line up the numbers
int StrLen(char s[]); //Returns an integer equal to the length of S
void Show(char n1[], char n2[], char result[]);

int main()
{
    int base=10;
    char ans, number1[size], number2[size], result[size];
    cout << "7_7_add_decimal_numbers" <<endl<<endl;
    cout<<"Enter two Decimal Numbers:"<<endl;
    do
    {
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
    cout<<"Number 1: ";
    cin>>n1;
    cout<<"Number 2: ";
    cin>>n2;
}

void Add(char n1[], char n2[], char result[], int base)
{
    int num1dight, num2dight, resultanswer, resultdight, carry=0;
    char n1_reverse[size], n2_reverse[size], result_reverse[size];
    Reverse(n1_reverse, n1);
    Reverse(n2_reverse, n2);
    int i;
    for (i=0; i<size; i++)
    {
        num1dight=n1_reverse[i]-48;
        num2dight=n2_reverse[i]-48;
        resultanswer=num1dight+num2dight+carry;
        resultdight=resultanswer%base;
        carry=resultanswer/base;
        result_reverse[i]=resultdight+48;
    }
    result_reverse[size]='\0';
    Reverse(result, result_reverse);
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
