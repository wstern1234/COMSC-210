//Filename: C210-A2.cpp
//Description: driver file for class Date
//Author: Wills Stern

#include <iostream>
#include "Date.h"
using namespace std;




int main()
{
    Date date1;
    Date date2(4, 16, 2012);
    Date date3(5, 5, 20);

    cout << "Testing object date1 created by the default constructor.............\n";
    cout << "Year : " << date1.getYear() << endl;
    cout << "Month: " << date1.getMonth() << endl;
    cout << "Day  : " << date1.getDay() << endl;
    cout << "Days in the month       " << date1.getDaysInMonth() << endl;
    cout << "Number of days passed   " << date1.numberOfDaysPassed() << endl;
    cout << "Number of days left     " << date1.numberOfDaysLeft() << endl;
    cout << "This year is ";
    if (date1.isLeapYear())
        cout << "a leap year\n";
    else
        cout << "not a leap year\n";
    cout << "Adding 20 days and the date is\n";
    date1.incrementDate(400);
    cout << "\tYear : " << date1.getYear() << endl;
    cout << "\tMonth: " << date1.getMonth() << endl;
    cout << "\tDay  : " << date1.getDay() << endl;
    cout << "******************************************************************\n";
    cout << "\nTesting date2, non-default parameters, testing with date 4/16/2012 \n\n";

    cout << "Year : " << date2.getYear() << endl;
    cout << "Month: " << date2.getMonth() << endl;
    cout << "Day  : " << date2.getDay() << endl;
    cout << "Days in the month      " << date2.getDaysInMonth() << endl;
    cout << "Number of days passed  " << date2.numberOfDaysPassed() << endl;
    cout << "Number of days left    " << date2.numberOfDaysLeft() << endl;
    cout << "This year is ";
    if (date2.isLeapYear())
        cout << "a leap year\n";
    else
        cout << "not a leap year\n";
    cout << "Adding 20 days and the date is\n";
    date2.incrementDate(20);
    cout << "\tYear : " << date2.getYear() << endl;
    cout << "\tMonth: " << date2.getMonth() << endl;
    cout << "\tDay  : " << date2.getDay() << endl;

    cout << "******************************************************************\n";
    cout << "\nTesting setters with date3, which is currently 5/5/20\n\n";

    cout << "Year : " << date3.getYear() << endl;
    cout << "Month: " << date3.getMonth() << endl;
    cout << "Day  : " << date3.getDay() << endl;
    cout << "This year is ";
    if (date3.isLeapYear())
        cout << "leap\n";
    else
        cout << "not a leap year\n";
    cout << "Resetting the date to 7/7/2021\n";
    date3.setMonth(7);
    date3.setDay(7);
    date3.setYear(2021);
    cout << "\tYear : " << date2.getYear() << endl;
    cout << "\tMonth: " << date2.getMonth() << endl;
    cout << "\tDay  : " << date2.getDay() << endl;
    cout << "This year is ";
    if (date3.isLeapYear())
        cout << "leap\n";
    else
        cout << "not a leap year\n";

    return 0;
}