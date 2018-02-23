#include <iostream>

using namespace std;

const double oz_in_lb=16.0, g_in_oz=28.35, kg_in_g=0.001, g_in_kg=1000, oz_in_g=0.03527, lb_in_oz=0.0625;
const double In_in_ft=12.0, cm_in_In=2.54, m_in_cm=0.01, cm_in_m=100, In_in_cm=0.3937, ft_in_In=0.083;

void convert(double X,double x,double& Y,double& y,double xInX,double xToy,double yInY);

int main()
{

    double ft=0, in=0, m=0, cm=0, lb=0, oz=0, kg=0, g=0;
    cout << "5_12_etc_unit_conversion_txt" << endl << endl;
    convert(5,3,kg,g,oz_in_lb,g_in_oz,kg_in_g);
    cout<<"5lbs and 3oz = "<<kg<<"kg "<<g<<"g"<<endl;
    convert(5,3,lb,oz,g_in_kg,oz_in_g,lb_in_oz);
    cout<<"5kg and 3g = "<<lb<<"lb "<<oz<<"oz"<<endl;
    convert(5,3,m,cm,In_in_ft,cm_in_In,m_in_cm);
    cout<<"5ft and 3in = "<<m<<"m "<<cm<<"cm"<<endl;
    convert(5,3,ft,in,cm_in_m,In_in_cm,ft_in_In);
    cout<<"5m and 3cm = "<<ft<<"ft "<<in<<"in"<<endl <<endl;
    return 0;
}

void convert(double X,double x,double& Y,double& y,double xInX,double xToy,double yInY)
{
    x=x+X*xInX;
    y=x*xToy;
    Y=static_cast<int>(y*yInY);
    y=x*xToy-Y/yInY;
}
