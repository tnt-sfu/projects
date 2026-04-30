// Lab 2: Display song number and converting user's age.

#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    cout <<"SONG LIBRARY" << endl;
    cout <<"************" << endl;
    int songs = 0;
    cout << "Initial number of songs:              " << setw(3) << songs << endl;
    songs += 10;
    cout << "Number of songs after first purchase: " << setw(3) << songs << endl;
    songs += 644;
    cout << "Number of songs after today:          " << setw(3) << songs << endl; 

    // Understanding
    // What is the difference between defining a variable and using a variable? 
    // Defining a varible is to give a name to a storage area that our programs can manipulate, also to tell the compiler where and how much storage to create and what type of data being used.
    // When looking at a C++ program, how can you tell where a variable is defined? 
    // We look for declaration statement like const, int, doubles, etc.
    // What happens if you try to redeclare a variable? 
    // Compiler gives me error: redeclaration of 'variable'

    // Asking User's age
    int user_age = 0;
    cout << "What is your age in years? ";
    cin >> user_age;
    
    // Calculate and print out number of days they have lived
    const int days_per_year = 365;
    cout << " On your last birthday you have lived " << user_age * days_per_year << " days! " << endl;
    
    // Calculate and display the number of complete decades users have lived
    const int years_per_decade = 10;
    int number_of_decade = user_age / years_per_decade;
    cout << " On your last birthday you have also lived " << number_of_decade << " complete decades " << endl;
    
    // Calculate and display how many years to be one decade older
    int number_of_year_since_the_last_decade = user_age % years_per_decade;
    cout << " It will be " << years_per_decade - number_of_year_since_the_last_decade << " years until you are one decade older" << endl;
    
    // Display how many centuries old
    const double years_per_century = 100.0;
    cout << " You are also " << user_age / years_per_century << " centuries old." << endl;
    
    // Understanding
    // To test the number of days, some usefull input could be 1, 2, or 10 years old. With these, we don't really need a calculator.

    // Display if user is a minor
    const int minor_threshhold = 19;
    if (user_age < minor_threshhold) {
    cout << "You are a minor in BC " << endl;}

    // Display if user is a senior
    const int senior_threshhold = 65;
    if (user_age >= senior_threshhold) {
    cout << "You are a senior in BC" << endl;
    
    // Display numbers of years users have been a senior
    cout << "You have been a senior for " << user_age - senior_threshhold << " years." << endl;
    
    // Feeling input from user and word of encouragement
    string feeling_input;
    cout << "How does it feel to be a senior?" << endl;
    cin >> feeling_input;
    cout << "I see. Thank you for your years of contribution!" << endl;
    }

    // Understanding
    // Yes, I did use braces for both.
    // 3a. Yes, I would realize my mistake because VScode would red-highlighted at my second if statement, and my current tab (varibles.cpp) would also be red-highlighted.
    // 3b. VScode will red-highlighted my return line, and also my current tab (varibles.cpp) to remind me of the error.
    // Negative integers are still integers but invalid for age. My program will still go ahead and calculate as if negative age is valid. 
    // The most direct approach I can think of is to integrate a while loop, print out error message to users and ask to re-enter positive value as long as input value is negative.

    return 0;    
}