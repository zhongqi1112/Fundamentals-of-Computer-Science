#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>


using namespace std;

const int size=40;

void Initial(int Array[][size]);
void Random (int Array[][size]);
void NextGeneration(int World[][size], int Next[][size]);
void Show(int Array[][size]);
void MouseLeft(int x, int y, int &type, int Array[][size], int &run, int &kai);


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

void Random (int Array[][size])
{
    int randomNumber;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            randomNumber=rand() % 2;
            if(randomNumber)
            {
                randomNumber=rand() % 2;
                Array[i][j]=randomNumber;
            }
            else
            {
                Array[i][j]=randomNumber;
            }
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

void MouseLeft(int x, int y, int &type, int Array[][size], int &run, int &kai)
{
    //Cells:  Change Array & Change Color
    if(x<size)
    {
        type=0;//Cells
        cout<<"Click on the cells"<<endl;
        if(Array[y][x])
        {
            Array[y][x]=0;
        }
        else
        {
            Array[y][x]=1;
        }
    }
    else
    {
        //Stat: Run
        if(y<=4)
        {
            type=1;//button_1
            cout<<"Click on the Button 1_Strat"<<endl;//Strat
            run=1;
        }

        //Stop: Pause
        else if(y>4 && y<=8)
        {
            type=2;//button_2
            cout<<"Click on the Button 2_Stop"<<endl;//Stop
            run=0;
        }

        //Random
        else if(y>8 && y<=12)
        {
            type=3;//button_3
            cout<<"Click on the Button 3_Random"<<endl;//Random
            Random(Array);
        }

        //Reset
        else if(y>12 && y<=16)
        {
            type=4;//button_4
            cout<<"Click on the Button 4_Reset"<<endl;//Reset
            Initial(Array);
        }

        //Read file
        else if(y>16 && y<=20)
        {
            type=5;//button_5
            cout<<"Click on the Button 5_Read"<<endl;//Read
            ifstream inFile;
            inFile.open("gameoflife.txt");
            for(int i=0; i<size; i++)
            {
                for(int j=0; j<size; j++)
                {
                    inFile>>Array[i][j];
                }
            }
            kai=1;
            inFile.close();
        }

        //Save file
        else if(y>20 && y<=24)
        {
            type=5;//button_6
            cout<<"Click on the Button 6_Save"<<endl;//Save
            ofstream inFile;
            inFile.open("gameoflife.txt");
            for(int i=0; i<size; i++)
            {
                for(int j=0; j<size; j++)
                {
                    inFile<<Array[i][j];
                    inFile<<" ";
                }
            }
            inFile.close();
        }
        else
        {
            cout<<"There is no Button"<<endl;
        }
    }
    cout<<endl;
}

#endif // GAMEOFLIFE_H
