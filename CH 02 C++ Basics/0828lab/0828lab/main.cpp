#include <iostream>

using namespace std;

int main()
{
    cout << "Math Game" << endl << "Are you ready?" <<endl;
    int count;
    int min;
    int max;
    cout << "Input a Low  number:  ";
    cin >> min;
    cout << "Input a High number:  ";
    cin >> max;
    count = min;
    cout << endl;
    cout << "No.1: Print Low to High" <<endl;
    while (count <= max)
    {
        cout << count << " ";
        count++;
    }
    cout <<endl;
    cout << "=================================================================" << endl << endl;
    cout << "No.2: Print Low to High Skip every 3 numbers" << endl;
    count = 0;
    while (count <= max){
            cout << count << " ";
            count++;
            count++;
            count++;
    }
    cout << endl;
    cout << "=================================================================" << endl << endl;
    int number_3_low;
    int number_3_high;
    int count_3;
    cout << "Input another Low  number:  ";
    cin >> number_3_low;
    cout << "Input another High number:  ";
    cin >> number_3_high;
    cout << endl;
    cout << "No.3 Print Low to High: Multiples of Four" << endl;
    count_3=number_3_low;
    while (count_3<=number_3_high){
        if (count_3 %4==0){
            cout << count_3 << " ";
        }
        count_3++;
    }
    cout << endl;
    cout << "=================================================================" << endl << endl;
    cout << "No.4 Print Low to High: Multiples of Seven" << endl;
    count_3=number_3_low;
    while (count_3<=number_3_high){
        if (count_3 %7==0){
            cout << count_3 << " ";
        }
        count_3++;
    }
    cout << endl;
    cout << "=================================================================" << endl << endl;
    int number_5_low;
    int number_5_high;
    int count_5;
    cout << "Input another Low  number for Game 5:  ";
    cin >> number_5_low;
    cout << "Input another High number for Game 5:  ";
    cin >> number_5_high;
    cout << endl;
    cout << "No.5 Print Low to High: Skip Multiples of Seven" << endl;
    count_5=number_5_low;
    while (count_5<=number_5_high){
        if (count_5 %7!=0){
            cout << count_5 << " ";
        }
        count_5++;
    }
    cout << endl;
    cout << "=================================================================" << endl << endl;
    int count_6=1;
    int num;
    int count_total_odd=0;
    int count_total_even=0;
    int count_avg_odd=0;
    int count_avg_even=0;
    int count_grand_total=0;
    double count_grand_avg=0;
    int count_odd_number=0;
    int count_even_number=0;
    cout << "Input 10 numbers: " << endl;
    while (count_6<=10) {
        cout << "Number " << count_6 << ": ";
        cin >> num;
        if (num%2==0) {
            count_total_even=count_total_even+num;
            count_avg_even=count_avg_even+num;
            count_even_number=count_even_number+1;
        }
        else {
            count_total_odd=count_total_odd+num;
            count_avg_odd=count_avg_odd+num;
            count_odd_number=count_odd_number+1;
        }
        count_grand_total=count_grand_total+num;
        count_grand_avg=count_grand_avg+num;
        count_6++;
    }
    cout <<endl;
    count_avg_odd=count_avg_odd/count_odd_number;
    count_avg_even=count_avg_even/count_even_number;
    cout << "Total odd numbers = " << count_total_odd << endl;
    cout << "Total even numbers = " << count_total_even << endl;
    cout << "Avg odd = " << count_avg_odd << endl;
    cout << "Avg even = " << count_avg_even << endl;
    cout << "Grand total = " << count_grand_total << endl;
    cout << "Grand avg = " << count_grand_avg/10 << endl;
    cout << "=================================================================" << endl << endl;
    cout << "Game over, Thank you!" << endl <<endl <<endl;
    return 0;
}

