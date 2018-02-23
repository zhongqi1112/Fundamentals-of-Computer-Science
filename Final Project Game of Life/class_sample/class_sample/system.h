#ifndef SYSTEM_H
#define SYSTEM_H
#include <SFML/Graphics.hpp>

const int SIZE=20;

class System
{
public:
    System();
    void Step();
    void NextGen();
    void Show();
    void initialArray(int Array[][SIZE]);
    void Draw(sf::RenderWindow& window);
private:
    int world[20][20];


};

#endif // SYSTEM_H
