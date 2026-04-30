// This program determines total buffet luncheon cost when
// the number of guests and the per person cost are known.
// It contains a logic error.
// By Gaddis, modified by B Fraser.
#include <iostream>
#include <iomanip>
using namespace std; 

const int ADULT_MEAL_COST = 6.25; // Child meal cost = 75% of this

int main()
{
    // Get number of adults and children attending
	cout << "This program calculates total cost "
	    << "for a buffet luncheon.\n";

	int numAdults = 0;
    cout << "Enter the number of adult guests (age 12 and over): ";
    cin >> numAdults;

    int numChildren = 0;
    cout << "Enter the number of child guests (age 2-11): ";
    cin >> numChildren;

	// Calculate meal costs
	double adultMealTotal = numAdults * ADULT_MEAL_COST; //THE BUG IS HERE: int * int wont return a double, have to cast one of it to double!
	double childMealTotal = numChildren * ADULT_MEAL_COST * .75;
	double totalMealCost  = adultMealTotal + childMealTotal;

	// Display total meal cost
	cout << fixed << setprecision(2);
	cout << "\nTotal buffet cost is " << totalMealCost << endl;
	return 0;
}
/*
Understanding

What is the bug in the mealCost.cpp program?
    - numAdults and ADULT_MEAL_COST are both int. The results of multiplication will always be int so we lose the cents part
    - Has to static cast 1 of them in the multiplication.

How to carefully test a program is correct.
    Quote from cs.waterloo.ca:
    "Apply 2 main methods of testing: white-box and black-box testing. 
    White-box testing examines the internal structure of a program and attempts to test each logical case. 
    White-box testing can be thought of as "transparent" box testing: the tester can see and test a specific section of code.
    Black-box testing (also known as data-driven or input/output-driven testing) in which the tester views the program as a black box, and as such, the inner workings of the program are unknown.
    The main tool used in black-box testing is the specification of the program: that is, the tester attempts to determine what input causes the output of the program to be different from what the specifications would require."
*/