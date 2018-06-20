#include "counter.h"
#include <iostream>

using namespace std;

Counter::Counter()
{
    count=0;
    Max_count=9999;
}
Counter::Counter(int MAX)
{
    Max_count=MAX;
    count=0;
}

void Counter::reset()
{
    count=0;
}

void Counter::incr1()
{
    count+=1;
}

void Counter::incr10()
{
    count+=10;
}

void Counter::incr100()
{
    count+=100;
}

void Counter::incr1000()
{
    count+=1000;
}

bool Counter::overflow()
{
    if(count>Max_count)
    {
        return true;
    }
    return false;
}

void Counter::Print()
{
    if(!overflow())
    {

        if(count<10)
        {
            cout<<"000"<<count<<endl;
        }
        else if(count<100)
        {
            cout<<"00"<<count<<endl;
        }
        else if(count<1000)
        {
            cout<<"0"<<count<<endl;
        }
        else
        {
            cout<<count<<endl;
        }
    }
    else
    {
        cout<<endl<<"This was a long time ago"<<endl<<"0000"<<endl;
        reset();
    }
}
