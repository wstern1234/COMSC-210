#include "StackAsLList.h"
using namespace std;
int main()
{
	StackAsLList* theStack;
	char testString[50];
	int i;
	char ch;
	cout << "\tSimple Stack Demonstration\n\n\n";
	cout << "\t(Stack implemented as a linked structure - Stack data type is character.)\n\n";
	cout << "\tCreating a stack...\n\n";
	theStack = new StackAsLList(); // Instantiate a stack object
	cout << "\tStack created...\n\n";
	// Test pushing and popping first/last item on a stack
	cout << "\tTesting push and pop of single item.\n\n";
	theStack->Push('A');
	cout << "\tPopped: " << theStack->Pop() << "\n\n";
	cout << "\t...done\n\n";
	// Test stack by reversing the order of letters in a string
	cout << "\tEnter a string to be reversed ::: ";
	// Use get() so we can input spaces
	cin.getline(testString, 50); // Assume user is smart enought to not exceed the limit
	// Push all letters on the stack
	i = 0;
	while (testString[i] != '\0')
	{
		theStack->Push(testString[i]);
		i++;
	}
	/// Pop letters and print in reverse
	cout << "\tYour string printed in reverse is...\n\n\t";
	while ((ch = theStack->Pop()) != '\0') // Pop returns null terminator when stack is empty
		cout << ch;
	cout << "\n\n\t...done.\n";
	return 0;
}