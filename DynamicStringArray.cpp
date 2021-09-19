// Filename: DynamicStringArray.cpp
// Description: implementation file for the class DynamicStringArray
// Author: Wills Stern

#include "DynamicStringArray.h"

using namespace std;




// default constructor
DynamicStringArray::DynamicStringArray() {

	// no inputs, so dynamicArray and size are set to nullptr and size, respectively
	dynamicArray = nullptr;
	size = 0;
}

// makes a copy of the current dynamic array to a new DynamicStringArray instance
DynamicStringArray::DynamicStringArray(const DynamicStringArray& oldObj) {

	// starts copying process by assigning size of new dynamic array with size of old dynamic array
	size = oldObj.size;
	
	// if the old dynamic array was empty, so is the new one, else it just copies over the old data
	if (size == 0)
		dynamicArray = NULL;
	else {
		dynamicArray = new string[size];
		for (int i = 0; i < size; i++)
			dynamicArray[i] = oldObj.dynamicArray[i];
	}

}


// returns the string at index of the dynamic array
string DynamicStringArray::getEntry(int index) {

	// checks if index is valid, else it returns just fine
	if ((index < 0) || (index >= size))
		return NULL;
	else
		return dynamicArray[index];

}

// returns size of dynamic array
int DynamicStringArray::getSize() {
	return size;
}

// creates new dynamic array 1 larger than current dynamic array using newEntry
void DynamicStringArray::addEntry(string newEntry) {

	// creates a dynamic array one larger than previous
	string* newDynamicArray = new string[size + 1];

	// assigns each value of old dynamic array to new dynamic array
	for (int i = 0; i < size; i++)
		newDynamicArray[i] = dynamicArray[i];

	// both assigns new string to end of dynamic array and increases size
	newDynamicArray[size++] = newEntry;

	// frees up memory taken by old dynamic array
	delete[] dynamicArray;

	// assigns initial dynamic array with newDynamicArray
	dynamicArray = newDynamicArray;

}


// creates new dynamic array 1 smaller than current dynamic array using element to locate string to delete
bool DynamicStringArray::deleteEntry(string entry) {

	string* newDynamicArray = NULL;

	int pos = -1;

	// finds position of string to be deleted
	for (int i = 0; (i < size) && (pos == -1); i++)
		if (dynamicArray[i] == entry)
			pos = i;

	// checks if string is found
	if (pos == -1)
		return false;

	// will create new dynamic array one less than old dynamic array if size > 1
	if (size > 1)
		newDynamicArray = new string[size - 1];

	// assigns values of old dynamic array to new one
	for (int i = 0, j = 0; i < size; i++)
		if (i != pos)
			newDynamicArray[j++] = dynamicArray[i];

	// decreases size, frees up memory, and assigns initial array with new one
	size--;
	delete[] dynamicArray;
	dynamicArray = newDynamicArray;
	return true;

}

// overloads = operator for applying it to DynamicStringArray instances
DynamicStringArray& DynamicStringArray::operator = (const DynamicStringArray& rightSide) noexcept {

	// frees up memory of dynamic array if it isn't empty
	if (dynamicArray != NULL)
		delete[] dynamicArray;
	
	// assigns dynamic array to null and 0 if rightSide's size = 0, else assigns rightSide dynamic array to new dynamic array
	if (rightSide.size == 0) {

		size = 0;
		dynamicArray = NULL;

	} else {

		size = rightSide.size;
		dynamicArray = new string[size];

		for (int i = 0; i < size; i++) {

			dynamicArray[i] = rightSide.dynamicArray[i];

		}

	}

	return *this;
}


// Gives back memory that was given to dynamic array
DynamicStringArray::~DynamicStringArray() {

	if (dynamicArray != NULL)
		delete[] dynamicArray;

}