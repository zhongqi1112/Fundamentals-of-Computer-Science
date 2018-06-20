#include <iostream>

using namespace std;

int main()
{
    cout << "3_1_paper_rock_scissor" << endl;
    cout << "[P]Paper, [R]Rock, [S]Scissor." << endl << endl;
    char player1;
    char player2;
    char ans;
    do
    {
        cout << "Player 1 Enter: ";
        cin >> player1;
        cout << "Player 2 Enter: ";
        cin >> player2;
        switch (player1)
        {
        case 'p':
        case 'P':
            switch (player2)
            {
            case 'p':
            case 'P': cout << "Tie!" << endl << endl;
                break;
            case 'r':
            case 'R': cout << "Player 1 Win!" << endl << endl;
                break;
            case 's':
            case 'S': cout << "Player 2 Win!" << endl << endl;
                break;
            default:
               cout << "Wrong Enter" << endl << endl;
            }
            break;
        case 'r':
        case 'R':
            switch (player2)
            {
             case 'p':
             case 'P': cout << "Player 2 Win!" << endl << endl;
                break;
            case 'r':
            case 'R': cout << "Tie!" << endl << endl;
                break;
            case 's':
            case 'S': cout << "Player 1 Win!" << endl << endl;
                break;
            default:
               cout << "Wrong Enter" << endl << endl;
            }
            break;
        case 's':
        case 'S':
            switch (player2)
            {
             case 'p':
             case 'P': cout << "Player 1 Win!" << endl << endl;
                break;
            case 'r':
            case 'R': cout << "Player 1 Win!" << endl << endl;
                break;
            case 's':
            case 'S': cout << "Tie!" << endl << endl;
                break;
            default:
               cout << "Wrong Enter" << endl << endl;
            }
            break;
         default:
            cout << "Wrong Enter" << endl << endl;
        }
        cout << "Do you want to play again? ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

