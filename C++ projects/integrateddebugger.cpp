// Program to experiment with the integrated debugger.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int factorial(int n) 
{
	//Bug: starts at multiply 0 which makes everthing 0. changed to 1.
    int answer = 1;
	for (int i = 1; i <= n; i++) {
		answer *= i;
	}
	return answer;
}

// Return the maximum number from a vector of integers.
// If the vector is empty, return 0.
int findMax(const vector<int> &vect)
{
	int max = 0;
	for (int val : vect) {
        //Bug: Condition was revese (val<max)
		if (max < val) {
			max = val;
		}
	}
	return max;
}

int main () 
{
	// Test factorial:
	const int MAX_FACTORIAL_TEST = 6;
	for (int n = 1; n <= MAX_FACTORIAL_TEST; n++) {
		cout << setw(2) << n 
				<< "! = " 
				<< setw(5) << factorial(n) << endl;
	}
	
	// Test findMax():
	cout << "a) " << findMax({1, 2, 3}) << endl;
	cout << "b) " << findMax({5, 0, 3, 4}) << endl;
	cout << "c) " << findMax({10}) << endl;
	cout << "d) " << findMax({-10}) << endl;
	cout << "e) " << findMax({}) << endl;
	cout << "f) " << findMax({100, 200, 34, -25, -2525, 3}) << endl;
	cout << "g) " << findMax({0}) << endl;
}
/*
6. Understanding:
1. How do you set a breakpoint on a line of code?
    Left click the red dot at the beginning of the line, to the left of the code
2. How do you step a program, one line at a time, to watch it execute?
    Step Over (F10) while running the Debugger (F5)
3. How can you watch the values in a variable as it executes (without having to call
cout all the time to print them)?
    Top left table "Varialbes" while running the debugger.
4. What kind of bug would be best explored with the debugger? A bug known to exist in
a small function, like factorial() or a bug somewhere in a much bigger program,
such as your most recent assignment? Why?
    A bug in a small function because we cant watch 10,000 lines of code being excecuted one at a time.
    For big program, we need to run tests.


*/