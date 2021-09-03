#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED


const int SIZE = 13;
const int monthArr[SIZE] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {

private:
	int month, day, year;

public:
	Date(int = 1, int = 1, int = 1970);

	void setMonth(int);
	void setDay(int);
	void setYear(int);

	int getMonth() const;
	int getDay() const;
	int getYear() const;

	bool isLeapYear();

	int numberOfDaysPassed();
	int numberOfDaysLeft();

	void incrementDate(int);

	int getDaysInMonth();
};



#endif // !DATE_H_INCLUDED
