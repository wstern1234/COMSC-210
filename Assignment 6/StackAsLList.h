///********************************************************
/// File: StackAsLList.h
/// Purpose: Header file for a stack implemented
/// as a linked structure.
///********************************************************
#include <iostream>
using namespace std;
/// Define a structure to be used as the stack item
struct StackNode
{
	char ch;
	StackNode* next;
};
class StackAsLList
{
private:
	StackNode* top;
	/// Pointer to top of the stack
public:
	StackAsLList();
	/// Class constructor
	~StackAsLList(); /// Class destructor
	void ClearStack();
	/// Remove all items from the stack
	bool Push(char ch);
	/// Push an item onto the stack
	char Pop();
	/// Pop an item from the stack
	bool isEmpty();
	/// Return true if stack is empty
	bool isFull();
	/// Return true if stack is full
};

