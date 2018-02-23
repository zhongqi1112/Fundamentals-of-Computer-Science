#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>

using namespace std;

const int size=20;

void Initial(int Array[][size]);
void NextGeneration(int World[][size], int Next[][size]);
void Show(int Array[][size]);


void Initial(int Array[][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            Array[i][j]=0;
        }
    }
}

void NextGeneration(int World[][size], int Next[][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            int X=i;
            int Y=j;
            for(int i=X-1; i<=X+1; i++)
            {
                for(int j=Y-1; j<=Y+1; j++)
                {
                    if(i==-1 && j==-1)
                    {
                        if(World[size-1][size-1]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                    else if(i==-1 && j==size)
                    {
                        if(World[size-1][0]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                    else if(i==size && j==-1)
                    {
                        if(World[0][size-1]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                    else if(i==size && j==size)
                    {
                        if(World[0][0]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                    else if(i==-1)
                    {
                        if(World[size-1][j]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                    else if(j==-1)
                    {
                        if(World[i][size-1]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                    else if(j==size)
                    {
                        if(World[i][0]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                    else if(i==size)
                    {
                        if(World[0][j]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                    else
                    {
                        if(World[i][j]==1)
                        {
                            Next[X][Y]++;
                        }
                    }
                }
            }
            if(World[X][Y]==1)
            {
                Next[X][Y]--;
            }
        }
    }

    //2. Fill out World(Next Generation):
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(Next[i][j]==3)
            {
                World[i][j]=1;
            }
            else if(Next[i][j]==2)
            {
                    World[i][j]=World[i][j];
            }
            else
            {
                World[i][j]=0;
            }
        }
    }

}

void Show(int Array[][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout<<Array[i][j]<<" ";
        }
        cout<<endl;
    }
}

#endif // GAMEOFLIFE_H
