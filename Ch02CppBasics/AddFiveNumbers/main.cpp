#include <iostream>

using namespace std;

int main()
{
    int max = 5;
    int count = 1;
    int num;
    int total=0;
    cout << "Input a number";
    while (count<=max){
        cout<<": ";
        cin>>num;
        total = total + num;
        cout<<count<<" numbers, and new total: "<<total<<endl;
        count++;
    }
    cout << endl << "====================================" <<endl;
    return 0;
}

