#include "function.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;

Function::Function()
{
    Initial(World);
}

void Function::Initial(int Array[][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            Array[i][j]=0;
        }
    }
}

void Function::Random ()
{
    Initial(World);
    for(int i=0; i<50; i++)
    {
        int x=rand() % size;
        int y=rand() % size;
        World[x][y]=1;
    }
}

void Function::Step()
{
    //call the function to calculate the next generation
    //from here. uyou must bring in all the required
    //funcionts and make them part of the class.
    if(!pause)
    {
        Initial(NeighborCount);
        NextGen();
    }
}

void Function::Draw(sf::RenderWindow &window)
{
    sf::Vector2f Size(cell_lengh, cell_lengh);
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::RectangleShape shape;
    sf::Text Button_1;
    sf::Text Button_2;
    sf::Text Button_3;
    sf::Text Button_4;
    sf::Text Button_5;
    sf::Text Button_6;
    sf::Text Button_7;
    sf::Text Button_8;
    sf::Text Button_9;

    Button_1.setFont(font);
    Button_2.setFont(font);
    Button_3.setFont(font);
    Button_4.setFont(font);
    Button_5.setFont(font);
    Button_6.setFont(font);
    Button_7.setFont(font);
    Button_8.setFont(font);
    Button_9.setFont(font);

    Button_1.setString("Start");
    Button_2.setString("Stop");
    Button_3.setString("Random");
    Button_4.setString("Reset");
    Button_5.setString("Load");
    Button_6.setString("Save");
    Button_7.setString("Speed +");
    Button_8.setString("Speed -");
    Button_9.setString("Pattern");

    shape.setSize(Size);
    Button_1.setCharacterSize(word_size);
    Button_2.setCharacterSize(word_size);
    Button_3.setCharacterSize(word_size);
    Button_4.setCharacterSize(word_size);
    Button_5.setCharacterSize(word_size);
    Button_6.setCharacterSize(word_size);
    Button_7.setCharacterSize(word_size);
    Button_8.setCharacterSize(word_size);
    Button_9.setCharacterSize(word_size);

    Button_1.setColor(sf::Color::Red);
    Button_2.setColor(sf::Color::Red);
    Button_3.setColor(sf::Color::Red);
    Button_4.setColor(sf::Color::Red);
    Button_5.setColor(sf::Color::Red);
    Button_6.setColor(sf::Color::Red);
    Button_7.setColor(sf::Color::Red);
    Button_8.setColor(sf::Color::Red);
    Button_9.setColor(sf::Color::Red);

    Button_1.setPosition(button_x, 0);
    Button_2.setPosition(button_x, CEW*cell_lengh);
    Button_3.setPosition(button_x, 2*CEW*cell_lengh);
    Button_4.setPosition(button_x, 3*CEW*cell_lengh);
    Button_5.setPosition(button_x, 4*CEW*cell_lengh);
    Button_6.setPosition(button_x, 5*CEW*cell_lengh);
    Button_7.setPosition(button_x, 6*CEW*cell_lengh);
    Button_8.setPosition(button_x, 7*CEW*cell_lengh);
    Button_9.setPosition(button_x, 8*CEW*cell_lengh);

    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(outline);

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            float box_x=cell_lengh*j;
            float box_y=cell_lengh*i;
            shape.setPosition(box_x, box_y);
            if(World[i][j])
            {
                shape.setFillColor(sf::Color::Green);
            }
            else
            {
                shape.setFillColor(sf::Color::Black);
            }
            window.draw(shape);
            window.draw(Button_1);
            window.draw(Button_2);
            window.draw(Button_3);
            window.draw(Button_4);
            window.draw(Button_5);
            window.draw(Button_6);
            window.draw(Button_7);
            window.draw(Button_8);
            window.draw(Button_9);
        }
    }
}

