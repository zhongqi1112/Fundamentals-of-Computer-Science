#ifndef FREQUENCIES_H
#define FREQUENCIES_H

#include <iostream>
#include <fstream>
#include <frequencies.h>

using namespace std;

const int size=16;

bool UsedAdd=true;
void Keyboard(int A[], int C[], int &N);
void File(int A[], int C[], int &N);
void Frequencies(int A[], int C[], int &N);
void Show(int A[], int C[], int &N);


void Keyboard(int A[], int C[], int &N)
{
    for(int i=0; i<size; i++)
    {
        cin>>A[i];
    }
    cout<<"Numbers Array:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;
    Frequencies(A, C, N);
}

void File(int A[], int C[], int &N)
{
    char filename[size];
    cout<<"Enter a file name: ";
    cin>>filename;
    ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        cout<<endl<<"****** could not open file for input. ******"<<endl;
        exit(0);
    }
    for(int i=0; i<size; i++)
    {
        inFile>>A[i];
    }
    cout<<"Numbers Array:"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;
    Frequencies(A, C, N);
}

void Frequencies(int A[], int C[], int &N)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[i]==A[j])
            {
                C[j]++;
                j=i;
                UsedAdd=false;
            }
            else
            {
                UsedAdd=true;
            }
        }
        if(UsedAdd)
        {
            N++;
            A[N]=A[i];
            C[N]=1;
        }
    }
}

void Show(int A[], int C[], int &N)
{
    cout<<"Number"<<"    "<<"Count"<<endl;
    for(int i=0; i<=N; i++)
    {
        cout<<A[i]<<"         "<<C[i]<<endl;
    }
    cout<<endl<<endl;
}



#endif // FREQUENCIES_H
