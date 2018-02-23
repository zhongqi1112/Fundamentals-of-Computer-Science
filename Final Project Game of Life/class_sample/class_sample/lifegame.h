#ifndef LIFEGAME_H
#define LIFEGAME_H
#include <SFML/Graphics.hpp>
#include "system.h"


class Lifegame
{
public:
    Lifegame();
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();
    void ShowShapes();
private:
    sf::RenderWindow window;
    System system;
};

#endif // LIFEGAME_
