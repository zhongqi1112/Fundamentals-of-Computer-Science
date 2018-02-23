#include <SFML/Graphics.hpp>
//#include <iostream>

//using namespace std;

int main()
{
    //    cout << "draw_grid" << endl;
    sf::Vector2f size(20,20);
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::RectangleShape shape;
    shape.setPosition(20,20);
    shape.setSize(size);
    shape.setFillColor(sf::Color::Green);
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
