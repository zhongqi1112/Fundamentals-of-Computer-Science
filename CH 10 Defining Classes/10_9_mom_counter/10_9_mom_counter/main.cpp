#include <iostream>
#include <counter.h>

using namespace std;

int main()
{
    cout << "10_9_mom_counter" <<endl<<endl;
    char keys;
    bool TurnOn=true;
    int Tens=0, Dollars=0, Dimes=0, Cents=0, digits;
    show(Tens, Dollars, Dimes, Cents);
    do
    {
        cin>>keys;
        switch (keys)
        {
        case'a':
        case'A':
            cin>>digits;
            incr1(Cents,digits);
            break;
        case's':
        case'S':
            cin>>digits;
            incr10(Dimes, digits);
            break;
        case'd':
        case'D':
            cin>>digits;
            incr100(Dollars, digits);
            break;
        case'f':
        case'F':
            cin>>digits;
            incr1000(Tens, digits);
            break;
        case'r':
        case'R':
            rest(Tens, Dollars, Dimes, Cents);
            break;
        case'q':
        case'Q':
            TurnOn=false;
            break;
        default:
            break;
        }
        if(overflow(Tens, Dollars, Dimes, Cents))
        {
            if(Cents>9)
            {
                Cents%=10;
                Dimes++;
            }
            if(Dimes>9)
            {
                Dimes%=10;
                Dollars++;
            }
            if(Dollars>9)
            {
                Dollars%=10;
                Tens++;
            }
            if(Tens>9)
            {
                cout<<"This was a long time ago"<<endl;
                Tens=9, Dollars=9, Dimes=9, Cents=9;
            }
        }
        show(Tens, Dollars, Dimes, Cents);
    }while(TurnOn);
    return 0;
}

