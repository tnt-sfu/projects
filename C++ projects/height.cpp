// Assignment 1 Question 1: Height Program

#include <iostream>
using namespace std;
int main()
{
    // Ask user about height inches
    cout << "Enter your height in inches:";
    double height_in_inches = 0;
    cin >> height_in_inches;

    // Convert height from inches to feet
    int feet_factor = (int)height_in_inches / 12;
    int inch_factor = (int)height_in_inches % 12;
    cout << "Write either: \"I\'m " << feet_factor << "\'" << inch_factor << "\"!\" \\ \"I\'m " << height_in_inches << "\" tall!\"" << endl;

    // Convert height to metric
    const double inches_per_meter = 39.3701;
    cout << "(Height in metric: " << height_in_inches / inches_per_meter << "m)" << endl;

    return 0;
}