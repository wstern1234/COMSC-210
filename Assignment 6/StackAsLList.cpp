#include "StackAsLList.h"




// constructor
StackAsLList::StackAsLList() {

	// stack initiated to Null
	top = NULL;

}


// destructor
StackAsLList::~StackAsLList() {

	ClearStack();

}


// clears stack of nodes
void StackAsLList::ClearStack() {

	struct StackNode* temp;

	// if stack isn't empty, enters it to delete nodes
	if ( !isEmpty() ) {
		temp = top;

		// loops through stack and deletes nodes until top is NULL
		while (top != NULL) {
			temp = top;
			top = top->next;
			delete temp;
		}
	}

	top = NULL;

}


// adds a node to the stack
bool StackAsLList::Push(char ch) {

	StackNode* newNode = new StackNode();

	if (newNode == NULL)
		return false;


	//gives newNode the ch parameter value and makes next equal NULL
	newNode->ch = ch;
	newNode->next = NULL;

	// checks if its empty, else assigns newNode's next to top and newNode to top
	if (isEmpty())
		top = newNode;
	else {
		newNode->next = top;
		top = newNode;
	}

	return true;

}

// removes node from stack
char StackAsLList::Pop() {

	char ch;

	struct StackNode* temp;

	// if empty, returns a null character
	if (isEmpty())
		return '\0';

	// assigns top to temp, top to its next value, and temp's ch value to ch
	temp = top;
	top = top->next;
	ch = temp->ch;

	// deallocates memory from temp, makes it NULL
	delete temp;
	temp = NULL;


	return ch;

}


// tells if stack is empty
bool StackAsLList::isEmpty() {

	return (top == NULL);

}


// tells if stack is full
bool StackAsLList::isFull() {

	return false;

}