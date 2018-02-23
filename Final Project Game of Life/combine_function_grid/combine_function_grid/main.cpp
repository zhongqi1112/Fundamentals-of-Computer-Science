#include <iostream>
#include <SFML/Graphics.hpp>
#include <gameoflife.h>

using namespace std;

int main()
{
    cout << "combine_function_grid" << endl<<endl<<endl<<endl;
    bool running=true;
    int World[size][size], NeighborCount[size][size];
    sf::Vector2f Size(10, 10);
    sf::RenderWindow window(sf::VideoMode(220, 220), "SFML works!");
    sf::RectangleShape shape;
    shape.setSize(Size);

    Initial(World);
    //First Generation:

    //    World[9][8]=1;
    //    World[9][9]=1;
    //    World[9][10]=1;

    World[1][3]=1;
    World[2][1]=1;
    World[2][3]=1;
    World[3][2]=1;
    World[3][3]=1;

    window.clear();
    Show(World);
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            float box_x=11*j;
            float box_y=11*i;
            shape.setPosition(box_x, box_y);
            if(World[i][j])
            {
                shape.setFillColor(sf::Color::Green);
            }
            else
            {
                shape.setFillColor(sf::Color::Blue);
            }
            window.draw(shape);
        }
    }
    window.display();

        do
        {
            Initial(NeighborCount);
            NextGeneration(World, NeighborCount);
            cin.get();

            window.clear();
            Show(World);
            for(int i=0; i<size; i++)
            {
                for(int j=0; j<size; j++)
                {
                    float box_x=11*j;
                    float box_y=11*i;
                    shape.setPosition(box_x, box_y);
                    if(World[i][j])
                    {
                        shape.setFillColor(sf::Color::Green);
                    }
                    else
                    {
                        shape.setFillColor(sf::Color::Blue);
                    }
                    window.draw(shape);
                }
            }
            window.display();
        }while(running);
    return 0;
}
