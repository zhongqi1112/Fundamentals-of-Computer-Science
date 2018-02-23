#include <iostream>

using namespace std;

int strlen(char s[]);
int FindOnly(char source[], char dights[], int Pos);
int FindNotOnly(char source[], char dights[], int Pos);
int strchr(char source, char dights[]);
void substr(char source[], char dest[], int startnum, int endnum);

int main()
{
    cout << "find_any" << endl<<endl;
    int Pos;
    char dights[]="0123456789";
    char source[]="abcd54321efgh";
    char dest[10];
    cout<<"Dights: "<<dights<<endl;
    cout<<"Source: "<<source<<endl;
    strlen(dights);
    strlen(source);
    cout<<"Length: Dights: "<<strlen(dights)<<endl;
    cout<<"Length: Source: "<<strlen(source)<<endl;
    int startnum=FindOnly(source, dights, Pos);
    int endnum=FindNotOnly(source, dights, startnum+1);
    cout<<"Start: "<<startnum<<endl;
    cout<<"End: "<<endnum<<endl;
    substr(source, dest, startnum, endnum);
    cout<<"Strstr: "<<dest<<endl;
    cout<<endl<<"==================================="<<endl<<endl;
    return 0;
}

int strlen(char s[])
{
    int i=0;
    while (s[i]!='\0')
    {
        i++;
    }
    return i;
}

int FindOnly(char source[], char dights[], int Pos)
{
    char Source;
    for (int i=0; i<strlen(source);i++)
    {
        Source=source[i];
        if(strchr(Source, dights)>0)
        {
            Pos=i;
            return Pos;
        }
    }
}

int FindNotOnly(char source[], char dights[], int Pos)
{
    char Source;
    for (int i=Pos; i<strlen(source);i++)
    {
        Source=source[i];
        if(strchr(Source, dights)<0)
        {
            Pos=i-1;
            return Pos;
        }
    }
}

int strchr(char source, char dights[])
{
    for (int i=0; i<strlen(dights); i++)
    {
        if(dights[i]==source)
        {
            return i;
        }
    }
    return (-1);
}

void substr(char source[], char dest[], int startnum, int endnum)
{
    int j=0;
    for(int i=startnum; i<=endnum; i++)
    {
        dest[j]=source[i];
        j++;
    }
    dest[j]='\0';
    strlen(dest);
}
