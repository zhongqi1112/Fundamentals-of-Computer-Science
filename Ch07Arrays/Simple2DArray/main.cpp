#include <iostream>

using namespace std;
const int ROWS = 4;
const int COLS = 6;
const int MAX = 5;
void Init(int A[], int item);
void Print(int A[], int numUsed);
int Append(int A[], int &numUsed, int item);
//----------------------
void Init(int A[][MAX]);
int main()
{
    int numUsed=10;
    int fail;

    int twoD[MAX][MAX];
    int oneD[MAX];

    Init(twoD);






    cout <<endl<<endl<< "=======================" << endl;
    return 0;
}
int Append(int A[], int &numUsed, int item){
    if (numUsed>=MAX){
        return 1; //overflow...
    }
    A[numUsed++] = item;
    return 0;
}

void Init(int A[][MAX]){
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            A[i][j] = i*10+j;
        }
    }

}



//--------------------------
void Print(int A[][MAX]){
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

}

void Init(int A[], int item){
    for (int i=0; i<MAX; i++){
        A[i] = item;
    }
}

void Print(int A[], int numUsed){
    for (int i=0; i<numUsed; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}



//=============================
void TestOneD(){
//    Init(oneD, 0);
//    for (int i=0; i<6; i++){
//        fail = Append(oneD, numUsed, (345<<i));
//        if (fail){
//            cout<<endl<<"** OVERFLOW **"<<endl;
//        }

//    }
//    Print(oneD, numUsed);

}
