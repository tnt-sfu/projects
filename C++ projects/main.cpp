// Lab 1 Program
#include <iostream>
using namespace std;
int main()
{
    // Some simple output
    cout << "Hello lab world!\n";
    cout << "Greeting!" << endl;
    cout << "Stand up straigth with your shoulders back!" << endl;
    cout << "**********" << endl;
    cout << "A quote by Sir John A. Macdonald:" << endl;
    cout << "Let us be French, let us be English, but most importantly let us be Canadian!"<<endl;
    cout << "**********" << endl;

    // Read value from keyboard
    int favNum = 0;
    cout << "What is your favourite number? ";
    cin >> favNum;
    cout << "Wow! " << favNum << " is a great choice!" << endl;

    return 0;
}