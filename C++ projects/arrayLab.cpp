
#include <iostream>
using namespace std;

void displayArray(int array[],int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }
}

void populateSequence(int arr[], int size, int start, int gap)
{
    arr[0]=start;
    int lastnum = start;
    for(int i = 1; i <= size; i++)
    {
        int nextnum = lastnum + gap;
        arr[i]= nextnum;
        lastnum = nextnum;
    }
}
int minValue(int arr[],int size)
{
    int smallest = arr[0];
    for(int i = 0; i < size; i++)
    {   
        if(arr[i]<smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}
int main() 
{   
    // Test displayArray():
    int arr0[] = {42, 0, 1, 101, 58};
    displayArray(arr0, 5);
    cout << endl;
    
    // Test 1 populateSequence: Expected values 7, 9, 11, and 13
    int arr1[4];
    populateSequence(arr1, 4, 7, 2);
    displayArray(arr1, 4);
    cout << endl;
    
    // Test 2 populateSequence: Expected values 2, -1, and -4
    int arr2[3];
    populateSequence(arr2, 3, 2, -3);
    displayArray(arr2, 3);
    cout << endl;

    // Test for minValue
    int arr3[] {17, 3, 12, 11, 4};
    int val1 = minValue(arr3, 5);
    cout << "Min1: " << val1 << "\n";
    cout << endl;

    // should print the value 3
    int arr4[] {1, 0, 7, 23, 2, -1};
    cout << "Min2: " << minValue(arr4, 6) << "\n";
    cout << endl;

    // should print the value -1

    return 0;

}
/*
3. Understanding:
◦ Most functions use a return value to pass back information. However,
populateSequence() has a void return type, yet it is able to give the calling code
(in this case main()) some values in the array. Explain how this happens. Why can
this function use the void return type?
- Because arrays are pointers, we are not passing the array to the function, we are passing a pointer to its first element

2. Understanding:
◦ For the minValue() function, why start the “smallest” variable at arr[0] instead
of the number 0?
    - Because then if the smallest is less than 0, we have a bug.
◦ What happens in your program when there are multiple values which have the same
minimum value? Does this cause a problem? Why or why not?
    - Then it will still return that minimum value. Not really a problem since we want the minimum value and we still get it.
◦ Explain why the minValue() function has a return type instead of using the same
method to pass back information as populateSequence().
    - Because we want a single int value for this
◦ What is the output to the screen of the following code:
int arr[] = {10, 20, 0};
minValue(arr, 3); // Think carefully...
    - Nothing to the screen, it returned the smallest value, I dont see any display command
▪ Explain what changes are needed to display the answer it computes to the screen.
    - use cout after
▪ Why is it better to have the function return a value, rather than directly print the
value to the screen?
    - Classic. The analogy with voting ballot, saying the vote out loud vs sending in the vote.

*/

