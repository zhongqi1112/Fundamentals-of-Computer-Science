#include <iostream>

using namespace std;

int main()
{
    cout << "2_10_sum" << endl << endl;
    int num;
    int count;
    int sum_positive = 0;
    int sum_negetive = 0;
    int sum_total = 0 ;
    cout << "Input ten whole numbers, please." << endl;
    count = 1;
    while (count <=10)
    {
        cout << "Number " << count << " : ";
        cin >> num;
        if (num >0)
        {
            sum_positive = sum_positive + num;
        }
        else
        {
            sum_negetive = sum_negetive + num;
        }
        sum_total += num;
        count++;
    }
    cout << "Sum of all the numbers greater than zero: " << sum_positive << endl;
    cout << "Sum of all the numbers less than zero: " << sum_negetive << endl;
    cout << "Sum of all the numbers: " << sum_total << endl;
    cout << "==========================================================================" << endl << endl;
    return 0;
}

