#ifndef MENU_H
#define MENU_H

#include <constants.h>
#include <function.h>

class Menu
{
public:
    Menu();
    void random ();
    void Start();
    void Stop();
    void Random();
    void Reset();
    void Load();
    void Save();
    void Speedincrease();
    void Speeddecrease();
private:
    int World[size][size];
//    Function function;
};

#endif // MENU_H
