
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool hasNegative(double *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < 0)
        {
            return true;
        }
    }
    return false;
}

void zeroDissimilarPrefix(int *pA, int *pB)
{

}
const int NUM_DIGITS = 10;
void testZeroPrefix(int a, int b)
    {
    cout << "Test on " << setw(NUM_DIGITS) << a
    << " and " << setw(NUM_DIGITS) << b << endl;
    zeroDissimilarPrefix(&a, &b);
    cout << " = " << setw(NUM_DIGITS) << a
    << " and " << setw(NUM_DIGITS) << b << endl;
    }


int main() 
{   
    double arr1[] {2, 5.2, 6, 8, 6, 10, 325532, 0};
    cout << "Has negative #1?: " << hasNegative(arr1, 8) << endl;
    double arr2[] {2, 7.2, 0.1, -2, 5};
    cout << "Has negative #2?: " << hasNegative(arr2, 5) << endl;
    double arr3[] {-1, -5, -153};
    cout << "Has negative #3?: " << hasNegative(arr3, 3) << endl;
    
    return 0;
}
/*
5. Understanding:
◦ What two ways (syntax) can an array be passed to a function? i.e., if you want to pass
an array to a function, which are the two ways you can write the function prototype?
(Think about pointers)
    - pass as in array syntax or pass as in pointer sintax (*pData or data[])
    
*/