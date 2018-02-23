#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

//template <typename T>

const int MAX = 10; //It is a 10*10 table

int Random(int low, int high);
void Init(int A[][MAX], int Size[], int &row, int &col);
void Append(int A[][MAX], int Size[], int row, int &col, int Number);
void Delete(int A[][MAX], int Size[], int row, int &col);
void Insert(int A[][MAX], int Size[], int row, int col, int Number);
void Duplicated(int A[][MAX], int Size[], int row, int &col);
void Show(int A[][MAX], int Size[], int row, int col);
void GetCursor(int Size[], int &row, int &col);
void Cursor_Left(int &col);
void Cursor_Right(int Size[], int row, int &col);
void Cursor_Down(int Size[], int &row, int &col);
void Cursor_Up(int Size[], int &row, int &col);
void Cursor_Home(int Size[], int &row, int &col);
void Cursor_End(int Size[], int &row, int &col);


int main()
{
    char command;
    int A[MAX][MAX], Size[MAX], row_cursor, col_cursor, num;
    cout<<"[R]andom [A]ppend [I]nsert [D]elete [G]etCursor D[u]plicated [Q]uit" << endl;
    cout<<"4=Left, 6=Right, 2=Down, 8=Up, 7=home, 1=end"<<endl<<endl;
    do
    {
        cout<<">";
        cin>>command;
        switch(command)
        {
        case 'r':
        case 'R':
            Init(A, Size, row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case 'a':
        case 'A':
            cin>>num;
            Append(A, Size, row_cursor, col_cursor, num);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case 'd':
        case 'D':
            Delete(A, Size, row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case 'i':
        case 'I':
            cin>>num;
            Insert(A, Size, row_cursor, col_cursor, num);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case 'u':
        case 'U':
            Duplicated(A, Size, row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);

            break;
        case 'g':
        case 'G':
            GetCursor(Size, row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case 'q':
        case 'Q':
            Show(A, Size, row_cursor, col_cursor);
            cout << endl << "Thank you!" << endl << endl;
            break;
        case '4': //Left
            Cursor_Left(col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case '6': //Right
            Cursor_Right(Size, row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case '2': //Down
            Cursor_Down(Size,row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case '8': //Up
            Cursor_Up(Size,row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case '7': //home
            Cursor_Home(Size, row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        case '1': //end
            Cursor_End(Size,row_cursor, col_cursor);
            Show(A, Size, row_cursor, col_cursor);
            break;
        default:
            cout << "Enter correct command!"<<endl;
            break;
        }
    }while(command!='q'&& command !='Q');
    return 0;
}


int Random(int low, int high)
{
    int range = high-low+1;
    int randomNumber = low + (rand() % range);
    return randomNumber;
}

void Init(int A[][MAX], int Size[], int &row, int &col)
{
    for (int i=0; i<MAX; i++)
    {
        Si  ze[i]=Random(0,MAX);
        for (int j=0; j<Size[i]; j++)
        {
            A[i][j] = Random(0,99);
        }
    }
    row=MAX-1;
    if(Size[MAX-1]==0)
    {
        col=0;
    }
    else
    {
        col=Size[MAX-1]-1;
    }
}

void Show(int A[][MAX], int Size[], int row, int col)
{
    if(Size[row]==0)
    {
        col=-1;
    }
    cout<< "Row: " <<row<<" Col: " <<col<<endl;
    for (int i=0; i<MAX; i++)
    {
        int Row_Count=Size[i];
        if(Row_Count<10)
        {
            if(i==row && Size[i]==0)
            {
                cout<<"[:]   "<<Row_Count<<")   ";
            }
            else
            {
                cout<<" :    "<<Row_Count<<")   ";
            }
        }
        else
        {
            if(i==row && Size[i]==0)
            {
                cout<<"[:]   "<<Row_Count<<")  ";
            }
            else
            {
                cout<<" :    "<<Row_Count<<")  ";
            }
        }
        for (int j=0; j<Size[i]; j++)
        {
            if(i==row && j==col)
            {
                if(A[i][j]<10)
                {
                    cout<<" [ "<<A[i][j]<<"] ";
                }
                else
                {
                    cout<<" ["<<A[i][j]<<"] ";
                }
            }
            else
            {
                if(A[i][j]<10)
                {
                    cout<<"   "<<A[i][j]<<"  ";
                }
                else
                {
                    cout<<"  "<<A[i][j]<<"  ";

                }
            }
        }
        cout << endl;
    }
}

void Append(int A[][MAX], int Size[], int row, int &col, int Number)
{
    if (Size[row]>=MAX)
    {
        cout << "Overflow"<<endl;
    }
    else
    {
        col=Size[row];
        Size[row]+=1;
        A[row][col]= Number;
    }
}

void Delete(int A[][MAX], int Size[], int row, int &col)
{
    Size[row]--;
    if(Size[row]<0)
    {
        Size[row]=0;
    }
    for (int i=col; i<Size[row]; i++)
    {
        A[row][i]=A[row][i+1];
    }
    if(col>=Size[row])
    {
        col--;
    }
    if(col<0)
    {
        col=0;
    }
}

void Insert(int A[][MAX], int Size[], int row, int col, int Number)
{
    if (Size[row]>=MAX)
    {
        cout << "Overflow"<<endl;
    }
    else
    {
        Size[row]++;
        for (int i=Size[row]; i>col; i--)
        {
            A[row][i]=A[row][i-1];
        }
        A[row][col]=Number;
    }
}

void Duplicated(int A[][MAX], int Size[],int row, int &col)
{
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<Size[i]-1; j++)
        {
            if(A[i][j]==A[i][j+1])
            {
                for(j=j; j<Size[i]; j++)
                {
                    A[i][j+1]= A[i][j+2];
                }
                Size[i]--;
                j=-1;
            }
        }
    }
    if(col>=Size[row])
    {
        col=Size[row]-1;
    }
}

void GetCursor(int Size[], int &row, int &col)
{
    do
    {
        cin>>row;
        cin>>col;
        if(row>=MAX || col>=Size[row])
        {
            cout<<"Wrong Cursor. Enter Again."<<endl;
        }
    }while(row>MAX || col>Size[row]);
}

void Cursor_Left(int &col)
{
    col--;
    if(col<0)
    {
        col=0;
    }
}
void Cursor_Right(int Size[], int row, int &col)
{
    col++;
    if(col>=Size[row]-1)
    {
        col=Size[row]-1;
    }
    if(col<0)
    {
        col=0;
    }
}

void Cursor_Down(int Size[], int &row, int &col)
{
    row++;
    if(row>=MAX)
    {
        row=MAX-1;
    }
    else
    {
        if(col>=Size[row])
        {
            col=Size[row]-1;
        }
        if(col<0)
        {
            col=0;
        }
    }
}

void Cursor_Up(int Size[], int &row, int &col)
{
    row--;
    if(row<0)
    {
        row=0;
    }
    else
    {
        if(col>=Size[row])
        {
            col=Size[row]-1;
        }
        if(col<0)
        {
            col=0;
        }
    }
}

void Cursor_Home(int Size[], int &row, int &col)
{
    row=0;
    if(Size[row]==0)
    {
        col=-1;
    }
    else
    {
        col=0;
    }
}

void Cursor_End(int Size[], int &row, int &col)
{
    row=MAX-1;
    if(Size[row]==0)
    {
        col=-1;
    }
    else
    {
        col=Size[row]-1;
    }
}
