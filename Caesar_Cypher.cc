
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

//prototypes
void displayMenu();

void setKey(int& key);

void encrypt(int key);

void decrypt(int key);

int main() {
    int choice, key;
    key = 3;
    do {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            cout << endl;
            setKey(key);
        }
        else if (choice == 2) {
            cout << endl;
            encrypt(key);
        }
        else if (choice == 3) {
            cout << endl;
            decrypt(key);
        }
    } while (choice != 4);
    return 0;
}
//print menu
void displayMenu()
{
    cout << "Type \"1\" to set key value.\nType \"2\" to encrypt a file." << endl;
    cout << "Type \"3\" to decrypt a file.\nType \"4\" to end program." << endl;
}
//get value for key
void setKey(int& key)
{
    cout << "Enter key:";
    cin >> key;
    cout << endl;
}

//add key to char ascii value
void encrypt(int key)
{
    ifstream inStream;
    ofstream outStream;
    string inFile;
    string outFile;
    cout << "Enter input file name: ";
    cin >> inFile;//input file
    
    inStream.open(inFile);
    
    if (inStream.fail())//check fail
    {
        cout << "Error: file not found" << endl;
        exit(0);
    }

    cout << "Enter output file name: ";
    cin >> outFile;//output file

    outStream.open(outFile);
    if (outStream.fail())//check fail
    {
        cout << "Error" << endl;
        exit(0);
    }

    char ch;
    inStream.get(ch);
    while (!inStream.eof())
    {
        if (ch != ' '){//Makes sure to not change whitespace
            ch += key;
        }
        outStream << ch;

        inStream.get(ch);
    }
   
}

//inverse of encrypt
void decrypt(int key)
{
    ifstream inStream;
    ofstream outStream;
    string inFile;
    string outFile;
    cout << "Enter input file name: ";
    cin >> inFile;
    
    inStream.open(inFile);
    
    if (inStream.fail())
    {
        cout << "Error: file not found" << endl;
        exit(0);
    }

    cout << "Enter output file name: ";
    cin >> outFile;

    outStream.open(outFile);
    if (outStream.fail())
    {
        cout << "Error" << endl;
        exit(0);
    }

    char ch;
    inStream.get(ch);
    while (!inStream.eof())
    {
        if (ch != ' '){
            ch -= key;
        }
        outStream << ch;

        inStream.get(ch);
    }
   
}
