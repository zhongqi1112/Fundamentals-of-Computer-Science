#include "menu.h"
#include "constants.h"
#include "function.h"
#include <iostream>
#include <fstream>

using namespace std;

Menu::Menu()
{

}

void Menu::random ()
{
    for(int i=0; i<50; i++)
    {
        int x=rand() % size;
        int y=rand() % size;
        World[x][y]=1;
    }
}

void Menu::Start()
{
    cout<<"Click on the Button 1_Strat"<<endl;//Strat
    pause=false;
}

void Menu::Stop()
{
    cout<<"Click on the Button 2_Stop"<<endl;//Stop
    pause=true;
}

void Menu::Random()
{
    cout<<"Click on the Button 3_Random"<<endl;//Random
    function.random();
    pause=true;
}

void Menu::Reset()
{
    //button_4
    cout<<"Click on the Button 4_Reset"<<endl;//Reset
    Initial(World);
    pause=true;
    speed=10;
}

void Menu::Load()
{
    //button_5
    cout<<"Click on the Button 5_Read"<<endl;//Read
    ifstream inFile;
    inFile.open("gameoflife.txt");
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            inFile>>World[i][j];
        }
    }
    pause=true;
    inFile.close();
}

void Menu::Save()
{
    //button_6
    cout<<"Click on the Button 6_Save"<<endl;//Save
    ofstream inFile;
    inFile.open("gameoflife.txt");
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            inFile<<World[i][j];
            inFile<<" ";
        }
        inFile<<endl;
    }
    inFile.close();
}

void Menu::Speedincrease()
{
    speed++;
}

void Menu::Speeddecrease()
{
    if(speed>1)
    {
        speed--;
    }
}
