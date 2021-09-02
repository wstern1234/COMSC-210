// Filename: Day.cpp
// Description: implementation file for Day class
// Author: Wills Stern

#include "Day.h"

using namespace std;




// default constructor
Day::Day() {
	day = "Monday";
}


// constructor with string d
Day::Day(string d) {
	day = d;
}


// string array with all the days in the week
string Day::weekDays[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};


// allows programmer to set the day
void Day::setDay(string d) {
	day = d;
}

// returns the next day
string Day::nextDay() {

	int i;

	// loops through, finds day
	for (i = 0; i < 7; i++)
		if (weekDays[i] == day)
			break;

	// returns i + 1 in weekDays unless i > 6, for which it returns 0 in weekDays
	return( weekDays[(i < 6) ? (i + 1) : 0] );

}


// returns the previous day
string Day::prevDay() {

	int i;

	// loops through, finds day
	for (i = 0; i < 7; i++)
		if (weekDays[i] == day)
			break;

	// returns i - 1 in weekDays unless i < 0, for which it returns 6 in weekDays
	return( weekDays[(i > 0) ? (i - 1) : 6] );

}

// adds a numDays to day
void Day::addDay(int numDays) {

	int i;

	// loops through, finds day
	for (i = 0; i < 7; i++)
		if (weekDays[i] == day)
			break;

	// adds number of days forward to i, then checks and handles for illegitimate values
	i += numDays;
	if (i - 7 > 0)
		while (i - 7 > 0)
			i -= 7;

	// returns i in weekDays unless i > 7, for which it returns 0 in weekDays
	day = ( weekDays[(i < 7) ? i : 0] );

}