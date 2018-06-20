#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream testFile;
    testFile.open("SimpleFile.txt");
    if (testFile.fail()){
        cout<<"Could not open output file..."<<endl;
        cin.get();
        return 2;
    }


    testFile << "Here is your file"<<endl;
    testFile.close();


    cout <<endl<<endl<<endl<< "=============================" << endl;
    return 0;
}
