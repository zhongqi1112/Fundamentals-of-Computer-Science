#include <iostream>
#include <SFML/Graphics.hpp>
#include <gameoflife.h>

using namespace std;

int main()
{
    cout << "game_of_life" << endl<<endl<<endl<<endl;
    int running=0, kai=0;
    int World[size][size], NeighborCount[size][size], Type;
    int button_x=(size+1)*cell_lengh;
    int word_size=4*cell_lengh;
    int speed=10;
    sf::Vector2f Size(cell_lengh, cell_lengh);
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    sf::Event event;
    // inside the main loop, between window.clear() and window.display()
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

    Button_1.setFont(font);
    Button_2.setFont(font);
    Button_3.setFont(font);
    Button_4.setFont(font);
    Button_5.setFont(font);
    Button_6.setFont(font);
    Button_7.setFont(font);
    Button_8.setFont(font);

    Button_1.setString("Start");
    Button_2.setString("Stop");
    Button_3.setString("Random");
    Button_4.setString("Reset");
    Button_5.setString("Load");
    Button_6.setString("Save");
    Button_7.setString("Speed +");
    Button_8.setString("Speed -");

    shape.setSize(Size);
    Button_1.setCharacterSize(word_size);
    Button_2.setCharacterSize(word_size);
    Button_3.setCharacterSize(word_size);
    Button_4.setCharacterSize(word_size);
    Button_5.setCharacterSize(word_size);
    Button_6.setCharacterSize(word_size);
    Button_7.setCharacterSize(word_size);
    Button_8.setCharacterSize(word_size);

    Button_1.setColor(sf::Color::Red);
    Button_2.setColor(sf::Color::Red);
    Button_3.setColor(sf::Color::Red);
    Button_4.setColor(sf::Color::Red);
    Button_5.setColor(sf::Color::Red);
    Button_6.setColor(sf::Color::Red);
    Button_7.setColor(sf::Color::Red);
    Button_8.setColor(sf::Color::Red);

    Button_1.setPosition(button_x, 0);
    Button_2.setPosition(button_x, 4*cell_lengh);
    Button_3.setPosition(button_x, 8*cell_lengh);
    Button_4.setPosition(button_x, 12*cell_lengh);
    Button_5.setPosition(button_x, 16*cell_lengh);
    Button_6.setPosition(button_x, 20*cell_lengh);
    Button_7.setPosition(button_x, 24*cell_lengh);
    Button_8.setPosition(button_x, 28*cell_lengh);


    window.draw(Button_1);
    window.draw(Button_2);
    window.draw(Button_3);
    window.draw(Button_4);
    window.draw(Button_5);
    window.draw(Button_6);
    window.draw(Button_7);
    window.draw(Button_8);

    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(outline);

    Initial(World);
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
            window.draw(shape);
            window.draw(Button_1);
            window.draw(Button_2);
            window.draw(Button_3);
            window.draw(Button_4);
            window.draw(Button_5);
            window.draw(Button_6);
            window.draw(Button_7);
            window.draw(Button_8);
        }
    }
    window.display();

    while (window.isOpen())
    {
        while (window.pollEvent(event))//or waitEvent
        {
            window.setFramerateLimit(speed);
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
                    MouseLeft(mouse_x, mouse_y, Type, World, running, kai, speed);
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
                    window.draw(shape);
                    window.draw(Button_1);
                    window.draw(Button_2);
                    window.draw(Button_3);
                    window.draw(Button_4);
                    window.draw(Button_5);
                    window.draw(Button_6);
                    window.draw(Button_7);
                    window.draw(Button_8);
                }
            }
            window.display();
            kai=0;
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
                    window.draw(shape);
                    window.draw(Button_1);
                    window.draw(Button_2);
                    window.draw(Button_3);
                    window.draw(Button_4);
                    window.draw(Button_5);
                    window.draw(Button_6);
                    window.draw(Button_7);
                    window.draw(Button_8);
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
                window.draw(shape);
                window.draw(Button_1);
                window.draw(Button_2);
                window.draw(Button_3);
                window.draw(Button_4);
                window.draw(Button_5);
                window.draw(Button_6);
                window.draw(Button_7);
                window.draw(Button_8);
            }
        }
        window.display();
    }
    return 0;
}
