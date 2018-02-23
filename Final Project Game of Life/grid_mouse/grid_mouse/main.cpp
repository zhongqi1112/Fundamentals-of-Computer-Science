#include <iostream>
#include <SFML/Graphics.hpp>
#include <gameoflife.h>

using namespace std;

int main()
{
    cout << "grid_button" << endl<<endl<<endl<<endl;
    int running=0;
    int World[size][size], NeighborCount[size][size], Type;
    sf::Vector2f Size(10, 10);
    sf::Vector2f SIZE(43, 43);

    sf::RenderWindow window(sf::VideoMode(483, 440), "SFML works!");

    //    while (window.isOpen())
    //    {
    sf::Event event;

    sf::RectangleShape shape;
    sf::RectangleShape start;
    sf::RectangleShape stop;
    sf::RectangleShape random;
    sf::RectangleShape reset;
    sf::RectangleShape read;
    sf::RectangleShape save;

    shape.setSize(Size);
    start.setSize(SIZE);
    stop.setSize(SIZE);
    random.setSize(SIZE);
    reset.setSize(SIZE);
    read.setSize(SIZE);
    save.setSize(SIZE);

    start.setFillColor(sf::Color::Red);
    stop.setFillColor(sf::Color::Red);
    random.setFillColor(sf::Color::Red);
    reset.setFillColor(sf::Color::Red);
    read.setFillColor(sf::Color::Red);
    save.setFillColor(sf::Color::Red);

    start.setPosition(440, 0);
    stop.setPosition(440, 44);
    random.setPosition(440, 88);
    reset.setPosition(440, 132);
    read.setPosition(440, 176);
    save.setPosition(440, 220);

    window.draw(start);
    window.draw(stop);
    window.draw(random);
    window.draw(reset);
    window.draw(read);
    window.draw(save);

    Initial(World);
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
            window.draw(random);
            window.draw(reset);
            window.draw(read);
            window.draw(save);

            window.draw(shape);
        }
    }
    window.display();


    while (window.isOpen())
    {
        while (window.pollEvent(event))//or waitEvent
        {
            // check the type of the event...
            switch (event.type)
            {
            // window closed
            // "close requested" event: we close the window
            case sf::Event::Closed:
                window.close();
                cout<<"Close Game"<<endl<<endl;
                break;

                // key pressed
            case sf::Event::KeyPressed:
                //...
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "The right button was pressed" << std::endl;
                    std::cout << "Mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "Mouse y: " << event.mouseButton.y << std::endl;
                }
                else
                {
                    std::cout << "The left button was pressed" << std::endl;
                    std::cout << "Mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "Mouse y: " << event.mouseButton.y << std::endl;
                    int mouse_x=event.mouseButton.x/11;
                    int mouse_y=event.mouseButton.y/11;
                    cout<<"Current cell: ("<<mouse_x<<", "<<mouse_y<<")"<<endl;
                    MouseLeft(mouse_x, mouse_y, Type, World, running);
                    while(running)
                    {
                        Initial(NeighborCount);
                        NextGeneration(World, NeighborCount);
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
                                window.draw(random);
                                window.draw(reset);
                                window.draw(read);
                                window.draw(save);
                                window.draw(shape);
                            }
                        }
                        window.display();
                    }
                }
            default:
                break;
            }
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
                    window.draw(random);
                    window.draw(reset);
                    window.draw(read);
                    window.draw(save);
                    window.draw(shape);
                }
            }
            window.display();
        }
    }
    return 0;
}



/*

                    int i=event.mouseButton.x/11;
                    int j=event.mouseButton.y/11;


                    if(i<size && j<size)
                    {
                        if(World[i][j])
                        {
                            World[j][i]=0;
                        }
                        else
                        {
                            World[j][i]=1;
                        }

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
                                window.draw(random);
                                window.draw(read);
                                window.draw(save);

                                window.draw(shape);
                            }
                        }
                        window.display();
                    }
                    else if(Type==1)// Button 1 ____ Start
                    {
                        //                        sf::Event event;
                        do
                        {
//                        while (window.pollEvent(event))//or waitEvent
//                        {
//                            // check the type of the event...
//                            switch (event.type)
//                            {
//                            // window closed
//                            // "close requested" event: we close the window
//                            case sf::Event::Closed:
//                                window.close();
//                                cout<<"Close Game"<<endl<<endl;
//                                break;

//                                // key pressed
//                            case sf::Event::KeyPressed:
//                                //...
//                                break;
                            if(sf::Event::MouseButtonReleased)
                            {
                                if (event.mouseButton.button == sf::Mouse::Right)
                                {
                                }
                                else
                                {
                                    Type=CellsType(mouse_x, mouse_y);
                                    if(Type==2);//Button 2__Stop
                                    {
                                        running=false;
                                    }
                                }
                            }
//                                break;
//                                do
//                                {
                                    if(Type==2);//Button 2__Stop
                                    {
                                        running=false;
                                    }
                                    Initial(NeighborCount);
                                    NextGeneration(World, NeighborCount);
                                    //            cin.get();
                                    //            window.();
                                    //            Show(World);
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
                                            window.draw(random);
                                            window.draw(read);
                                            window.draw(save);

                                            window.draw(shape);
                                        }
                                    }
                                    window.display();
//                            }
//                        }

                                }while(running);

*/
