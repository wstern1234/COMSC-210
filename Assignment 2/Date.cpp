#include <iostream>
#include "Date.h"

using namespace std;




Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}


void Date::setMonth(int m) {
	month = m;
}

void Date::setDay(int d) {
	day = d;
}

void Date::setYear(int y) {
	year = y;
}


int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

int Date::getYear() const {
	return year;
}


bool Date::isLeapYear() {

	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
			
		return true;

	} else {

		return false;

	}

}


int Date::numberOfDaysPassed() {

	int sumDays = 0;

	for (int i = 1; i < month; i++)
		sumDays += monthArr[i];

	sumDays += ( (isLeapYear() && month > 2) ? (day + 1) : (day) );

	return sumDays;

}

int Date::numberOfDaysLeft() {

	return ( (isLeapYear()) ? (366 - numberOfDaysPassed()) : (365 - numberOfDaysPassed()) );

}


void Date::incrementDate(int numDays) {

	int daysLeftInMonth;

	daysLeftInMonth = monthArr[month] - day;

	if (daysLeftInMonth >= numDays)
		day += numDays;
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