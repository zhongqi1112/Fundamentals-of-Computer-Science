#include "countertype.h"
#include <iostream>

using namespace std;

CounterType::CounterType()
{
    count=0;
}

CounterType::CounterType(int Counter)
{
    count=Counter;
}

void CounterType::reset()
{
    count=0;
}

bool CounterType::negative()
{
    if (count<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CounterType::incr1()
{
    count+=1;
}

void CounterType::decr1()
{
    count-=1;
}

void CounterType::print()
{
    if(!negative())
    {
        cout<<count<<endl;
    }
    else
    {
        cout<<"Can Not Negative"<<endl<<"0"<<endl;
        reset();
    }
}
