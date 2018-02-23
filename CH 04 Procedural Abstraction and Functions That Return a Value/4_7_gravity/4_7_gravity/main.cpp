#include <iostream>

using namespace std;

double force (double mass_1, double mass_2, double distance, double g);

int main()
{
    cout << "4_7_gravity" << endl << endl;
    double m_1, m_2, d, f;
    const double g=6.673e-8;
    char ans;
    do
    {
        cout << "Input two mass:" << endl;
        cout << "Mass 1: ";
        cin >> m_1;
        cout << "Mass 2: ";
        cin >> m_2;
        cout << "Input the distance: ";
        cin >> d;
        f= force (m_1, m_2, d, g);
        cout << "Gravitational attractive force: " << f;
        cout << endl << endl;
        cout << "Do you want to do again? ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << endl;
    cout << "Thank you!" << endl << endl;
    cout << "==========================================================================" << endl << endl << endl;
    return 0;
}

double force (double mass_1, double mass_2, double distance, double g)
{
    return (g*mass_1*mass_2/distance/distance);
}
