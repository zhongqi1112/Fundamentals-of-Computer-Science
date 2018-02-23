#ifndef GAME_H
#define GAME_H

#include <function.h>
#include <constants.h>
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();
private:
    sf::RenderWindow window;
    Function function;
};

#endif // GAME_H
