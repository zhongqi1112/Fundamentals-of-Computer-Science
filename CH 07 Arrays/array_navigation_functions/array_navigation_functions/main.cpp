#include <iostream>

using namespace std;

const int Size=10;
int cursor, i, intarray[Size];

void Append(int Array[], int number, int &NumUsed);
void Delete(int Array[], int &NumUsed);
void Insert(int Array[], int number, int &NumUsed);
void Search(int Array[], int number, int &NumUsed);
void Sort(int Array[], int &NumUsed);
void Show(int Array[], int NumUsed);
void Reverse(int Array[], int NumUsed);
void Duplicated(int Array[], int &NumUsed);
void Goback(int &NumUsed);
void Forward(int &NumUsed);
bool Success(int NumUsed);
bool Research;

int main()
{
    cout << "array_navigation_functions" << endl;
    char command;
    int num, count=0;
    cout << "[A]ppend [I]nsert [D]elete [S]earch s[o]rt [r]everse d[u]plicated e[X]it" << endl << endl;
    cout << "{ }" << endl;
    do
    {
        cout << ":";
        cin >> command;
        cout << "{ ";
        switch (command)
        {
        case 'a':
            cin >> num;
            cursor=count;
            Success(count);
            if (Success(count))
            {
                Append (intarray, num, count);
            }
            else
            {
                cout << "Overflow }" << endl << "{ ";
                cursor=Size-1;
            }
            Show(intarray,count);
            break;
        case 'd':
            Delete (intarray, count);
            Show(intarray,count);
            break;
        case 'i':
            cin >> num;
            Success(count);
            if (Success(count))
            {
                Insert (intarray, num, count);
            }
            else
                cout << "Overflow }" << endl << "{ ";
            Show(intarray,count);
            break;
        case 's':
            cin >> num;
            Research=false;
            Search (intarray, num, count);
            if(!Research)
            {
                cout << "There is no number: " << num << " }" << endl << "{ ";
            }
            Show(intarray,count);
            break;
        case 'o':
            cursor=count-1;
            Sort(intarray, count);
            Show(intarray,count);
            break;
        case 'r':
            Reverse(intarray, count);
            Show(intarray,count);
            break;
        case 'u':
            Duplicated(intarray, count);
            if(cursor>=count)
            {
                cursor=count-1;
            }
            Show(intarray,count);
            break;
        case '4':
            Goback(count);
            Show(intarray, count);
            break;
        case '6':
            Forward(count);
            Show(intarray, count);
            break;
        case '1':
            cursor=count-1;
            Show(intarray, count);
            break;
        case '7':
            cursor=0;
            Show(intarray, count);
            break;
        case 'x':
            Show(intarray, count);
            count=Size+1;
            cout << endl << "Thank you!" << endl << endl;
            break;
        default:
            cout << "Enter correct command! }" << endl << "{ ";
            Show(intarray, count);
            break;
        }
    }while (count<=Size);
    return 0;
}

void Append (int Array[], int number, int &NumUsed)
{
    if(NumUsed<0)
    {
        NumUsed=0;
        cursor=0;
    }
    Array[NumUsed]=number;
    NumUsed++;
}

void Delete (int Array[], int &NumUsed)
{
    NumUsed--;
    for (i=cursor; i<=NumUsed; i++)
    {
        Array[i]=Array[i+1];
    }
    if (cursor>=NumUsed)
    {
        cursor=NumUsed-1;
    }
}

void Insert (int Array[], int number, int &NumUsed)
{
    NumUsed++;
    for (i=NumUsed; i>cursor; i--)
    {
        Array[i]=Array[i-1];
    }
    Array[cursor]=number;
}

void Search(int Array[], int number, int &NumUsed)
{
    for (i=0; i<NumUsed; i++)
    {
        if (Array[i]==number)
        {
            cursor=i;
            Research=true;
            return;
        }
    }
}

void Sort(int Array[], int &NumUsed)
{
    int j, temp;
    for (i=0; i<NumUsed; i++)
    {
        for (j=i; j<NumUsed; j++)
        {
            if (Array[j]<Array[i])
            {
                temp=Array[j];
                Array[j]=Array[i];
                Array[i]=temp;
            }
        }
    }
}

void Show(int Array[], int NumUsed)
{
    for (i=0; i<NumUsed; i++)
    {
        if (i==cursor)
        {
            cout << "[" << Array[i] << "] ";
        }
        else
        {
            cout << Array[i] << " ";
        }
    }
    cout << "}" << endl;
}

bool Success(int NumUsed)
{
    if (NumUsed<Size)
        return true;
    else
        return false;
}

void Reverse(int Array[], int NumUsed)
{
    int j, temp;
    i=0;
    j=NumUsed-1;
    do
    {
        temp=Array[j];
        Array[j]=Array[i];
        Array[i]=temp;
        i++;
        j--;
    }while (i<j);
}

void Duplicated(int Array[], int &NumUsed)
{
    for(i=0; i<NumUsed; i++)
    {
        if(Array[i]==Array[i+1])
        {
            for(i=i; i<NumUsed; i++)
            {
                Array[i+1]=Array[i+2];
            }
            NumUsed--;
            i=-1;
        }
    }
}

void Goback(int &NumUsed)
{
    cursor--;
    if(cursor<0)
    {
        cursor=0;
    }
}

void Forward(int &NumUsed)
{
    cursor++;
    if(cursor>=NumUsed)
    {
        cursor=NumUsed-1;
    }
}
