#include <iostream>
#include <iomanip>
using namespace std;

// Using Function Bool; Whether number is prime.
bool isPrime(int num)
{
    int i = 2;
    while (i <= num)
    {
        if (num % i == 0 && num != i)
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    int value1;
    int value2;
    
    // Asking user for Value 1
    cout << "Enter a value between 1 and 999: ";
    cin >> value1;

    // Repeat if out of range
    while (value1 < 1 || value1 > 999)
    {
        cout << "The value must be greater than 0 and less than 1000: ";
        cin >> value1;
    }
    // Asking for value 2
    cout << "Enter a second value between 1 and 999: ";
    cin >> value2;
    
    // Repeat if out of range
    while (value2 < 1 || value2 > 999)
    {
        cout << "The value must be greater than 0 and less than 1000: ";
        cin >> value2;
    }

    // Swap order if value 1 larger than value 2
    if (value1 > value2)
    {
        int temp = value1;
        value1 = value2;
        value2 = temp;
    }

    // Calculate factors
    int i = value1;
    while (i <= value2)
    {
        cout << setw(4) << i;
        int countFactors = 0;

        int j = 1;
        while (j <= i)
        {
            if (i % j == 0)
            {
                cout << setw(4) << j;
                countFactors++;
            }
            j++;
        }

        cout << setw(3) << "(" << countFactors << ")";

        // Check for prime and perfect square
        if (isPrime(i))
        {
            cout << " **prime**";
        }
        else if (countFactors % 2 == 1)
        {
            cout << "  **perfect square**";
        }

        cout << endl;

        i++;
    }

    return 0;
}