#include <iostream>

using namespace std;

int main()
{
    cout << "2_6_meeting_room" << endl << endl; // Determines whether a meeting room is in violation of fire law regulations regarding the maximum room capacity
    int max; // maximum room capacity
    int num; // number of people to attend the meeting
    int addition; // additional people may legally attend
    int exclude; // be excluded in order to meet the fire regulations
    char ans;
    do{
       cout << "Maximum Room Capacity: ";
       cin >> max;
       cout << "Number of people to attend the meeting: ";
       cin >> num;
       if (num <= max)
       {
           addition = max - num;
           cout << "It is legal to hold the meeting." << endl;
           cout << "Additional people may legally attend: " << addition;
       }
       else
       {
           exclude = num - max;
           cout << "The meeting cannot be held as planned due to fire regulations!" << endl;
           cout << "People must be excluded in order to meet the fire regulations: " << exclude;
       }
       cout << endl;
       cout << "==========================================================================" << endl << endl;
       cout << "Do you want to repeat the calculation?(y/n) ";
       cin >> ans;
      } while (ans == 'y');
   cout << endl;
   cout << "Thank you!" << endl << endl;
   cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

