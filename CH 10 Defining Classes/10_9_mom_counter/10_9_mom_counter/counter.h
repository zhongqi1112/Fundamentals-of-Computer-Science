#ifndef COUNTER_H
#define COUNTER_H

using namespace std;

void rest(int &tens, int &dollars, int &dimes, int &cents);
void incr1(int &cents, int digits);
void incr10(int &dimes, int digits);
void incr100(int &dollars, int digits);
void incr1000(int &tens, int digits);
bool overflow(int &tens, int &dollars, int &dimes, int &cents);
void show(int tens, int dollars, int dimes, int cents);


void rest(int &tens, int &dollars, int &dimes, int &cents)
{
    tens=0, dollars=0, dimes=0, cents=0;
}

void incr1(int &cents, int digits)
{
    cents+=digits;
}

void incr10(int &dimes, int digits)
{
    dimes+=digits;
}

void incr100(int &dollars, int digits)
{
    dollars+=digits;
}

void incr1000(int &tens, int digits)
{
    tens+=digits;
}

bool overflow(int &tens, int &dollars, int &dimes, int &cents)
{
    if(cents>9||dimes>9||dollars>9||tens>9)
    {
        return true;
    }
    return false;
}

void show(int tens, int dollars, int dimes, int cents)
{
    cout<<tens<<dollars<<"."<<dimes<<cents<<endl;
}

#endif // COUNTER_H
