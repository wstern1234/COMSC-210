// Filename: Date.cpp
// Description: implementation file for the class Date
// Author: Wills Stern

#include <iostream>
#include "Date.h"

using namespace std;




// constructor
Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}


// getter functions
void Date::setMonth(int m) {
	month = m;
}
void Date::setDay(int d) {
	day = d;
}
void Date::setYear(int y) {
	year = y;
}


// getter functions
int Date::getMonth() const {
	return month;
}
int Date::getDay() const {
	return day;
}
int Date::getYear() const {
	return year;
}


// returns true if year is a leap year
bool Date::isLeapYear() {

	// if year is divisible by 400 OR (year divisible by 4 AND NOT divisible by 100) then leap year
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
			
		return true;

	} else {

		return false;

	}

}


// returns number of days passed since beginning of year
int Date::numberOfDaysPassed() {

	int sumDays = 0;

	// goes through monthArr containing number of days each month
	for (int i = 1; i < month; i++)
		sumDays += monthArr[i];

	// adds a day if the year is a leap year
	sumDays += ( (isLeapYear() && month > 2) ? (day + 1) : (day) );

	return sumDays;

}

// returns number of days left in the year
int Date::numberOfDaysLeft() {

	// checks if year is leap year, then makes appropriate calculation
	return ( (isLeapYear()) ? (366 - numberOfDaysPassed()) : (365 - numberOfDaysPassed()) );

}


// increments the current date by numDays days
void Date::incrementDate(int numDays) {

	int daysLeftInMonth;

	daysLeftInMonth = monthArr[month] - day;

	// checks if it's safe to add numDays to days
	if (daysLeftInMonth >= numDays)
		day += numDays;
	// goes to next month because numDays + days > monthArr[month] and sets correct day
	else {
		day = 1;
		month++;
		numDays -= (daysLeftInMonth + 1);

		while (numDays > 0)
			if (numDays >= monthArr[month]) {

				numDays -= monthArr[month];

				if ((month == 2) && isLeapYear())
					numDays--;

				month++;

				if (month > 12) {
					month = 1;
					year++;
				}

			} else {
				
				day += numDays;
				numDays = 0;

			}

	}

}


// uses switch case to find number of days in month
int Date::getDaysInMonth() {

	switch (month) {

	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;

	case 2:
		// uses isLeapYear() to assign February's number of days
		return( isLeapYear() ? 29 : 28 );
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;

	}

}