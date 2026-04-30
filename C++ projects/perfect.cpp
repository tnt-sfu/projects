#include <iostream>
using namespace std;

// Bool function to check for properfactor

bool isProperFactor(int num, int divisor)
{
    if ((divisor < num) && (num % divisor == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Int function to return sum of proper factors
int sumProperFactors (int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        
        if ( isProperFactor(n,i) == 1)
        {
            sum += i;
        }
        else
        {
            continue;
        }
    
    }
    return sum;
}

// Bool function to check if n is a perfect number

bool isPerfectNumber (int n)
{
    if (n == sumProperFactors(n))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    //check if isProperFactor is working

    cout << "3 proper factor of 6? "<< isProperFactor(6,3) << endl;
    cout << "4 proper factor of 6? "<< isProperFactor(6,4) << endl;
    cout << "1 proper factor of 6? "<< isProperFactor(6,1) << endl;
    cout << "6 proper factor of 6? "<< isProperFactor(6,6) << endl;
    
    // Read user input and check if it's a perfect number

    cout << "Enter an integer: ";
    int checkNum;
    cin >> checkNum;
    cout << "Sum of proper factors: " << sumProperFactors(checkNum) << endl;
    if (isPerfectNumber(checkNum) == 1)
    {
        cout << "That's a perfect number." << endl;
    }
    else
    {
        cout << "Not a perfect number." << endl;
    }
    
    // Print out all perfect numbers from 1 to 10,000

    cout << "All perfect numbers from 1 to 10000: " << endl;
    for (int i = 1; i <= 10000; i++)
    {
        if(isPerfectNumber(i) == 1)
        {
            cout << i << endl;
        }
        else
        {
            continue;
        }
    }
    
    return 0;
}
/*
12. Understanding
◦ Describe (in words) what your main function would look like if you implemented it
without using functions. What is the advantage of using functions?
    
    It would look like an essay with a lot of different variables declared.
    Using functions made it look categorized.

◦ What would happen if the function isProperFactor() displayed the answer
instead of returned the answer? Would your program work?
    
    It would print out 1 and 0 and my program would not work if we call the function to check true or false like this.

◦ Inside sumProperFactor(), why is a for loop a good type of loop to use?

    Because we know where it starts and ends.

◦ Why are the following two lines of code interchangeable? Which is better? Why?
if (isProperFactor(n, i)) {...}
if (isProperFactor(n, i) == true) {...

    Because it's an Bool function, it holds value true or fales ( 1 or 0)
    I'm not sure if one is superior to another, but the 2nd line is clearer to me.
    Looking forward to this when lab 6 solution is released
*/