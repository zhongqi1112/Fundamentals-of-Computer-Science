#include <iostream>
#include <fstream>

using namespace std;


void ReadIntsFromFile();
void WriteIntsToFile();
void WriteEvenNumbersOnly();

void OutputInts(ostream& outStream); //ostream, not oFstream!

void WriteIntArray(char fileName[], int intArray[], int size);
void ReadIntArray(char fileName[], int intArray[], int &size);
void PrintIntArray(int intArray[], int size);


char Menu()
{

    char ch;
    cout<<endl<<". . . . . . . . . . . . . . . . . . . . . "<<endl;
    cout<<"1. write ints to a file"<<endl;
    cout<<"2. read ints from a file"<<endl;
    cout<<"3. write int array to a file"<<endl;
    cout<<"4. read int array from a file"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"x. Exit"<<endl;
    cout<<": ";
    cin>>ch;
    cin.ignore(1000,'\n');
    cout<<endl<<". . . . . . . . . . . . . . . . . . . . . "<<endl;
    return ch;
}



int main()
{
    bool done = false;
    char choice=' ';
    int writeThis[] = {0,1,2,3,4,5,6,7,8,9};
    int readIntoThis[100];
    int numOfInts=-1;

    char outBlock[] = "this is a short block of characters";
    char inBlock[1001];


    do{
        choice = Menu();

        switch(choice)
        {
        case '1':WriteIntsToFile();
            break;
        case '2':ReadIntsFromFile();
            break;
        case '3':WriteIntArray("intfile.txt",writeThis,10);
            break;
        case '4':ReadIntArray("intfile.txt",readIntoThis,numOfInts);
            PrintIntArray(readIntoThis, numOfInts);
            break;

        case 'x':
        case 'X':
            done=true;
            break;
        }


    }while(!done);

    cout << endl<<endl<<"====== Done ===============" << endl;
    return 0;
}

//-----------------------------------------------

//example of outputting numbers
void WriteIntsToFile()
{
    ofstream outStream;
    outStream.open("file2.txt");
    if (outStream.fail())
    {
        cout<<"FAIL";
        exit(0);

    }
    for (int i=0; i<20; i++)
    {
        outStream<<i<<" ";
    }
    outStream.close();
    cout<<endl<<"a bunch of numbers were written to the file."<<endl;

}

//example of inputting numbers
void ReadIntsFromFile()
{
    cout<<"attempting to read ints from the file:"<<endl;

    ifstream inStream;
    inStream.open("file2.txt");
    if (inStream.fail())
    {
        cout<<"File filed to to open..."<<endl;
        exit(0);

    }
    cout<<endl<<"-- beginning of file --"<<endl;
    //this is our familiar pre-read while loop!

    int num;
    inStream>>num;
    while (!inStream.eof()) //have we reached the end of file marker?
    {
        cout<<num<<" ";
        inStream >> num;
    }
    cout<<endl<<"-- end of file --"<<endl;
    inStream.close();
}


//-----------------------------------------------------------


void WriteIntArray(char fileName[], int intArray[], int size)
{
    ofstream outFile;
    outFile.open(fileName);
    if (outFile.fail())
    {
        cout<<endl<<"***** could not open file for output. ****"<<endl;
        exit(0);
    }
    //write the size of the array first...
    outFile<<size<<endl;

    for (int i=0; i<size; i++)
    {
        //don't forget to leave some space
        //between numbers or you will have a bad day
        outFile<<intArray[i]<<" ";
    }

    outFile.close();

}

void ReadIntArray(char fileName[], int intArray[], int &size)
{
    ifstream inFile;
    inFile.open(fileName);
    if (inFile.fail())
    {
        cout<<endl<<"***** could not open file for input. ****"<<endl;
        exit(0);
    }
    //write the size of the array first...
    inFile>>size;
    for (int i=0; i<size; i++)
    {
        //don't forget to leave some space
        //between numbers or you will have a bad day
        inFile>>intArray[i];
    }

    inFile.close();

}

void PrintIntArray(int intArray[], int size)
{
    for (int i=0; i<size; i++)
    {
        cout<<intArray[i]<<" ";
    }
    cout<<endl;
}

//----------------------------------------------------

//example of reading from one file and writing to another
void WriteEvenNumbersOnly()
{

    ifstream inStream;  //to read from...
    inStream.open("file2.txt");
    if (inStream.fail())
    {
        cout<<"File filed to to open..."<<endl;
        exit(0);

    }

    ofstream outStream; //to write to...
    outStream.open("file3.txt");
    if (outStream.fail())
    {
        cout<<"FAIL";
        exit(0);

    }



    outStream<<endl<<"-- All the odd numbers in file2: --"<<endl;
    int num;
    inStream>>num;
    while (!inStream.eof())
    {
        if (num % 2 == 1)
        {
            outStream<<num<<" ";
        }
        inStream >> num;
    }
    outStream<<endl<<"-- end of file --"<<endl;

    inStream.close();
    outStream.close();
}
