#include <iostream>

using namespace std;

const int size=20;

void Show(int World[][size]);

int main()
{
    cout<<"3_life"<<endl<<endl<<endl<<endl;
    char command;
    int World[size][size], Next[size][size];
    //initial:
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            World[i][j]=0;
        }
    }


    //First Generation:
    World[10][9]=1;
    World[10][10]=1;
    World[10][11]=1;

//    World[8][10]=1;
//    World[9][8]=1;
//    World[9][10]=1;
//    World[10][9]=1;
//    World[10][10]=1;


    Show(World);

    do
    {
        //Fill out Next:

        //1. Fill out Next(Check how many life around this cell):
               //initial Next
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                Next[i][j]=0;
            }
        }

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

        cin.get();
        Show(World);
    }while(command!='q');
    return 0;
}

void Show(int World[][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout<<World[i][j]<<" ";
        }
        cout<<endl;
    }
}
