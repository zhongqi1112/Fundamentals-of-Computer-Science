#include <iostream>

using namespace std;

char slash;
const int max_month=12;
const int max_date=31;

void Getdate(int& m, int& d, int& y); //Get the date as input.

void Validate(int& m, int& d, int& y);
//If negative (but otherwise valid) values are entered, get absolute value. For invalid values, report error.

void Nextday(int& m, int& d, int& y); //Compute the next date.

int Daysinmonth(int m, int y); //Determine the number of days in a month.

int Leapyear(int y); //Determine whether a year is a leap year.

void Showdate(int m, int d, int y); // Output a date.

int main()
{
    cout << "Next Day" << endl << endl;
    int month, date, year;
    char ans;
    do
    {
        Getdate(month, date, year);
        Validate(month, date, year);
        Nextday(month, date, year);
        Daysinmonth(month, year);
        Leapyear(year);
        Showdate(month, date, year);
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << endl;
    return 0;
}

void Getdate(int& m, int& d, int& y)
{
    cout << "Input one day(mm/dd/yyyy):" << endl;
    cin >> m >> slash >> d >> slash >> y;
}

void Validate(int& m, int& d, int& y)
{
    while (m>max_month || d>max_date || m<1 || d<0)
    {
        cout << "The max month is 12, and the max date is 31. Enter again.";
        Getdate(m, d, y);
    }
}

void Nextday(int& m, int& d, int& y)
{
    int days;
    days=Daysinmonth(m,y);
    if(d==days)
    {
        d=1;
        m+=1;
        if(m==13)
        {
            m=1;
            y+=1;
        }
    }
    else
    {
        d+=1;
    }
}

int Daysinmonth(int m, int y)
{
    int days;
    if (m==2)
    {
        days=Leapyear(y);
    }
    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        days=31;
    }
    if (m==4 || m==6 || m==9 || m==11)
    {
        days=30;
    }
    return (days);
}

int Leapyear(int y)
{
    if (y%4==0)
        return (29);
    else
        return (28);
}

void Showdate(int m, int d, int y)
{
    cout << "The Next Day is(mm/dd/yyyy): " << endl << m << slash << d << slash << y << endl << endl;
}
