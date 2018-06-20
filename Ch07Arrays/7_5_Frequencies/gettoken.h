#ifndef GETTOKEN_H
#define GETTOKEN_H

const int size=50;
const int MAX=50;
char ALPHA[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char NUMBERS[]="0123456789";
char PUNC[]=",./;'[]:{}<>?~!@#$%^&*()_+-=*|";
char SPACE[]={"     \n"};

bool GetToken(char Block[], char Token[], char &TokenType, int &pos);
//Determines what type of token a character represents, and creates an array containing the token.

int Zorg(char MyString[], char CharSet[], char Substring[], int pos);
//Creates a substring of characters from MyString that can be found inside a character set, starting from a particular position.

void SkipSpace(char source[], int& pos);
//Skip Space


int StrLen(char s[]); //Returns an integer equal to the length of S
void StrCpy(char dest[], char src[]); //Copies the src into the dest
void StrCat(char dest[], char src[]); //Concatenates the src onto the end of the dest
int StrCmp(char S1[], char S2[]);//Compare the same or not
bool Find(char FindHere[], char target); //find a target character starting at a particular type
int FindAny(char source[], char dights[], int Pos); //Find the first occurrence in the source. Return its positon
int FindNotAny(char source[], char dights[], int Pos); //Find the first occurrence NOT in the source. Return its position.
int StrChr(char source, char dights[]); //Returns a pointer to the first occurrence of character in the source
int StrRChr(char source, char dights[]); //Returns a pointer to the last occurrence of character in the source
void SubStr(char source[], char dest[], int startnum, int endnum);//copies chars from src to dest in the index range
void StrNCpy(char dest[], char src[], int Limit); //The same as the two-argument strcpy except that at most Limit characters are copied
void StrNCat(char dest[], char src[], int Limit); //The same as the two-argument strcat except that at most Limit characters are appended
void Show(char chars[], int pos); //This will print the string and print a marker on the next line corresponding to pos
void ToLower(char upper[], char lower[]); //Convert the cstring to lower case
void ToUpper (char lower[], char upper[]); //Convert the cstring to upper case
void ReadBigFile(char fileName[]);
void new_line();
void Keyboard(int *pNum, int *pCount);
void File(int *pNum, int *pCount);
void CountNums(int *pNum, int **pCount, int count);
int FindHighestNum(int *pNum, int count);


#include <iostream>
#include <fstream>
#include "gettoken.h"

using namespace std;

bool GetToken(char Block[], char Token[], char &TokenType, int &pos)
{
    SkipSpace(Block, pos);
    if(Find(NUMBERS, Block[pos]))
    {
        TokenType='N';
        pos=Zorg(Block, NUMBERS, Token, pos);
    }
    if(Block[pos]!='\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Zorg(char MyString[], char CharSet[], char Substring[], int pos)
{

    int startnum=FindAny(MyString, CharSet, pos);
    int endnum=FindNotAny(MyString, CharSet, pos);
    if(endnum==-1)
    {
        endnum=StrLen(MyString)-1;
    }
    SubStr(MyString, Substring, startnum, endnum);
    return (pos+StrLen(Substring));
}

void SkipSpace(char source[], int& pos)
{
    if(Find(SPACE,source[pos]))
    {
        pos++;
    }
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

void StrCpy(char dest[], char src[])
{
    int i=0;
    for(i=0; i<StrLen(src); i++)
    {
        dest[i]=src[i];
    }
    dest[i]='\0';
}

void StrCat(char dest[], char src[])
{
    int i=StrLen(dest);
    int j=StrLen(src);
    int size=i+j;
    int a=0;
    for (i=StrLen(dest); i<size; i++)
    {
        dest[i]=src[a];
        a++;
    }
    dest[i]='\0';
}


int StrCmp(char S1[], char S2[])
{

    int a=0, b=0;
    for (int i=0; i<StrLen(S1);i++)
    {
        a=a+S1[i];
    }
    for(int j=0; j<StrLen(S2);j++)
    {
        b=b+S2[j];
    }
    if(a==b)
    {
        return 0;
    }
    else if (a>b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool Find(char FindHere[], char target)
{
    for(int i=0; i<StrLen(FindHere); i++)
    {
        if(target==FindHere[i])
        {
            return true;
        }
    }
    return false;
}

int FindAny(char source[], char dights[], int Pos)
{
    char Source;
    for (int i=Pos; i<StrLen(source);i++)
    {
        Source=source[i];
        if(StrChr(Source, dights)>=0)
        {
            Pos=i;
            return Pos;
        }
    }
    return -1;
}

int FindNotAny(char source[], char dights[], int Pos)
{
    char Source;
    for (int i=Pos; i<StrLen(source);i++)
    {
        Source=source[i];
        if(StrRChr(Source, dights)<0)
        {
            Pos=i-1;
            return Pos;
        }
    }
    return -1;
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

int StrRChr(char source, char dights[])
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

void SubStr(char source[], char dest[], int startnum, int endnum)
{
    int j=0;
    for(int i=startnum; i<=endnum; i++)
    {
        dest[j]=source[i];
        j++;
    }
    dest[j]='\0';
}

void StrNCpy(char dest[], char src[], int Limit)
{
    int i;
    for(i=0; i<Limit; i++)
    {
        dest[i]=src[i];
    }
    dest[i]='\0';
}
void StrNCat(char dest[], char src[], int Limit)
{
    int i, a=0;
    for (i=StrLen(dest); i<Limit+StrLen(dest); i++)
    {
        dest[i]=src[a];
        a++;
    }
    dest[i]='\0';
}
void Show(char chars[], int pos)
{
    cout<<chars<<endl;
    for(int i=0; i<pos; i++)
        cout<<".";
    cout<<"^"<<endl<<endl;
}
void ToLower(char upper[], char lower[])
{
    int i=0;
    for(i=0; upper[i]!='\0'; i++)
    {
        lower[i]=upper[i]+32;
    }
    lower[i]='\0';
}
void ToUpper (char lower[], char upper[])
{
    int i;
    for(i=0; lower[i]!='\0'; i++)
    {
        upper[i]=lower[i]-32;
    }
    upper[i]='\0';
}
void ReadBigFile(char fileName[])
{
    ifstream inFile;
    inFile.open(fileName);
    if (inFile.fail())
    {
        cout<<endl<<"****** could not open file for input. ******"<<endl;
        exit(0);
    }
    char block[MAX+1];
    do
    {
        inFile.read(block, MAX);
        block[inFile.gcount()]=NULL;
        //process the block here.
        //for now, our process is just to print the block
        cout<<block<<endl;
    }while(!inFile.eof());
    inFile.close();
    cout<<endl<<endl<<" --- END OF FILE _____"<<endl;
}
void new_line()
{
    char next_char;
    do
    {
        cin.get(next_char);
    }while(next_char!='\n');
}
void Keyboard(int *pNum, int *pCount)
{
    int count = 0;
    cout << "How many numbers to be put in ? (up to 50)";
    cin >> count;
    if (count > 50)
        count = 50;
    pNum = new int[count];
    cout << "Enter the numbers:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << i+1 << ": ";
        cin >> pNum[i];
    }
    CountNums(pNum, &pCount, count);
    for (int j = 0; j < (FindHighestNum(pNum, count)+1); j++)
    {
        if (pCount[j] > 0)
            cout << j << ": " << pCount[j] << endl;
    }
}

void File(int *pNum, int *pCount)
{
    for (int i = 0; i < StrLen(fin); i++)
    {
        cout << i+1 << ": ";
        fin>>pNum[i];
    }
    CountNums(pNum, &pCount, StrLen(fin));
    for (int j = 0; j < (FindHighestNum(pNum, count)+1); j++)
    {
        if (pCount[j] > 0)
            cout << j << ": " << pCount[j] << endl;
    }
}

void CountNums(int *pNum, int **pCount, int count)
{
    (*pCount) = new int[FindHighestNum(pNum, count)+1];
    for (int j = 0; j <= FindHighestNum(pNum, count); j++)
        (*pCount)[j] = 0;
    for (int i = 0; i < count; i++)
        (*pCount)[pNum[i]]++;
}
int FindHighestNum(int *pNum, int count)
{
    int highnum = 0;
    for (int i = 0; i < count; i++)
    {
        if (pNum[i] > highnum)
            highnum = pNum[i];
    }
    return highnum;
}


#endif // GETTOKEN_H
