#include <iostream>

using namespace std;

int main()
{
    cout << "3_8_blackjack" << endl;
    int num; // Numbers of cards
    int count;
    char cards; // 2-9, a, t, j, q, k
    int points; // cards points
    int total; // total points
    int ace_num; // numbers of ace
    char ans;
    cout << "You receive 2-5 cards." << endl;
    cout << "Input the 2-9" << endl;
    cout << "10, jack, queen, king, and ace as 't', 'j', 'q', 'k', and 'a'." << endl << endl;
    do
    {
        do
        {
            cout << "How many cards you have? ";
            cin >> num;
        } while (num > 5 || num < 1);
        cout << "What is your cards values?" << endl;
        count = 0;
        total = 0;
        ace_num = 0;
        while (count < num)
        {
            cin >> cards;
            switch (cards)
            {
            case '2':
                points = cards - '0';
                total += points;
                break;
            case '3':
                points = cards - '0';
                total += points;
                break;
            case '4':
                points = cards - '0';
                total += points;
                break;
            case '5':
                points = cards - '0';
                total += points;
                break;
            case '6':
                points = cards - '0';
                total += points;
                break;
            case '7':
                points = cards - '0';
                total += points;
                break;
            case '8':
                points = cards - '0';
                total += points;
                break;
            case '9':
                points = cards - '0';
                total += points;
                break;
            case 't':
            case 'T':
                points = 10;
                total += points;
                break;
            case 'j':
            case 'J':
                points = 10;
                total += points;
                break;
            case 'q':
            case 'Q':
                points = 10;
                total += points;
                break;
            case 'k':
            case 'K':
                points = 10;
                total += points;
                break;
            case 'a':
            case 'A':
                ace_num ++;
                points = 11;
                total += points;
                break;
            default:
                cout << "You Enter a wrong cards." << endl;
            }
            count++;
        }
        if (total <= 21)
        {
            cout << "Total: " << total << endl;
        }
        else
        {
            while (ace_num > 0 && total > 21)
            {
                total -= 10;
                ace_num --;
            }
            if (total <= 21)
            {
                cout << "Total: " << total << endl;
            }
            else
            {
                cout << "Busted!" << endl;
            }
        }
        cout << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

