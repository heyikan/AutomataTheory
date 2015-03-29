#include <iostream>
#include <string>
using namespace std;

class DFA{

public:
  DFA()
  {
    currentLetterIndex = 0;
    isAcceptedState = false;
    isWordFind = false;
  }

  /// EBAY

  void getEbay_E();
  void getEbay_B();
  void getEbay_A();
  void getEbay_Y();

  /// WEB

  void getWeb_W();
  void getWeb_E();
  void getWeb_B();

  string getInputWord();
  void setInputWord(string val);

  void startState();
  void printStateName( string stateName );
  int acceptControl ( );

private:

  int currentLetterIndex;
  bool isAcceptedState;
  string inputWord;
  bool isWordFind;

};



class NFA{

public:

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

  bool controlLength ( int currentLetterIndex );
  void printState ( string stateName ,int currentLetterIndex );

  string getInputWord();
  void setInputWord(string val);


private:

  string inputWord;

};


string NFA::getInputWord()
{
  return inputWord;
}


void NFA::setInputWord(string val)
{
  inputWord = val;
}


bool NFA::controlLength ( int currentLetterIndex )
{
    return ( currentLetterIndex < inputWord.length() ) ? true : false;
}

void NFA::printState ( string stateName ,int currentLetterIndex )
{
    cout<< "-";
    for ( int i = 0 ; i < currentLetterIndex ; i++ )
    {
        cout << "-";
    }
    cout << stateName << " " << inputWord[currentLetterIndex] << endl;
}


bool NFA::startState ( int currentLetterIndex )
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




bool NFA::getEbay_E ( int currentLetterIndex )
{
    printState( "getEbay_E" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'b' )
        return getEbay_B(currentLetterIndex+1);
    return false;
}

bool NFA::getEbay_B ( int currentLetterIndex )
{
    printState( "getEbay_B" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'a' )
        return getEbay_A(currentLetterIndex+1);
    return false;
}

bool NFA::getEbay_A ( int currentLetterIndex )
{
    printState( "getEbay_A" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'y' )
        return true;
    return false;
}

bool NFA::getWeb_W ( int currentLetterIndex )
{
    printState( "getWeb_W" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'e' )
        return getWeb_E(currentLetterIndex+1);
    return false;
}

bool NFA::getWeb_E ( int currentLetterIndex )
{
    printState( "getWeb_E" , currentLetterIndex );
    if ( inputWord[currentLetterIndex] == 'b' )
        return true;
    return false;
}


string DFA::getInputWord()
{
  return inputWord;
}

void DFA::setInputWord(string val)
{
  inputWord = val;
}

void DFA::printStateName( string stateName )
{
    cout << inputWord.substr(0,currentLetterIndex) << " --> Now in " << stateName << " state" << endl;
}

int DFA::acceptControl ( )
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
void DFA::startState ( )
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

void DFA::getEbay_E ( )
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

void DFA::getEbay_B ( )
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
void DFA::getEbay_A ( )
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

void DFA::getEbay_Y ( )
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
void DFA::getWeb_W()
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
void DFA::getWeb_E()
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
void DFA::getWeb_B()
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



int main()
{
    string inputWord;


    cout << "Please enter a word!" << endl;
    cout << " Word = ";
    cin>> inputWord;


    cout << " Word Length = " << inputWord.length() << endl;

    DFA dfa;
    NFA nfa;

    dfa.setInputWord(inputWord);
    nfa.setInputWord(inputWord);

    int choice = 0;


    cout<<"DFA(1) or NFA(2) or All(3) ? "<<endl;
    cin>>choice;


      if(choice == 1)
      {
        cout<<"---------- DFA ---------- "<<endl;
        dfa.startState();
      }

      else if(choice == 2)
      {
        cout<<"---------- NFA ---------- "<<endl;
        if ( nfa.startState(0) )
            cout << "This word accepted!" << endl;
        else
            cout << "This word NOT accepted!" << endl;

      }

      else if(choice == 3)

      {
        cout<<"---------- DFA ---------- "<<endl;
        dfa.startState();

        cout<<"---------- NFA ---------- "<<endl;
        if ( nfa.startState(0) )
            cout << "This word accepted!" << endl;
        else
            cout << "This word NOT accepted!" << endl;

      }

      else
      {

        cout<<"Wrong Parameter!"<<endl;

      }
}
