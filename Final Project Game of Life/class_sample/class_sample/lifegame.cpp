#include "Lifegame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "system.h"

using namespace std;

Lifegame::Lifegame()
{
    window.create(sf::VideoMode(600, 600), "SFML window!");
        //VideoMode class has functions to detect screen size etc.
        //RenderWindow constructor has a third argumnet to set style
        //of the window: resize, fullscreen etc.

        window.setFramerateLimit(3);
}
void Lifegame::Draw()
{
    system.Draw(window);

}



void Lifegame::processEvents()
{
    sf::Event event;

       while (window.pollEvent(event))//or waitEvent
           {
           // check the type of the event...
               switch (event.type)
               {
                   // window closed
                   // "close requested" event: we close the window
                   case sf::Event::Closed:
                       window.close();
                       break;

                   // key pressed
                   case sf::Event::KeyPressed:
                       switch(event.key.code){

                        case sf::Keyboard::Escape:
                             window.close();
                             break;
                       }

                       break;
//                   case sf::Event::

               //mouse
//               case sf::Event::MouseButtonPressed:
//                   std::cout<<"Mouse Button has been pressed"<<std::endl;


//                   switch (event.key.code)
//                   {
//                   case sf::Mouse::Left:
//                       std::cout<<"Left Key has been pressed"<<std::endl;

                           break;

                       default:
                           break;
               }
           }
//       }
}

void Lifegame::update()
{
    system.Step();
}

void Lifegame::render()
{
    window.clear();
           Draw();
           window.display();
//           cin.get();
}



void Lifegame::run()
{
    while (window.isOpen())
       {
           processEvents();
           update();
           render(); //clear/draw/display
       }
}
