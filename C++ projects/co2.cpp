//Question 1 Assignment 3: CO2 table
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main ()
{
    //Print out program header
    cout << "BOGUS CO2 to Temperature Change Table Generator" << endl;
    cout << "-----------------------------------------------" << endl;
    
    //Declare global constants
    const int COLUMN_WIDTH = 15;
    const int INITIAL_YEAR = 2022;
    const double INITIAL_CO2 = 412.5;
    const double TEMP_CHANGE_FACTOR = 0.0091;
    const double INITIAL_TEMP = 22;
    
    //Ask for user input
    cout << "Enter the yearly change in CO2 [ppm]: ";
    double YEARLY_CHANGE_IN_CO2 = 0;
    cin >> YEARLY_CHANGE_IN_CO2;
    cout << endl;
    cout << "Enter the number of years to print: ";
    int NUMBER_OF_YEARS;
    cin >> NUMBER_OF_YEARS;
    cout << endl;
    
    //Print out table header
    cout << "Year"<<setw(COLUMN_WIDTH)<<"CO2ppm"<<setw(COLUMN_WIDTH + 8)<<"Temp Changed C"<<setw(COLUMN_WIDTH + 6)<<"Van Summer C"<<setw(COLUMN_WIDTH + 1)<<"Comment"<<endl;
    
    //Print out table content
    for (int j = 0; j <= NUMBER_OF_YEARS; j++)
    {
        cout << INITIAL_YEAR + j << setw(COLUMN_WIDTH-3) << INITIAL_CO2 + YEARLY_CHANGE_IN_CO2*j <<"ppm" << setw(COLUMN_WIDTH + 6) << YEARLY_CHANGE_IN_CO2*TEMP_CHANGE_FACTOR*j <<"'C" <<setw(COLUMN_WIDTH +4) << showpos << INITIAL_TEMP + YEARLY_CHANGE_IN_CO2*j*TEMP_CHANGE_FACTOR << noshowpos <<"'C";
        double temperature = INITIAL_TEMP + YEARLY_CHANGE_IN_CO2*j*TEMP_CHANGE_FACTOR;
        
        //comment on Vancouver temperature
        if(temperature < 24.00 && temperature >= 18)
        {
            cout << setw(COLUMN_WIDTH + 1) << "cool";
        }
        else if(temperature >= 24)
        {
            cout << setw(COLUMN_WIDTH + 1) << "warm";
        }
        else if(temperature < 18)
        {
            cout << setw(COLUMN_WIDTH +1) << "cold";
        }
        cout << endl;
    }
    return 0;
}