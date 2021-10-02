#include "LListQueue.h"




// constructor
LListQueue::LListQueue() {

	// assigns both head and tail to nullptr
	head = tail = nullptr;

}


// destructor
LListQueue::~LListQueue() {

	ClearQueue();

}


// completely removes all nodes in queue
void LListQueue::ClearQueue() {

	QNode* temp;

	// loops while queue isn't empty, deletes all nodes
	while (head != nullptr) {

		temp = head;
		head = head->next;
		delete temp;

	}

	// assigns both head and tail to nullptr
	head = tail = nullptr;

}


// // adds a node to the queue
bool LListQueue::Enqueue(char ch) {

	QNode* temp;

	if (isFull())
		return false;


	temp = new QNode();

	//gives temp the ch parameter value and makes next equal nullptr
	temp->ch = ch;
	temp->next = nullptr;

	// checks if its empty, else assigns tail's next with temp and tail with temp
	if (head == nullptr)
		head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}

	return true;

}


// removes node from queue
char LListQueue::Dequeue() {

	char ch;
	QNode* temp;

	// checks if empty returns null character
	if (isEmpty())
		return '\0';
	else {

		// else assigns ch with head's ch, temp with head, and head with its next
		ch = head->ch;
		temp = head;
		head = head->next;

		// deallocates temp's memory
		delete temp;

		// its empty, head and tail assigned nullptr
		if (isEmpty())
			head = tail = nullptr;

	}

	return ch;

}


// tells if queue is empty
bool LListQueue::isEmpty() {

	return (head == nullptr);

}

// tells if queue is full
bool LListQueue::isFull() {

	return false;

}