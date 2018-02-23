#include <iostream>
#include <SFML/Graphics.hpp>
#include <gameoflife.h>

using namespace std;

int main()
{
    cout << "grid_button" << endl<<endl<<endl<<endl;
    bool running=true;
    int World[size][size], NeighborCount[size][size];
    sf::Vector2f Size(10, 10);
    sf::Vector2f SIZE(20, 20);

    sf::RenderWindow window(sf::VideoMode(240, 220), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;

        sf::RectangleShape shape;
        sf::RectangleShape start;
        sf::RectangleShape stop;

        shape.setSize(Size);
        start.setSize(SIZE);
        stop.setSize(SIZE);

        start.setFillColor(sf::Color::Red);
        stop.setFillColor(sf::Color::Red);

        start.setPosition(220, 0);
        stop.setPosition(220, 22);

        window.draw(start);
        window.draw(stop);


        Initial(World);
        //First Generation:

        //        World[9][8]=1;
        //        World[9][9]=1;
        //        World[9][10]=1;

        World[1][3]=1;
        World[2][1]=1;
        World[2][3]=1;
        World[3][2]=1;
        World[3][3]=1;

        //    window.clear();
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
                window.draw(start);
                window.draw(stop);

                window.draw(shape);
            }
        }
        window.display();

        do
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // left mouse button is pressed: shoot
                //        gun.fire();
                // get the global mouse position (relatively to the desktop)
                sf::Vector2i globalPosition = sf::Mouse::getPosition();

                // get the local mouse position (relatively to a window)
                sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
            }

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            Initial(NeighborCount);
            NextGeneration(World, NeighborCount);
            //            cin.get();
            //            window.clear();
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
                    window.draw(start);
                    window.draw(stop);

                    window.draw(shape);
                }
            }
            window.display();
        }while(running);
    }
    return 0;
}
