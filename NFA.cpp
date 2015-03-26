#include <iostream>
#include <string>
using namespace std;

string inputWord;

bool startState(int);




/// EBAY

bool getEbay_E(int);
bool getEbay_B(int);
bool getEbay_A(int);
bool getEbay_Y(int);

/// WEB

bool getWeb_W(int);
bool getWeb_E(int);
bool getWeb_B(int);

bool controlLength ( int currentLetterIndex )
{
    return ( currentLetterIndex < inputWord.length() ) ? true : false;
}

void printState ( string stateName ,int currentLetterIndex )
{
    cout<< "-";
    for ( int i = 0 ; i < currentLetterIndex ; i++ )
    {
        cout << "-";
    }
    cout << stateName << " " << inputWord[currentLetterIndex] << endl;
}

int main()
{
    cout << "Please enter a word!" << endl;
    cout << " Word = ";
    cin>> inputWord;

    cout << " Word Length = " << inputWord.length() << endl;


    if ( startState(0) )
        cout << "This word accepted!" << endl;
    else
        cout << "This word NOT accepted!" << endl;
}

bool startState ( int currentLetterIndex )
{
    if ( !controlLength(currentLetterIndex) )
        return false;
    printState( "startState" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'e' )
        return ( getEbay_E (currentLetterIndex+1) || startState(currentLetterIndex+1) );
    else if ( inputWord[currentLetterIndex] == 'w' )
        return ( getWeb_W (currentLetterIndex+1) || startState(currentLetterIndex+1) );
    else
        return startState(currentLetterIndex+1);
}

bool getEbay_E ( int currentLetterIndex )
{
    printState( "getEbay_E" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'b' )
        return getEbay_B(currentLetterIndex+1);
    return false;
}

bool getEbay_B ( int currentLetterIndex )
{
    printState( "getEbay_B" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'a' )
        return getEbay_A(currentLetterIndex+1);
    return false;
}

bool getEbay_A ( int currentLetterIndex )
{
    printState( "getEbay_A" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'y' )
        return true;
    return false;
}

bool getWeb_W ( int currentLetterIndex )
{
    printState( "getWeb_W" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'e' )
        return getWeb_E(currentLetterIndex+1);
    return false;
}

bool getWeb_E ( int currentLetterIndex )
{
    printState( "getWeb_E" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'b' )
        return true;
    return false;
}
