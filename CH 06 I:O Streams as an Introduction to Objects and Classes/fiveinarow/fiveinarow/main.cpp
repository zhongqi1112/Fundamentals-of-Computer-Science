#include <iostream>
#include <iomanip>

const int COL_SIZE = 16;
const int ROW_SIZE = 15;
char first_row[ROW_SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','P'};

using namespace std;

void wrongStep(int& i, int& j, int& step, char board[][COL_SIZE]);
void setupboard(char board[][COL_SIZE]);
//precondition: 10 characters and 10 integers.
//postcondition: the 10 characters is the horizontal coordinate
//the 10 integer are the vertical coordinate on a board.
void Playing(char board[][COL_SIZE]);
//precondition: a board and chesses.
//postcondition: after one player put a chess down, the function can find the location of the chess
//and put it in the board.
void show(char board[][COL_SIZE]);
//precondition: a board and chess from last step.
//postcondition: after each step, show the board and chesses which the player placed.
void checkHorizontal(int& step, bool& X_win, bool& O_win, char board[][COL_SIZE]);
//precondition: a board and chesses.
//postcondition: check if there is a 5 same symbol horizontal chesses in a lines
//and decide which player wins.
void checkVertical(int& step, bool& X_win, bool& O_win, char board[][COL_SIZE]);
//precondition: a board and chesses.
//postcondition: check if there is a 5 same symbol vertical chesses in a lines
//and decide which player wins.
void checkSlope_negative(int& step, bool& X_win, bool& O_win, char board[][COL_SIZE]);
//precondition: a board and chesses.
//postcondition: check if there is a 5 same symbol negative slope chesses in a lines
//and decide which player wins.
void checkSlope_positive(int& step, bool& X_win, bool& O_win, char board[][COL_SIZE]);
//precondition: a board and chesses.
//postcondition: check if there is a 5 same symbol positive slope chesses in a lines
//and decide which player wins.

int main()
{

    char board[ROW_SIZE][COL_SIZE];
    cout << "===========================================================================\n"
         << "Welcome come to FIVE-In-A-ROW game.\n"
         << "this game need two people to play, one is called player X, another is called player O.\n"
         << "What you see below is the board of the game.\n"
         << "each 0 is a space of the board.\n"
         << "you need to input the coordinate to put the chess piece like 3A.\n"
         << "===========================================================================\n";

    setupboard(board);
    Playing(board);
    return 0;
}

void wrongStep(int& i, int& j, int& step, char board[][COL_SIZE])
{
    if(j == 0 || board[i][j] == 'X' || board[i][j] == 'O')
    {
        cout << "the coordinate is not available."
             << "please input your coordinate again.";
        step--;
        if(board[i][j] == 'X')
            board[i][j] = 'X';
        else if(board[i][j] == 'O')
            board[i][j] = 'O';
        else
        {
            if(i == 0)
                board[i][j] = '1';
            else if(i == 1)
                board[i][j] = '2';
            else if(i == 2)
                board[i][j] = '3';
            else if(i == 3)
                board[i][j] = '4';
            else if(i == 4)
                board[i][j] = '5';
            else if(i == 5)
                board[i][j] = '6';
            else if(i == 6)
                board[i][j] = '7';
            else if(i == 7)
                board[i][j] = '8';
            else if(i == 8)
                board[i][j] = '9';
            else if(i == 9)
                board[i][j] = 'Q';
            else if(i == 10)
                board[i][j] = 'R';
            else if(i == 11)
                board[i][j] = 'S';
            else if(i == 12)
                board[i][j] = 'T';
            else if(i == 13)
                board[i][j] = 'U';
            else
                board[i][j] = 'V';
        }
    }
    else
    {
        if(step % 2 == 0)
            board[i][j] = 'X';
        else
            board[i][j] = 'O';
    }
}

void setupboard(char board[][COL_SIZE])             //set up the board of five-in-a-row;
{
    char first_row[ROW_SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','P'};
    int i, j;
    for(i = 0; i < ROW_SIZE; i++)
        cout << setw(2) << first_row[i];
    cout << endl;                                  // set up the first line of the braod as char;
    for(i = 0; i < ROW_SIZE; i++)
    {
        for(j = 0; j < COL_SIZE; j++)
        {
            if(j == 0)
            {
                if(i == 0)
                    board[i][j] = '1';
                else if(i == 1)
                    board[i][j] = '2';
                else if(i == 2)
                    board[i][j] = '3';
                else if(i == 3)
                    board[i][j] = '4';
                else if(i == 4)
                    board[i][j] = '5';
                else if(i == 5)
                    board[i][j] = '6';
                else if(i == 6)
                    board[i][j] = '7';
                else if(i == 7)
                    board[i][j] = '8';
                else if(i == 8)
                    board[i][j] = '9';
                else if(i == 9)
                    board[i][j] = 'Q';
                else if(i == 10)
                    board[i][j] = 'R';
                else if(i == 11)
                    board[i][j] = 'S';
                else if(i == 12)
                    board[i][j] = 'T';
                else if(i == 13)
                    board[i][j] = 'U';
                else
                    board[i][j] = 'V';              //set up the vertical coordinate;
            }
            else
                board[i][j] = ' ';                  //each space is blank;
            cout << board[i][j];
        }
        cout << endl;
    }                                               //set up the rest of board as integer;
}

void Playing(char board[][COL_SIZE])                //playing five-in-a-row;
{
    char ans;
    int i, j;
    bool X_win = false;
    bool O_win = false;
    cout << "Do you want to start?\n"
         << "input y for yes, n for no.\n";
    cin >> ans;                                     //ask the player to start;

    if(ans == 'y' || ans == 'Y')
    {
        int step = 0;
        char row, col;
        cout << "player X first.\n"
             << "then player O turn.\n"
             << "player X please input the coordinate you want, input row first, then input colume.\n";
        do
        {
            if(step % 2 == 0)
            {
                cout << "Player X coordinate: ";
                cin >> row;
                cin >> col;                        // get the coordinate of X;

                if(row == 'Q' || row == 'R' || row == 'S' || row == 'T' || row == 'U' || row == 'V')
                    i = (int)row - 72;
                else
                    i = (int)row - 49;             // use The ASCII Character Set up the horizontal coordinate;

                if(col == 'P')
                    j = (int)col - 65;
                else
                    j = (int)col - 64;             // use The ASCII Character Set up the vertical coordinate;

                wrongStep(i, j, step, board);      // put 'X' on the braod;

                checkHorizontal(step, X_win, O_win, board);  // check 5 Xs in horizonntal direction;
                checkVertical(step, X_win, O_win, board);    // check 5 Xs in vertical direction;
                checkSlope_negative(step, X_win, O_win, board);  // check 5 Xs slope down direction;
                checkSlope_positive(step, X_win, O_win, board);  // check 5 Xs slope up direction;
            }
            else
            {
                cout << "Player O coordinate: ";
                cin >> row;
                cin >> col;                        // get the coordinate of O;
                if(row == 'Q' || row == 'R' || row == 'S' || row == 'T' || row == 'U' || row == 'V')
                    i = (int)row - 72;
                else
                    i = (int)row - 49;             // use The ASCII Character Set up the horizontal coordinate;

                if(col == 'P')
                    j = (int)col - 65;
                else
                    j = (int)col - 64;             // use The ASCII Character Set up the vertical coordinate;

                wrongStep(i, j, step, board);
                checkHorizontal(step, X_win, O_win, board);  // check 5 Os in horizonntal direction;
                checkVertical(step, X_win, O_win, board);    // check 5 Os in vertical direction;
                checkSlope_negative(step, X_win, O_win, board);  // check 5 Os slope down direction;
                checkSlope_positive(step, X_win, O_win, board);  // check 5 Os slope up direction;
            }
            cout << endl;
            show(board);                           //show the board after each input the coordinate;
            step++;
            cout << "===========================================================================\n";
        }while(X_win == false && O_win == false);
    }
}


void show(char board[][COL_SIZE])
{
    char first_row[COL_SIZE] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','P'};
    for(int i = 0; i < ROW_SIZE; i++)
        cout << setw(2) << first_row[i];
    cout << endl;
    for(int i = 0; i < ROW_SIZE; i++)
    {
        for(int j = 0; j < COL_SIZE; j++)
        {
            cout << setw(2) << board[i][j];         // put the chess which the player put on the board;
        }
        cout << endl;
    }
}

void checkHorizontal(int& step, bool& X_win, bool& O_win, char board[][COL_SIZE])
{
    X_win = false;
    O_win = false;
    int count, i, j;
    if(step%2 == 0)
    {
        count = 0;
        for(i = 0; i < ROW_SIZE; i++)
        {
            for(j = 1; j < COL_SIZE; j++)
            {
                if(board[i][j] == 'X')              // check the X on the board;
                {
                    count++;                        // count how many Xs in a uninterrupted line;
                    if(count >= 5)
                    {
                        cout << "#########==========CONGRATULATIONS==========#########\n"
                             << "#########==========PLAYER X WINS!!==========#########\n";
                        X_win = true;
                        break;
                    }                               // when 5 Xs in a horizontal line, X wins;
                }
                else
                {
                    count = 0;                     // if found other symbol interrupt in X line
                }                                   // clear the count;
            }
            if(X_win)
                break;
        }
    }
    else
    {
        count = 0;
        for(i = 0; i < ROW_SIZE; i++)
        {
            for(j = 1; j < COL_SIZE; j++)
            {
                if(board[i][j] == 'O')              // check the O on the board;
                {
                    count++;                        // count how many Os in a uninterrupted line;
                    if(count >= 5)
                    {
                        cout << "#########==========CONGRATULATIONS==========#########\n"
                             << "#########==========PLAYER O WINS!!==========#########\n";
                        O_win = true;
                        break;                      // when 5 Os in a horizontal line, O wins;
                    }
                }
                else                                // if found other symbol interrupt in O line
                    count = 0;                     // clear the count;
            }
            if(O_win)
                break;
        }
    }
    return;
}


void checkVertical(int& step, bool& X_win, bool& O_win, char board[][COL_SIZE])
{
    X_win = false;
    O_win = false;
    int count, i, j;
    if(step%2 == 0)
    {
        count = 0;
        for(j = 1; j < COL_SIZE; j++)
        {
            for(i = 0; i < ROW_SIZE; i++)
            {
                if(board[i][j] == 'X')              // check the X on the board;
                {
                    count++;                        // count how many Xs in a uninterrupted line;
                    if(count >= 5)
                    {
                        cout << "#########==========CONGRATULATIONS==========#########\n"
                             << "#########==========PLAYER X WINS!!==========#########\n";
                        X_win = true;
                        break;
                    }                               // when 5 Xs in a vertical line, X wins;
                }
                else                                // if found other symbol interrupt in X line
                    count = 0;                     // clear the count;
            }
            if(X_win)
                break;
        }
    }
    else
    {
        count = 0;
        for(j = 1; j < COL_SIZE; j++)
        {
            for(i = 0; i < ROW_SIZE; i++)
            {
                if(board[i][j] == 'O')              // check the O on the board;
                {
                    count++;                        // count how many Os in a uninterrupted line;
                    if(count >= 5)
                    {
                        cout << "#########==========CONGRATULATIONS==========#########\n"
                             << "#########==========PLAYER O WINS!!==========#########\n";
                        O_win = true;
                        break;                      // when 5 Os in a horizontal line, O wins;
                    }
                }
                else                                // if found other symbol interrupt in O line
                    count = 0;                     // clear the count;
            }
            if(O_win)
                break;
        }
    }
    return;
}

void checkSlope_negative(int& step, bool& X_win, bool& O_win, char board[][COL_SIZE])
{
    X_win = false;
    O_win = false;
    int count, i, j, m = 0, n = 0;
    if(step%2 == 0)
    {
        count = 0;
        for(i = 0; i < ROW_SIZE; i++)
        {
            for(j = 1; j < COL_SIZE; j++)
            {
                if(board[i][j] =='X')               // check the X on the board;
                {
                    count++;                        // count how many Xs in a uninterrupted line;
                    m = i;
                    n = j;
                    do
                    {
                        m++;
                        n++;
                        if(board[m][n] == 'X')
                        {
                            count++;
                            if(count >= 5)
                            {
                                cout << "#########==========CONGRATULATIONS==========#########\n"
                                     << "#########==========PLAYER X WINS!!==========#########\n";
                                X_win = true;
                                break;
                            }                   // when 5 Xs in a negative slope line, X wins;
                        }
                        else                    // if found other symbol interrupt in X line
                            count = 0;         // clear the count;
                    }while(board[m][n] == 'X');
                }
                if(X_win)
                    break;
            }
            if(X_win)
                break;
        }
    }
    else
    {
        count = 0;
        for(i = 0; i < ROW_SIZE; i++)
        {
            for(j = 1; j < COL_SIZE; j++)
            {
                if(board[i][j] == 'O')              // check the O on the board;
                {
                    count++;                        // count how many Os in a uninterrupted line;
                    m = i;
                    n = j;
                    do
                    {
                        m++;
                        n++;
                        if(board[m][n] == 'O')
                        {
                            count++;
                            if(count >= 5)
                            {
                                cout << "#########==========CONGRATULATIONS==========#########\n"
                                     << "#########==========PLAYER O WINS!!==========#########\n";
                                O_win = true;
                                break;          // when 5 Os in a horizontal line, O wins;
                            }
                        }
                        else                    // if found other symbol interrupt in O line
                            count = 0;         // clear the count;
                    }while(board[m][n] == 'O');
                }
                if(O_win)
                    break;
            }
            if(O_win)
                break;
        }
    }
}

void checkSlope_positive(int& step, bool& X_win, bool& O_win, char board[][COL_SIZE])
{
    X_win = false;
    O_win = false;
    int count, i, j, m = 0, n = 0;
    if(step%2 == 0)
    {
        count = 0;
        for(i = 0; i < ROW_SIZE; i++)
        {
            for(j = 1; j < COL_SIZE; j++)
            {
                if(board[i][j] =='X')               // check the X on the board;
                {
                    count++;                        // count how many Xs in a uninterrupted line;
                    m = i;
                    n = j;
                    do
                    {
                        m++;
                        n--;
                        if(board[m][n] == 'X')
                        {
                            count++;
                            cout << "-  " << count << endl;
                            if(count >= 5)
                            {
                                cout << "#########==========CONGRATULATIONS==========#########\n"
                                     << "#########==========PLAYER X WINS!!==========#########\n";
                                X_win = true;
                                break;
                            }                   // when 5 Xs in a horizontal line, X wins;
                        }
                        else                    // if found other symbol interrupt in X line
                            count = 0;         // clear the count;
                    }while(board[m][n] == 'X');
                }
                if(X_win)
                    break;
            }
            if(X_win)
                break;
        }
    }
    else
    {
        count = 0;
        for(i = 0; i < ROW_SIZE; i++)
        {
            for(j = 1; j < COL_SIZE; j++)
            {
                if(board[i][j] == 'O')              // check the O on the board;
                {
                    count++;                        // count how many Os in a uninterrupted line;
                    m = i;
                    n = j;
                    do
                    {
                        m++;
                        n--;
                        if(board[m][n] == 'O')
                        {
                            count++;
                            cout << "+  "<< count<< endl;
                            if(count >= 5)
                            {
                                cout << "#########==========CONGRATULATIONS==========#########\n"
                                     << "#########==========PLAYER O WINS!!==========#########\n";
                                O_win = true;
                                break;          // when 5 Os in a horizontal line, O wins;
                            }
                        }
                        else                    // if found other symbol interrupt in O line
                            count = 0;         // clear the count;
                    }while(board[m][n] == 'O');
                }
                if(O_win)
                    break;
            }
            if(O_win)
                break;
        }
    }
}
