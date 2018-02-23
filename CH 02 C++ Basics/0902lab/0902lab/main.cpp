#include <iostream>

using namespace std;
/*
1. Read n numbers and print total, max, min and average
2. Read and print numbers (and their total) from user until total of all the numbers is 27
3. Read and print numbers as long as these numbers are between 10 and 20 inclusive.
4. Read and print numbers as long as these numbers are between 10 and 20 inclusive but not 13.
5. Read and print numbers as long as they are not between 10 and 20 inclusive but 13 is allowed.
*/
int main()
{
    int times;
    int num;
    int count = 1;
    int max;
    int min;
    int total;
    double ave;
    cout << "Game 1" << endl << endl;
    cout << "How many numbers do you want to input? ";
    cin >> times;
    cout << "Number 1: ";
    cin >> num;
    max = num;
    min = num;
    total = num;
    count += 1;
    while (count <= times)
    {
        cout << "Number " << count << ": ";
        cin >> num;
        total += num;
        if (num > max)
        {
            max = num;
        }
        if (num < min)
        {
            min = num;
        }
        count++;
    }
    ave = total / times;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << ave << endl;
    cout << "==========================================================================" << endl << endl;
    int total_2 = 0;
    cout << "Game 2" << endl << endl;
    do
    {
        cout << "Input a number: ";
        cin >> num;
        total_2 = total_2 + num;
        cout << "Your number: " << num << endl;
        cout << "Total: " << total_2 << endl << endl;
    }
    while (total_2 != 27);
    cout << "==========================================================================" << endl << endl;
    cout << "Game 3" << endl << endl;
    cout << "How many numbers input? ";
    cin >> times;
    count = 1;
    while (count <= times)
    {
        cout << "Number " << count << ": ";
        cin >> num;
        if (num > 10 && num < 20)
        {
            cout << num << " is between 10 & 20" << endl << endl;
        }
        count++;
    }
    cout << "==========================================================================" << endl << endl;
    cout << "Game 4" << endl << endl;
    cout << "How many numbers input? ";
    cin >> times;
    count = 1;
    while (count <= times)
    {
        cout << "Number " << count << ": ";
        cin >> num;
        if (num > 10 && num < 20 && num != 13)
        {
            cout << num << " is between 10 & 20 and it is not 13" << endl << endl;
        }
        count++;
    }
    cout << "==========================================================================" << endl << endl;
    cout << "Game 5 (Last Game)" << endl << endl;
    cout << "How many numbers input? ";
    cin >> times;
    count = 1;
    while (count <= times)
    {
        cout << "Number " << count << ": ";
        cin >> num;
        if (num < 10 || num > 20 || num == 13)
        {
            cout << num << " is not between 10 & 20, but 13." << endl << endl;
        }
        count++;
    }
    cout << "==========================================================================" << endl << endl;

    return 0;
}

