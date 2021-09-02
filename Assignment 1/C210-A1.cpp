// Filename: C210-A1.cpp
// Description: driver file for Day class
// Author: Wills Stern

#include <iostream>
#include <string>
#include "Day.h"

using namespace std;




int main() {
    Day myDay("Monday");
    Day yourDay("Sunday");


    cout << "TESTING PREVIOUS DAY AND NEXT DAY" << endl << endl;

    cout << "My day is " << myDay.getDay() << endl;

    cout << "The yesterday of my day is " << myDay.prevDay() << endl;

    cout << "The tomorrow of my day is " << myDay.nextDay() << endl;

    cout << endl;

    
    cout << "Your day is " << yourDay.getDay() << endl;

    cout << "The yesterday of your day is " << yourDay.prevDay() << endl;

    cout << "The tomorrow of your day is " << yourDay.nextDay() << endl;

    cout << endl;


    cout << "************************************************************\n";


    cout << endl;
    
    cout << "TESTING ADD DAY " << endl << endl;

    cout << "Adding 4 to my day which is Monday, expected Friday.... ";

    myDay.addDay(4);

    cout << ".... result : My day is " << myDay.getDay() << endl;

    cout << endl;

    
    cout << "TESTING ADD DAY " << endl << endl;

    cout << "Adding 9 to your day which is Sunday, expected Tuesday.... ";

    yourDay.addDay(9);

    cout << ".... result : My day is " << yourDay.getDay() << endl;

    cout << endl;
    
    
    return 0;

}