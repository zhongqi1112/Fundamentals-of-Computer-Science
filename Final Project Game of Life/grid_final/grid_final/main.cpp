#include <iostream>
#include <SFML/Graphics.hpp>
#include <gameoflife.h>

using namespace std;

int main()
{
    cout << "grid_button" << endl<<endl<<endl<<endl;
    int running=0, kai=0;
    int World[size][size], NeighborCount[size][size], Type;
    sf::Vector2f Size(cell_lengh, cell_lengh);
    sf::Vector2f SIZE(43, 43);
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    window.setFramerateLimit(10);
    sf::Event event;

    // inside the main loop, between window.clear() and window.display()
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text Button_1;
    sf::Text Button_2;
    sf::Text Button_3;
    sf::Text Button_4;
    sf::Text Button_5;
    sf::Text Button_6;

    Button_1.setFont(font);
    Button_2.setFont(font);
    Button_3.setFont(font);
    Button_4.setFont(font);
    Button_5.setFont(font);
    Button_6.setFont(font);

    Button_1.setString("Start");
    Button_2.setString("Stop");
    Button_3.setString("Random");
    Button_4.setString("Reset");
    Button_5.setString("Load");
    Button_6.setString("Save");

    Button_1.setCharacterSize(24);
    Button_2.setCharacterSize(24);
    Button_3.setCharacterSize(24);
    Button_4.setCharacterSize(24);
    Button_5.setCharacterSize(24);
    Button_6.setCharacterSize(24);

    Button_1.setColor(sf::Color::Red);
    Button_2.setColor(sf::Color::Red);
    Button_3.setColor(sf::Color::Red);
    Button_4.setColor(sf::Color::Red);
    Button_5.setColor(sf::Color::Red);
    Button_6.setColor(sf::Color::Red);

    Button_1.setPosition(500, 0);
    Button_2.setPosition(500, 44);
    Button_3.setPosition(500, 88);
    Button_4.setPosition(500, 132);
    Button_5.setPosition(500, 176);
    Button_6.setPosition(500, 220);


//    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

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

    window.draw(Button_1);
    window.draw(Button_2);
    window.draw(Button_3);
    window.draw(Button_4);
    window.draw(Button_5);
    window.draw(Button_6);


    Initial(World);

    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);

    //Draw:
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
                    int mouse_x=event.mouseButton.x/cell_lengh;
                    int mouse_y=event.mouseButton.y/cell_lengh;
                    cout<<"Current cell: ("<<mouse_x<<", "<<mouse_y<<")"<<endl;
                    MouseLeft(mouse_x, mouse_y, Type, World, running, kai);
                }
                break;
            }
        }

        if(kai)
        {
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
                    window.draw(start);
                    window.draw(stop);
                    window.draw(random);
                    window.draw(reset);
                    window.draw(read);
                    window.draw(save);
                    window.draw(shape);
                    window.draw(Button_1);
                    window.draw(Button_2);
                    window.draw(Button_3);
                    window.draw(Button_4);
                    window.draw(Button_5);
                    window.draw(Button_6);
                }
            }
            window.display();

        }

        if(running)
        {
            Initial(NeighborCount);
            NextGeneration(World, NeighborCount);

            //Draw:
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
                    window.draw(start);
                    window.draw(stop);
                    window.draw(random);
                    window.draw(reset);
                    window.draw(read);
                    window.draw(save);
                    window.draw(shape);
                    window.draw(Button_1);
                    window.draw(Button_2);
                    window.draw(Button_3);
                    window.draw(Button_4);
                    window.draw(Button_5);
                    window.draw(Button_6);
                }
            }
            window.display();

        }

        //Draw:
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
                window.draw(start);
                window.draw(stop);
                window.draw(random);
                window.draw(reset);
                window.draw(read);
                window.draw(save);
                window.draw(shape);
                window.draw(Button_1);
                window.draw(Button_2);
                window.draw(Button_3);
                window.draw(Button_4);
                window.draw(Button_5);
                window.draw(Button_6);
            }
        }
        window.display();

    }
    return 0;
}
