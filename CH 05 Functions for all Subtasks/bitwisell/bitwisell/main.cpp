#include <iostream>
#include <string>

using namespace std;
string Dec2Bin(int num);
int Mask(int pos);
bool IsSet(int n, int bitPos);
string TestBitExample(int n);


int main()
{
    int num;
    do{

        cin>>num;
        cout<<TestBitExample(num)<<endl;

    }while (true);
    cout <<endl<<endl<<endl<< "=======================" << endl;
    return 0;
}
//------------------------


int Mask(int pos)
{
    return (1<<pos);
}
bool IsSet(int n, int bitPos)
{
    //mask & n == mask : is set.

    int mask = Mask(bitPos);
    int anded =  (n & mask);
    if (anded ==mask)
            return true;
    else
        return false;
}

string TestBitExample(int n){
    string bin;
    int count = 0;
    for (int i=31; i>=0; i--){

        if(count++%4==0) bin=bin+" ";
        if (IsSet(n,i))
            bin=bin+"1";
        else
            bin=bin+"0";
    }
    return bin;
}



//----------------
void TestAnd(){
    //cout<<(5&8);
    char ch;
    ch = cin.get();
    int n =1;
    int i=0;
    while (ch!= 'q'){

        cout<<Dec2Bin((n<<i++));
        ch = cin.get();
    }
}
string Dec2Bin(int num){
    string bin;
    const int NUM_OF_BITS = 32;
    int bigPower2 = (1<<NUM_OF_BITS-2); //largest positive number
    //cout<<"bigPower2: "<<bigPower2<<endl;
    int count = 1;
    while(bigPower2>0){
        if (num>=bigPower2){
            bin=bin+"1";
            num-=bigPower2;
        }else
            bin=bin+"0";
        bigPower2 /=2;
        //cout<<num<<"  "<<bin<<endl;
        count++;
        if (count%4 == 0){
            bin=bin+" ";
        }
    }
    //cout<<"bigPower2"<<bigPower2<<endl;
    return bin;
}
