#include <iostream>
#include "countertype.h"

using namespace std;

int main()
{
    CounterType Counter;
    char keys;
    int digits;
    bool TurnOn=true;
    cout << "10_5_counter"<<endl<<endl<<"[A]dd [D]ecrease [R]eset [Q]uit"<<endl;
    do
    {
        cin>>keys;
        switch(keys)
        {
        case'a':
        case'A':
            cin>>digits;
            for(int i=0;i<digits;i++)
            {
                Counter.incr1();
            }
            break;
        case'd':
        case'D':
            cin>>digits;
            for(int i=0;i<digits;i++)
            {
                Counter.decr1();
            }
            break;
        case'r':
        case'R':
            Counter.reset();
            break;
        case'q':
        case'Q':
            TurnOn=false;
            break;
        default:
            break;
        }
        Counter.print();
    }while(TurnOn);
    return 0;
}

