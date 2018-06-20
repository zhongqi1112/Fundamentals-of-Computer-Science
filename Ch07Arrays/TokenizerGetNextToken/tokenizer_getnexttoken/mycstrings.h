#ifndef MYCSTRINGS_H
#define MYCSTRINGS_H

#include <iostream>

using namespace std;

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
    else if (a<b)
    {
        return -1;
    }

}

int FindAny(char source[], char dights[], int Pos)
{
    char Source;
    for (int i=0; i<StrLen(source);i++)
    {
        Source=source[i];
        if(StrChr(Source, dights)>0)
        {
            Pos=i;
            return Pos;
        }
    }
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
    StrLen(dest);
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


#endif // MYCSTRINGS_H
