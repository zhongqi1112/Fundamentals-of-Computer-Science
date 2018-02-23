#include <iostream>
#include "counter.h"

using namespace std;

int main()
{
    cout << "10_9_mom_counter_class" <<endl<<endl;
    Counter count;
    bool TurnOn=true;
    char keys;
    int digits;
    count.Print();
    do
    {
        cin>>keys;
        switch (keys)
        {
        case'a':
        case'A':
            cin>>digits;
            for(int i=0;i<digits;i++)
            {
                count.incr1();
            }
            break;
        case's':
        case'S':
            cin>>digits;
            for(int i=0;i<digits;i++)
            {
                count.incr10();
            }
            break;
        case'd':
        case'D':
            cin>>digits;
            for(int i=0;i<digits;i++)
                count.incr100();
            break;
        case'f':
        case'F':
            cin>>digits;
            for(int i=0;i<digits;i++)
            {
                count.incr1000();
            }
            break;
        case'r':
        case'R':
            count.reset();
            break;
        case'q':
        case'Q':
            TurnOn=false;
            break;
        default:
            break;
        }
        count.Print();
    }while(TurnOn);
    return 0;
}
