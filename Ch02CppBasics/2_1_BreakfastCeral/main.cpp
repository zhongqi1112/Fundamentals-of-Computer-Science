#include <iostream>

using namespace std;

int main()
{
    cout << "2_1_breakfast ceral" << endl << endl;
    const double metric_ton = 35273.92;
    double weight_ounces;
    double weight_tons;
    int boxes;
    char ans;
    do
    {
        cout << "Weight of a package of breakfast cereal in ounces: ";
        cin >> weight_ounces;
        weight_tons = weight_ounces / metric_ton;
        boxes = metric_ton / weight_ounces;
        cout << "Weight in metric tons: " << weight_tons << " tons" << endl;
        cout << "The number of boxes needed to yield one metric ton of cereal: " << boxes << endl;
        cout << "==========================================================================" << endl << endl;
        cout << "Do you want to repeat the calculation?(y/n) ";
        cin >> ans;
    } while (ans == 'y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}
