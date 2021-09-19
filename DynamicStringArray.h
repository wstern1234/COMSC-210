// Filename: DynamicStringArray.h
// Description: header file for DynamicStringArray class
// Author: Wills Stern

#ifndef DYNAMICSTRINGARRAY_H
#define DYNAMICSTRINGARRAY_H

#include <string>

using namespace std;


class DynamicStringArray {

private:

	// creates a pointer for a dynamic array
	string* dynamicArray;

	// size of dynamicArray
	int size;

public:

	// default constructor
	DynamicStringArray();

	// makes a copy of array to a new DynamicStringArray instance
	DynamicStringArray(const DynamicStringArray &oldObj);


	// returns the string at index of dynamic array
	string getEntry(int index);

	// returns size of dynamic array
	int getSize();

	// creates new dynamic array 1 larger than current dynamic array using newEntry
	void addEntry(string newEntry);

	// creates new dynamic array 1 smaller than current dynamic array using element to locate string to delete
	bool deleteEntry(string element);

	// overloads = operator for applying it to DynamicStringArray instances
	DynamicStringArray& operator = (const DynamicStringArray& rightSide) noexcept;

	// Gives back memory that was given to dynamic array
	~DynamicStringArray();



};

#endif //DYNAMICSTRINGARRAY_H