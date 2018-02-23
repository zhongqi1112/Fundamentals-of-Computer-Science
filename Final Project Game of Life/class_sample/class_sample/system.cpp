#include "system.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

System::System()
{
    initialArray(world);
    world[2][2]=1;
    world[3][3]=1;
    world[4][1]=1;
    world[4][2]=1;
    world[4][3]=1;

}

void System::initialArray(int Array[][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
            Array[i][j]=0;
    }

}

void System::Step()
{
    NextGen();

    //call the function to calculate the next generation
    //from here. uyou must bring in all the required
    //funcionts and make them part of the class.
    cout<<"system step"<<endl;
}

void System::NextGen()
{
    int temp[SIZE][SIZE];

    initialArray(temp);
//    if(int i=0)
//    {

//    }
    for(int i=1;i<SIZE-1;i++)
    {
        for(int j=1;j<SIZE-1;j++)
        {
            int m=i;
            int n=j;
            for(int i=m-1;i<=m+1;i++)
            {
                for(int j=n-1;j<=n+1;j++)
                {
                    if(world[i][j]==1)
                    {
                        temp[m][n]++;
                    }
                }
            }
            if(world[m][n]==1)
            {
                temp[m][n]--;
            }
         }
    }

    //update all the change from the initial to the next array
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if(temp[i][j]==3)
            {
                world[i][j]=1;
//                cout<<"cope:  "<<i<<endl<<endl;
            }
            else if(temp[i][j]==2)
            {

            }
            else
            {
                world[i][j]=0;
            }
        }
    }

}



void System::Show()
{

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
            cout<<world[i][j]<<" ";
        cout<<endl;
    }

}



void System::Draw(sf::RenderWindow & window)
{
    Show();
    sf::RectangleShape rectangle(sf::Vector2f(20,20));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(1);
    window.draw(rectangle);

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(world[i][j]==0)
            {
                rectangle.setFillColor(sf::Color(137,32,190));

            }
            else
            {
                rectangle.setFillColor(sf::Color(87,229,200));

            }
            rectangle.setPosition(20*j,20*i);
            window.draw(rectangle);
        }

    }




}
