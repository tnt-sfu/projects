//Assignment 4: Maya Number Game
//Student group: cenyunz & tnt4

#include<iostream>
#include<iomanip>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;
// We do not use <cmath>

//Print thick block for 5. Length of block: 5 ch(s)
const char* ch = "\u2580";
void printFive(){
    cout << " " << ch << ch << ch << ch;
}

//Print o for 1
void printOne(){
    cout << "o";
}

// Void function to print Mayan Number. Raw muscle...
void printMayanNumber(int num){
    while(num>0){
        int res = num%20;
        if(res==0){
            cout << setw(4) << "00"; // setw(4) to make the 00 in the middle
        }
        else if(res==1){
            cout << setw(5); // when there is one o, setw(5) to let it on the right side
            printOne();
        }
        else if(res==2){
            cout << setw(4); 
            printOne();
            printOne();
        }
        else if(res==3){
            cout << setw(3);
            printOne();
            printOne();
            printOne();
        }
        else if(res==4){
            cout << setw(2);
            printOne();
            printOne();
            printOne();
            printOne();
        }
        else if(res==5){
            printFive(); // one five print one thick black block
        }
        else if(res==6){
            cout << setw(5);
            printOne();
            cout << endl;
            printFive();
        }
        else if(res==7){
            cout << setw(4);
            printOne();
            printOne();
            cout << endl;
            printFive();
        }
        else if(res==8){
            cout << setw(3);
            printOne();
            printOne();
            printOne();
            cout << endl;
            printFive();
        }
        else if(res==9){
            cout << setw(2);
            printOne();
            printOne();
            printOne();
            printOne();
            cout << endl;
            printFive();
        }
        else if(res==10){
            printFive();
            cout << endl; // starting from 10, there are two 5.
            printFive();
        }
        else if(res==11){
            cout << setw(5);
            printOne();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
        }
        else if(res==12){
            cout << setw(4);
            printOne();
            printOne();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
        }
        else if(res==13){
            cout << setw(3);
            printOne();
            printOne();
            printOne();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
        }
        else if(res==14){
            cout << setw(2);
            printOne();
            printOne();
            printOne();
            printOne();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
        }
        else if(res==15){
            printFive();
            cout << endl; // when it is 15, print 3 blocks
            printFive();
            cout << endl;
            printFive();
        }
        else if(res==16){
            cout << setw(5);
            printOne();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
        }
        else if(res==17){
            cout << setw(4);
            printOne();
            printOne();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
        }
        else if(res==18){
            cout << setw(3);
            printOne();
            printOne();
            printOne();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
        }
        else{ // res==19
            cout << setw(2);
            printOne();
            printOne();
            printOne();
            printOne();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
            cout << endl;
            printFive();
        }
        if(num/20!=0){
            cout << endl;
            cout << "------" << endl;
        }
        num = num / 20; // to make it in loop again or if num <0, out of the loop
    }
}

int main(){
    //Test value as required in section 3
    srand(time(NULL));

    // print the mayan number 2072025
    printMayanNumber(2072025);
    cout << endl;

    int max=0;
    //Global constant for user to exit the game
    const int TERMINATOR = 10;
    //Game header
    cout << "MAYAN NUMBER GAME" << endl;
    cout << "=================" << endl;
    cout << "You'll first enter a number (>= 10) to be the maximum number to guess."
    << "You'll then match a decimal number to its Maya equivalent." << endl;

    // Looping gameplay with the do while loop
    do{
        cout << "\nEnter maximum to guess from (< 10 exits): " << endl;
        cin >> max;

        //break out of the main do while loop if user put less than 10
        if (max < TERMINATOR){
            break;
        }

        //Computing 3 answers to display
        int correct_ans = rand()%(max-3)+4;
        cout << "Which of these Mayan numbers is equal to " << correct_ans << "?" << endl;
        int range1 = correct_ans*0.5;
        int range2 = correct_ans*1.5;
        int incorrect1 = rand()%(range1-range2-1)+range1;
        int incorrect2 = rand()%(range1-range2-1)+range1;

        /*
        Randomize answer output order with random_shuffle
        Headers included for this: <vector>, <algorithm>
        */
        vector <int> answersVector {correct_ans, incorrect1, incorrect2};
        random_shuffle (answersVector.begin(), answersVector.end());
        char letter = 'a';
        char correctChoice;
        for (unsigned int i = 0; i < answersVector.size(); i++){
            cout << letter <<". " << endl;
            printMayanNumber(answersVector.at(i));
            if (answersVector.at(i)==correct_ans){
               correctChoice = letter;
            }
            letter++;
            cout << endl;
        }
    
        // Getting user's answer
        cout << "Enter a, b, or c: ";
        char userAnswer;
        cin >> userAnswer;
        cout << endl;

        // Compare user's answer to vector element above and print out results
        if(userAnswer == correctChoice){
            cout << "CORRECT! The Mayan representation of " << correct_ans << " is" << endl;
            printMayanNumber(correct_ans);
        }
        else{
            cout << "INCORRECT! The Mayan representation of " << correct_ans << " is" << endl;
            printMayanNumber(correct_ans);
        }
    }
    while(max >= 10);
    
    return 0;
}