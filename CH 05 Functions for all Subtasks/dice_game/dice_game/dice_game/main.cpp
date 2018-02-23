#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int initialized_money=100;

int Random(int low, int high);

void Displaydice(int dice_1, int dice_2);

int Wager(int dice_1, int dice_2, int wager);

int main()
{
    srand((unsigned)time(0));
    cout << "Dice Game" << endl << endl;
    char choice;
    int dice_1,dice_2,bet,total;
    cout << "Your initialized money is: $" << initialized_money << endl;
    cout << "Input your bet: $";
    cin >> bet;
    total=initialized_money;
    bool run=true;
    while (run==true)
    {
        cout << "[r]oll [b]et e[x]it" << endl;
        cin>> choice;
        switch (choice)
        {
        case 'r':
            cout << "Roll" << endl;
            while (bet>total)
            {
                cout << "Your total is: $" << total<<endl;
                cout << "Your bet is: $" << bet <<endl;
                cout << "Change your bet is smaller than total: $";
                cin >> bet;
            }
            dice_1 = Random(1,6);
            dice_2 = Random(1,6);
            Displaydice(dice_1,dice_2);
            total+=Wager(dice_1, dice_2,bet);
            cout << "Your bet is: $" << bet << endl;
            cout << "Your wager is: $" << Wager(dice_1, dice_2,bet) << endl;
            cout << "Total is: $" << total << endl;
            if (total==0)
            {
                run=false;
            }
            break;
        case 'b':
            cout << "Bet: $";
            cin >> bet;
            while (bet>total)
            {
                cout << "Your bet is bigger than your total, bet again." << endl;
                cout << "Bet: $";
                cin >> bet;
            }
            break;
        case 'x':
            run=false;
            break;
        }
    }
    cout << endl;
    cout << "Game over" << endl << endl;
    return 0;
}

int Random(int lo, int hi)
{
    int range = hi-lo+1;
    int randomNumber = lo + (rand() % range);
    return randomNumber;
}

void Displaydice(int dice_1, int dice_2)
{
    cout << "Dice is: " << dice_1 << endl;
    cout << "Dice is: " << dice_2 << endl;
}

int Wager(int dice_1, int dice_2, int wager)
{
    if(dice_1==dice_2)
    {
        return (wager*2);
    }
    if(dice_1+dice_2==7)
    {
        return (wager*3);
    }
    else
    {
        return (-wager);
    }
}
