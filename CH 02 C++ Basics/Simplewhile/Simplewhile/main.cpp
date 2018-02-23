#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    cout << "When were you born? " << endl;
    int year;
    cin >> year;
    cout << "You were in " <<year << endl;
    int max, count, min;
    cout << "Input Low number ";
    cin >> min;
    cout << "Input High number ";
    cin >> max;
    count = min;
    if (count%7!=0){
        cout << "Winner" << endl;
    }
    else {
        cout << "Loser" << endl;
    }
    while (count <= max){
        if (count%7==0){
            cout << count << " ";
        count++;
        }
        else {
            cout << " ";
        cout << count << "@ " <<endl;
        }
        count++;
    }
    cout<<"=============="<<endl;
    int a=5;
    int b=0;
    int num;
    int total=0;
    cout << "input 5 number to add together";
    while (b<a)
    {
        cin >> num;
        total= total+ num;
        cout <<total;
        b++;
    }
    return 0;
}
