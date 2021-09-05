// Filename: Date.h
// Description: header file for Date class
// Author: Wills Stern

#ifndef DATE_H
#define DATE_H


const int SIZE = 13;
const int monthArr[SIZE] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {

private:
	int month, day, year;

public:
	// constructor
	Date(int = 1, int = 1, int = 1970);

	// setter functions
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	// getter functions
	int getMonth() const;
	int getDay() const;
	int getYear() const;

	// returns true if year is a leap year
	bool isLeapYear();
	
	// returns number of days passed since beginning of year
	int numberOfDaysPassed();

	// returns number of days left in the year
	int numberOfDaysLeft();

	// increments the current date by numDays days
	void incrementDate(int);

	// uses switch case to find number of days in month
	int getDaysInMonth();
};



#endif // DATE_H
