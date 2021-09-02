// Filename: Day.h
// Description: header file for Day class
// Author: Wills Stern

#ifndef Day_H
#define Day_H
#include <string>

using namespace std;




class Day {
	
private:
	string day;

public:
	// default constructor
	Day();

	// constructor with string d
	Day(string d);

	// destructor
	~Day() {}

	// string array with all the days in the week
	static string weekDays[7];


	// returns the day
	string getDay() {
		return day;
	}

	// allows programmer to set the day
	void setDay(string d);

	// returns the next day
	string nextDay();

	// returns the previous day
	string prevDay();

	// adds a numDays to day
	void addDay(int numDays);
};

#endif
