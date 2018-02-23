#ifndef GETTOKEN_H
#define GETTOKEN_H

#include <iostream>
#include <fstream>
#include "gettoken.h"

using namespace std;

const int size=80000;
const int MAX=80000;
char ALPHA[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZé";
char NUMBERS[]="0123456789";
char PUNC[]=",./;'[]:{}<>?~!@#$%^&*()_+-=*|\"";
char SPACE[]={"     \n"};
int num_words=0, num_numbers=0, num_punc=0;


void GetToken(istream& inFile, char block[], char token[], char &tokenType, int &pos);
//Grabs blocks of text from the inFile, copies them to the block[] array and copies
//the (next) token into the token[] array. On future calls to this function, the next
//tokens will be copied into the token array[]…
//Once the end of the block[] string has been reached, another block is retrieved from
//the file and copied into block[] and this process continues.
//once the end of the file has been reached, false will be returned, otherwise (in
//case of a successful token retrieval), true is returned.


bool GetToken(char Block[], char Token[], char &TokenType, int &pos);
//Determines what type of token a character represents, and creates an array containing the token.

int Zorg(char MyString[], char CharSet[], char Substring[], int pos);
//Creates a substring of characters from MyString that can be found inside a character set, starting from a particular position.

void SkipSpace(char source[], int& pos);
//Skip Space

void Process(char Token[], char TokenType);


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



void GetToken(ifstream& inFile, char block[], char token[], char &tokenType, int &pos)
{
    inFile.open("Self-Introduction.txt");
    if (inFile.fail())
    {
        cout<<endl<<"****** could not open file for input. ******"<<endl;
        exit(0);
    }
    block[MAX+1];
    bool continuse=true;
    do
    {
        inFile.read(block, MAX);
        block[inFile.gcount()]=NULL;
//        cout<<"BLOCK: "<<block<<endl;
        while(continuse)
        {
            continuse=GetToken(block, token, tokenType, pos);
            cout<<token<<"  ";
            Process(token, tokenType);
        }
        continuse=true;
        pos=0;
//        cout<<block<<endl;
    }while(!inFile.eof());
    inFile.close();
    cout<<endl<<endl<<" --- END OF FILE ---"<<endl<<endl;
}


bool GetToken(char Block[], char Token[], char &TokenType, int &pos)
{
    bool real=false;
    SkipSpace(Block, pos);
    if(Find(ALPHA, Block[pos]))
    {
        TokenType='A';
        pos=Zorg(Block, ALPHA, Token, pos);
        real=true;
    }
    else if(Find(NUMBERS, Block[pos]))
    {
        TokenType='N';
        pos=Zorg(Block, NUMBERS, Token, pos);
        real=true;
    }
    else if(Find(PUNC, Block[pos]))
    {
        TokenType='P';
        pos=Zorg(Block, PUNC, Token, pos);
        real=true;
    }
    else if (!real)
    {
        pos++;
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
    pos=pos+StrLen(Substring);
    return pos;
}

void SkipSpace(char source[], int& pos)
{
    if(Find(SPACE,source[pos]))
    {
        pos++;
    }
}

void Process(char Token[], char TokenType)
{
    if(TokenType=='A')
    {
        num_words++;
    }
    else if(TokenType=='N')
    {
        num_numbers+=StrLen(Token);
    }
    else if(TokenType=='P')
    {
        num_punc+=StrLen(Token);
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

#endif // GETTOKEN_H
