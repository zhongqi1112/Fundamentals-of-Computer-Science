#include <iostream>
#include <gameoflife.h>

using namespace std;

int main()
{
    cout<<"3_life"<<endl<<endl<<endl<<endl;
    bool running=true;
    int World[size][size], NeighborCount[size][size];
    Initial(World);
    //First Generation:
    World[10][9]=1;
    World[10][10]=1;
    World[10][11]=1;
    Show(World);
    do
    {
        Initial(NeighborCount);
        NextGeneration(World, NeighborCount);
        cin.get();
        Show(World);
    }while(running);
    return 0;
}

