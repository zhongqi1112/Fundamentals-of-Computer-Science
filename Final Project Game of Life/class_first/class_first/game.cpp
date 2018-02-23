#include "game.h"
#include "constants.h"
#include "function.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
//    window.setFramerateLimit(speed);
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); //clear/draw/display
    }
}

void Game::update()
{
    //cause changes to the data for the next frame
    //Step()
    function.Step();
}

void Game::render()
{
    window.clear();
    Draw();
    window.display();
}

void Game::Draw()
{
    //Look at the data and based on the data, draw shapes on window object.
    function.Draw(window);
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))//or waitEvent
    {
        int speed;
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
                function.MouseLeft(mouse_x, mouse_y, speed);
            }
            break;
        default:
            break;
        }
    }
}


