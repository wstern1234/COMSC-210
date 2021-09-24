// Filename: IntList.cpp
// Description: implementation file for the class IntList
// Author: Wills Stern
#include <iostream>
#include "IntList.h"

using namespace std;




// properly prints linked list
void IntList::print() {

	// initiates nodePtr and sets it to head
	ListNode* nodePtr = nullptr;
	nodePtr = head;

	// loops through linked list, outputs nodes
	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}

	cout << endl << endl;

}


// inserts a node into the linked list
void IntList::insertNode(int num) {

	// initiates node to be inserted and 2 helper nodes
	ListNode* newNode, * nodePtr, * previousNode = nullptr;

	// declares newNode and sets it to given num value
	newNode = new ListNode;
	newNode->value = num;

	// if no head, inserts newNode as first node, else adds newNode to linked list
	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	}
	else {

		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < num) {

			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}

		if (previousNode == nullptr) {

			head = newNode;
			newNode->next = nodePtr;

		}
		else {

			previousNode->next = newNode;
			newNode->next = nodePtr;

		}

	}

}


// deletes a node from the linked list
void IntList::deleteNode(int num) {

	// initiates 2 helper nodes
	ListNode* nodePtr, * previousNode = nullptr;

	// if no head, nothing to delete
	if (!head)
		return;

	// if value found, deletes it, else it loops through again, double checking, and deletes nodePtr
	if (head->value == num) {

		nodePtr = head->next;
		delete head;
		head = nodePtr;

	}
	else {

		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != num) {

			previousNode = nodePtr;
			nodePtr = nodePtr->next;

		}

		if (nodePtr) {

			previousNode->next = nodePtr->next;
			delete nodePtr;

		}

	}

}

// reverses linked list order
void IntList::reverse() {

	// initiates 4 nodes bc it has to reverse the entire list, which means it handles many nodes at a time
	ListNode* nodePtr, * tempPtr, * newNode, * newHead = nullptr;

	nodePtr = head;

	// checks if linked list is empty, creates new head, and loops through list, reversing it
	while (nodePtr) {

		newNode = new ListNode;
		newNode->value = nodePtr->value;
		newNode->next = nullptr;

		if (newHead != nullptr) {

			tempPtr = newHead;
			newHead = newNode;
			newNode->next = tempPtr;

		}
		else {

			newHead = newNode;

		}

		nodePtr = nodePtr->next;

	}

	destroy();


	head = newHead;

}


// destroys linked list
void IntList::destroy() {

	// intiates nodePtr and helper node
	ListNode* nodePtr, * nextNode = nullptr;

	nodePtr = head;

	// loops through linked list, deleting each node
	while (nodePtr != nullptr) {

		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;

	}

	head = nullptr;

}


// deletes node based off of pos in linked list
void IntList::removeByPos(int pos) {

	// creates new head node
	ListNode* p = head;

	// checks if linked list is empty
	if (p == nullptr)
		return;

	// loops through linked list until node at position pos
	while (pos > 0 && p) {

		p = p->next;
		pos--;

	}

	// if p = head, then head is deleted, else checks if pos is too big and deletes node at p
	if (p = head) {

		head = head->next;
		delete p;
		return;

	}
	else {

		// pos too big, so return
		if (p == nullptr)
			return;

		ListNode* trailer = head;

		while (trailer->next != p)
			trailer = trailer->next;

		trailer->next = p->next;
		delete p;

	}

}


// destructor
IntList::~IntList() {

	destroy();

}