void Function::NextGen()
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
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==-1 && j==size)
                    {
                        if(World[size-1][0]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==size && j==-1)
                    {
                        if(World[0][size-1]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==size && j==size)
                    {
                        if(World[0][0]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==-1)
                    {
                        if(World[size-1][j]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(j==-1)
                    {
                        if(World[i][size-1]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(j==size)
                    {
                        if(World[i][0]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else if(i==size)
                    {
                        if(World[0][j]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                    else
                    {
                        if(World[i][j]==1)
                        {
                            NeighborCount[X][Y]++;
                        }
                    }
                }
            }
            if(World[X][Y]==1)
            {
                NeighborCount[X][Y]--;
            }
        }
    }

    //2. Fill out World(Next Generation):
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(NeighborCount[i][j]==3)
            {
                World[i][j]=1;
            }
            else if(NeighborCount[i][j]==2)
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

void Function::Show(int Array[][size])
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

void Function::MouseLeft(int x, int y, int &speed)
{
    int Max_x, Min_x, Max_y, Min_y;
    //Cells:  Change Array & Change Color
    if(x<size)
    {
        //Cells
        cout<<"Click on the cells"<<endl;
        if(World[y][x])
        {
            World[y][x]=0;
        }
        else
        {
            World[y][x]=1;
        }
        pause=true;
    }
    else
    {
        //Stat: Run
        if(y<=CEW)
        {
            //button_1
            cout<<"Click on the Button 1_Strat"<<endl;//Strat
            pause=false;
        }

        //Stop: Pause
        else if(y>CEW && y<=2*CEW)
        {
            //button_2
            cout<<"Click on the Button 2_Stop"<<endl;//Stop
            pause=true;
        }

        //Random
        else if(y>2*CEW && y<=3*CEW)
        {
            //button_3
            cout<<"Click on the Button 3_Random"<<endl;//Random
            Random();
            pause=true;
        }

        //Reset
        else if(y>3*CEW && y<=4*CEW)
        {
            //button_4
            cout<<"Click on the Button 4_Reset"<<endl;//Reset
            Initial(World);
            pause=true;
            speed=10;
            cout<<"Speed: "<<speed<<endl;
        }

        //Load file
        else if(y>4*CEW && y<=5*CEW)
        {
            //button_5
            cout<<"Click on the Button 5_Load"<<endl;//Read
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

        //Save file
        else if(y>5*CEW && y<=6*CEW)
        {
            //button_6
            cout<<"Click on the Button 6_Save"<<endl;//Save
            ofstream inFile;
            inFile.open("gameoflife.txt");
            for(int i=0; i<size; i++)
            {
                for(int j=0; j<size; j++)
                {
                    inFile<<World[i][j]<<" ";
                }
//                inFile<<endl;
            }
            inFile.close();
        }

        //Button_7
        else if(y>6*CEW && y<=7*CEW)
        {
            cout<<"Click on the Button 7_Speed++"<<endl;//Speed++
            cout<<"Speed: "<<speed<<endl;
            speed++;
        }

        //Button_8
        else if(y>7*CEW && y<=8*CEW)
        {
            if(speed>1)
            {
                cout<<"Click on the Button 8_Speed--"<<endl;//Speed--
                speed--;
            }
            cout<<"Speed: "<<speed<<endl;
        }
        //SavePattern
        //Button_9
        //        else if(y>8*CEW && y<=9*CEW)
        //        {
        //            cout<<"Click on the Button 9_SavePattern"<<endl;//SavePattern
        //            ofstream inFile;
        //            inFile.open("gameoflife.txt");
        //            for(int i=0; i<size; i++)
        //            {
        //                for(int j=0; j<size; j++)
        //                {
        //                    if(i>=Min_y && i<=Max_y && j>=Min_x && j<=Max_x)
        //                    {
        //                        inFile<<World[i][j]<<" ";
        //                    }
        //                    else
        //                    {
        //                        inFile<<"0 ";
        //                    }
        //                }
        //                inFile<<endl;
        //            }
        //            inFile.close();
        //        }
        else
        {
            cout<<"There is no Button"<<endl;
        }
    }
    cout<<endl;
}

void Function::SavePattern(int mouse_x, int mouse_y, int end_mouse_x, int end_mouse_y)
{
    int Max_x, Min_x, Max_y, Min_y;
    if(mouse_x<end_mouse_x)
    {
        Max_x=end_mouse_x;
        Min_x=mouse_x;
    }
    else
    {
        Max_x=mouse_x;
        Min_x=end_mouse_x;
    }
    if(mouse_y<end_mouse_y)
    {
        Max_y=end_mouse_y;
        Min_y=mouse_y;
    }
    else
    {
        Max_y=mouse_y;
        Min_y=end_mouse_y;
    }
    if(mouse_x!=end_mouse_x && mouse_y!=end_mouse_y)
    {
        if(end_mouse_x<size)
        {
            cout<<"Released on the cells"<<endl;
            if(World[end_mouse_y][end_mouse_x])
            {
                World[end_mouse_y][end_mouse_x]=0;
            }
            else
            {
                World[end_mouse_y][end_mouse_x]=1;
            }
        }

        ofstream inFile;
        inFile.open("gameoflife.txt");

        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                if(i>=Min_y && i<=Max_y && j>=Min_x && j<=Max_x)
                {
                    if(i==Min_y && j==Min_x)
                    {
                        if(World[i][j])
                        {
                            inFile<<"0 ";
                        }
                        else
                        {
                            inFile<<"1 ";
                        }
                    }
                    if(i==Max_y && j==Max_x)
                    {
                        if(World[i][j])
                        {
                            inFile<<"0 ";
                        }
                        else
                        {
                            inFile<<"1 ";
                        }
                    }
                    else
                    {
                        inFile<<World[i][j]<<" ";
                    }
                }
                else
                {
                    inFile<<"0 ";
                }
            }
        }
        inFile.close();

    }

}
