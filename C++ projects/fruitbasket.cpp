//Assignment 1 Question 2: fruit basket program

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Print out output header
    cout << "**************************" << endl;
    cout << "Local Fruit Box Calculator" << endl;
    cout << "**************************" << endl;
    cout << endl;

    // ask user for number of appless donated
    int apples;
    cout << "Enter the number of apples donated: ";
    cin >> apples;

    // ask user for number of oranges donated
    int oranges;
    cout << "Enter the number of oranges donated: ";
    cin >> oranges;

    // ask user for the number of fruity pieces per basket
    int fruits_Per_Basket;
    cout << "Enter the number of fruity pieces per basket: ";
    cin >> fruits_Per_Basket;
    cout << endl;

    // display inputs
    cout << "Input Values: " << endl;
    cout << "------------" << endl;
    cout << "# Apples Donated:          " << setw(4) << apples << endl;
    cout << "# Oranges Donated:         " << setw(4) << oranges << endl;
    cout << "# Fruit pieces per Basket: " << setw(4) << fruits_Per_Basket << endl;

    // calculate number of baskets can be created
    int total_Baskets = (apples + oranges) / fruits_Per_Basket;

    // calculate min apples per basket
    int min_Apple = apples / total_Baskets;

    // calculate min oranges per basket
    int min_Oranges = oranges / total_Baskets;

    // calculate left Over Fruits
    int left_Over_Fruits = (apples + oranges) % fruits_Per_Basket;

    // calculate pieces need to complete one more basket
    int required_Pieces = fruits_Per_Basket - left_Over_Fruits;

    // Show Basket Results
    cout << endl;
    cout << "Basket Creation Numbers: " << endl;
    cout << "-----------------------" << endl;
    cout << "# Baskets to create:       " << setw(4) << total_Baskets << endl;
    cout << "Min # apples per basket:   " << setw(4) << min_Apple << endl;
    cout << "Min # oranges per basket:  " << setw(4) << min_Oranges << endl;
    const int number_of_ribbons_per_basket = 3;
    cout << "# Ribbons to tie baskets:  " << setw(4) << total_Baskets * number_of_ribbons_per_basket << endl;
    cout << "# Pieces needed to complete one more basket:" << setw(4) << required_Pieces << endl;

    return 0;
}