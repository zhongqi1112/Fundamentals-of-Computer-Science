#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" <<endl <<endl <<endl;
    int year;
    cout << "What were you born? ";
    cin >> year;
    cout<<"You were born in " <<year <<endl;
    int age=2014-year;
    cout<<"You are " <<age << " years old.";
    if (age == 21)
    {
        cout<<" You are forever 21." <<endl <<endl;
    }
    if (age < 30)
    {
        cout<<" You are young." <<endl <<endl;
    }
    else
    {
        cout<<" You are old" <<endl <<endl;
    }
    cout<< "======================"<<endl<<endl;
    return 0;
}
