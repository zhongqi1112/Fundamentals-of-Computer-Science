#ifndef FUNCTION_H
#define FUNCTION_H
#include <constants.h>
#include <SFML/Graphics.hpp>

class Function
{
public:
    Function();
    void Step();
    void Initial(int Array[][size]);
    void Random ();
    void NextGen();
    void Show(int Array[][size]);
    void MouseLeft(int x, int y, int &speed);
    void Draw(sf::RenderWindow& window);
private:
    int World[size][size];
    int NeighborCount[size][size];
    bool pause;
};

#endif // FUNCTION_H
