// Exercise: Make this piece of code use functions!

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_VAL_IN_TABLE = 20;
const int DISPLAY_WIDTH = 10;

// Void Function to print out heading
void printOutHeading() 
{
    cout << setw(DISPLAY_WIDTH) << "n"
         << setw(DISPLAY_WIDTH) << "n^2"
         << setw(DISPLAY_WIDTH) << "1..n"
         << setw(DISPLAY_WIDTH) << "2^n" << endl;
    cout << setw(DISPLAY_WIDTH) << "---"
         << setw(DISPLAY_WIDTH) << "----"
         << setw(DISPLAY_WIDTH) << "-----"
         << setw(DISPLAY_WIDTH) << "--------" << endl;
}

// Int Function to calculate 2nd column, n^2
int CalculateNSquare (int n) 
{
    int nSquared = n * n;
    return (nSquared); 
}

// Int Function to calculate 3rd column, sum 1 to n
int CalSum1toN (int n)
{
    int sum1toN = 0;
    int i = 0;
    while (i <= n) {
            sum1toN += i;
            i++;}
    return (sum1toN);
}    

// Int Function to calculate 4th column, 2^n
int Cal2toTheN (int n)
{
    int twoToTheN = 1;
    int j = 1;
        while (j <= n) {
            twoToTheN *= 2;
            j++;
        }
    return (twoToTheN);
}

// Void function to call all other functions inside a while loop with n counting up
void PrintOutTable ()
{
    int n = 1;
    while (n <= MAX_VAL_IN_TABLE)
    {
        cout << setw(DISPLAY_WIDTH) << n
                << setw(DISPLAY_WIDTH) << CalculateNSquare(n)
                << setw(DISPLAY_WIDTH) << CalSum1toN(n)
                << setw(DISPLAY_WIDTH) << Cal2toTheN(n)
                << endl;
    n++;
    }
}

int main()
{
    // Calling all functions - final results
    printOutHeading();
    PrintOutTable();
    return 0;
}

// Understanding:
// 1. Define the function (void, int, etc), name it, and put the parameters in the bracket. For example: int CalculateNSquare (int n). At the end of the function, write: return (desired value);
// 2. This difference is best described with Dr. Brian analogy: Saying the vote out loud vs sending your vote in.