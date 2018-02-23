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
    for(int i=1; i<size-1; i++)
    {
        for(int j=1; j<size-1; j++)
        {
            int X=i;
            int Y=j;
            for(int i=X-1; i<=X+1; i++)
            {
                for(int j=Y-1; j<=Y+1; j++)
                {
                    if(World[i][j]==1)
                    {
                        Next[X][Y]++;
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
//                    World[i][j]=World[i][j];
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
