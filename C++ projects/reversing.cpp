#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

//1.1 Check Permutation
bool isPermutation(int arr[], int n){
	bool check=true;
	for(int i=0; i<n; i++){
		if(arr[i]>=1 && arr[i]<=n){
			for(int j=n-1; j>i; j--){ // j>i so it do not need to compare again
				if(arr[i]==arr[j]){
					check=false;
					break;
				}
				else{
					check;
				}
			}
		}
		else{
			check=false;
			break;
		}
	}
	return check;
}

// 1.2 Initialize the Permutation
void initializePermutation(int arr[], int n){
	//for(int i=0;i<n;i++){
	//	arr[i]=i+1;
	//}
    if(n==0){
        return; // end the void function
    }
    initializePermutation(arr,n-1);
    arr[n-1]=n;
}

// 1.3.1 Reversals
// Reverse m elements in the array arr, changing the original array.
void reverseArray(int arr[], int m){
    int i = 0;
    int j = m -1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
        i++;
    }
}
//1.3.2 Array Copies
void copyArray(int destination[], int source[], int size){
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}
// 1.3 Permutation Score
int scorePermutation(int arr[], int n){
    int score = 0;
    //create new copy array
    int copy[n];
    copyArray(copy,arr,n);
    if (arr[0]==1 || n ==1)
    {
        return 0;
    }
    while(copy[0] != 1)
    {
        reverseArray(copy,copy[0]);
        score ++;
    }
    return score;
}

// 1.4 Permutation Print
void printPermutationAndScore(int arr[], int n){
    cout << "[n = " << n << "] Score of {";
    for (int i = 0; i < n; i++){
        cout << arr[i];
        if (i<n-1){
            cout << ",";
        }
    } 
    cout << "} = " << scorePermutation(arr,n) << " " << endl;
}

bool nextPermutation(int arr[], int n){
	// Check that arr[] is already a valid permutation.
    // If this assertion is failing, set a breakpoint and debug it! You should 
    // check that arr is a permutation (using the debugger to see it). If its not, 
    // look for where the code corrupts it!
    assert(isPermutation(arr, n));
    
    // Use the built-in C++ permutation algorithm (in <algorithms>)
    // For arguments, we pass it the first element of the array, and one-past the end.
    return std::next_permutation(&arr[0], &arr[n]);
}

//1.5 Generating Permutations
void demoPermutations()
{
    // Create the first permutation
    const int SIZE = 4;
    int perm[SIZE];
    cout << "Showing all permutations of size " << SIZE << endl;
    initializePermutation(perm, SIZE);

    // Create all possible permutations
    int counter = 1;
    bool moreToGo = true;
    while (moreToGo) {
        // Display the permutation
        cout << counter << ": ";
        for (int i = 0; i < SIZE; i++) {
            cout << perm[i] << ", ";
        }
        cout << endl;

        moreToGo = nextPermutation(perm, SIZE);
        counter++;
    }
    cout << endl;
}

//1.6 Finding Optimal Permutations with Brute Force
void findOptimalPermutation(int arr[], int n){
    int maxScore = 0;
    int currentScore = 0;
    int maxPerm[n]; 
    int currentPerm[n];
    initializePermutation(currentPerm, n);
    
    bool moreToGo = true;

    while (moreToGo) {
        currentScore = scorePermutation(currentPerm,n);
        if (currentScore > maxScore)
        {
            maxScore = currentScore;
            copyArray(maxPerm,currentPerm,n);
        }
        moreToGo = nextPermutation(currentPerm, n);
    }
    printPermutationAndScore(maxPerm,n);
    cout<<endl;
}

void printOptimalPermutations(int low, int high){
    for (int i = low; i <= high; i++){
    	int arr[i] = {1};
    	findOptimalPermutation(arr,i);
    }
}


int main(){
	// Simple tests for isPermutation(). Add more for better testing.
	cout << "Some isPermutation() tests (perhaps add more!)" << endl;
	int arr1[] = {4, 2, 3, 1, 5};
	cout << "isPerm 1? " << isPermutation(arr1, 5) << endl;
	int arr2[] = {4, 2, 3, 5, 5};
	cout << "isPerm 2? " << isPermutation(arr2, 5) << endl;
	int arr3[] = {4, 2, 0, 1};
	cout << "isPerm 3? " << isPermutation(arr3, 4) << endl;
	cout << endl;

	// Demo the use of nextPermutation() and other function.
	demoPermutations();

	printOptimalPermutations(1,11);

	return 0;
}