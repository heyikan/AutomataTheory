#include <iostream>
#include <string>
using namespace std;

int currentLetterIndex = 0;
string inputWord;
bool isAcceptedState = false;
bool isWordFind = false;

int acceptControl ( );
void startState();

/// EBAY

void getEbay_E();
void getEbay_B();
void getEbay_A();
void getEbay_Y();

/// WEB

void getWeb_W();
void getWeb_E();
void getWeb_B();


void printStateName( string stateName )
{
    cout << inputWord.substr(0,currentLetterIndex) << " --> Now in " << stateName << " state" << endl;
}

int main()
{
    cout << "Please enter a word!" << endl;
    cout << " Word = ";
    cin>> inputWord;

    cout << " Word Length = " << inputWord.length() << endl;

    // State Starting
    startState( );
}

int acceptControl ( )
{
    /**
    * -1 = Not Accepted and Stop
    *  0 = Not Accepted and Continue
    *  1 = Accepted and stop
    *  2 = Accepted and Continue
    **/
    if ( inputWord.length() == 0 )
        return -1;
    if ( isWordFind && currentLetterIndex < inputWord.length() )
        return 2;
    else if ( isWordFind )
        return 1;
    if ( currentLetterIndex == inputWord.length() )
    {
        if ( isAcceptedState )
            return 1;
        else
            return -1;
    }
    else
        return 0;
}
void startState ( )
{
    printStateName("Start");
    isAcceptedState = false;
    int controlResult = acceptControl();
    if ( controlResult == 0 )
    {
        if ( inputWord[currentLetterIndex] == 'e' )
        {
            currentLetterIndex++;
            getEbay_E();
        }
        else if ( inputWord[currentLetterIndex] == 'w' )
        {
            currentLetterIndex++;
            getWeb_W();
        }
        else
        {
            currentLetterIndex++;
            startState();
        }
    }
    else
    {
        cout << "This word NOT accepted!" << endl;
    }
}

void getEbay_E ( )
{
    printStateName("E");
    isAcceptedState = false;
    int controlResult = acceptControl();
    if ( controlResult == 0 )
    {
        if ( inputWord[currentLetterIndex] == 'b' )
        {
            currentLetterIndex++;
              getEbay_B();
        }
        else
        {
            startState();
        }
    }
    else
        cout << "This word NOT accepted!" << endl;
}

void getEbay_B ( )
{
    printStateName("EB");
    isAcceptedState = false;
    int controlResult = acceptControl();
    if ( controlResult == 0 )
    {
        if ( inputWord[currentLetterIndex] == 'a' )
        {
            currentLetterIndex++;
            getEbay_A();
        }
        else
        {
            startState();
        }
    }
    else
        cout << "This word NOT accepted!" << endl;
}
void getEbay_A ( )
{
    printStateName("EBA");
    isAcceptedState = false;
    int controlResult = acceptControl();
    if ( controlResult == 0 )
    {
        if ( inputWord[currentLetterIndex] == 'y' )
        {
            currentLetterIndex++;
            getEbay_Y();
        }
        else
        {
            startState();
        }
    }
    else
        cout << "This word NOT accepted!" << endl;
}

void getEbay_Y ( )
{
    printStateName("EBAY");
    isAcceptedState = true;
    isWordFind = true;
    int controlResult = acceptControl();
    while ( controlResult == 2 )
    {
        printStateName("EBAY - Finish");
        currentLetterIndex++;
        controlResult = acceptControl();
    }
    cout << endl << "This word contains 'EBAY'. ACCEPTED!" << endl;
    return;
}
void getWeb_W()
{
    printStateName("W");
    isAcceptedState = false;
    int controlResult = acceptControl();
    if ( controlResult == 0 )
    {
        if ( inputWord[currentLetterIndex] == 'e' )
        {
            currentLetterIndex++;
            getWeb_E();
        }
        else
        {
            startState();
        }
    }
    else
        cout << "This word NOT accepted!" << endl;
}
void getWeb_E()
{
    printStateName("WE");
    isAcceptedState = false;
    int controlResult = acceptControl();
    if ( controlResult == 0 )
    {
        if ( inputWord[currentLetterIndex] == 'b' )
        {
            currentLetterIndex++;
            getWeb_B();
        }
        else
        {
            startState();
        }
    }
    else
        cout << "This word NOT accepted!" << endl;
}
void getWeb_B()
{
    printStateName("WEB - Finish");
    isAcceptedState = true;
    isWordFind = true;
    int controlResult = acceptControl();
    while ( controlResult == 2 )
    {
        printStateName("WEB - Finish");
        currentLetterIndex++;
        controlResult = acceptControl();
    }

    cout << endl << "This word contains 'WEB'. ACCEPTED!" << endl;
    return;
}
