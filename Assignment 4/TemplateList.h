// Filename: TemplateList.h
// Description: header file for class TemplateList
// Author: Wills Stern

#ifndef TEMPLATELIST_H
#define TEMPLATELIST_H

#include <iostream>

using namespace std;



// default template type is int
template <typename structType = int>
struct ListNode
{
    structType value;
    struct ListNode* next;
};


// default template type is int
template <typename elemType = int>
class TemplateList
{
private:
    ListNode<elemType>* head;   // List head pointer
    // Destroy function
    void destroy();

public:
    // Constructor
    
	TemplateList() {
		head = nullptr;
	}

    // List operations
    void insertNode(elemType);

    void deleteNode(elemType);

    void print();

    void reverse();

    void removeByPos(int);

    // Destructor
    ~TemplateList();

};




// properly prints linked list
template<typename elemType>
void TemplateList<elemType>::print() {

	// initiates nodePtr and sets it to head
	ListNode<elemType>* nodePtr = nullptr;
	nodePtr = head;

	// loops through linked list, outputs nodes
	while (nodePtr) {
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}

	cout << endl << endl;

}


// inserts a node into the linked list
template<typename elemType>
void TemplateList<elemType>::insertNode(elemType num) {

	// initiates node to be inserted and 2 helper nodes
	ListNode<elemType>* newNode, * nodePtr, * previousNode = nullptr;

	// declares newNode and sets it to given num value
	newNode = new ListNode<elemType>;
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
template<typename elemType>
void TemplateList<elemType>::deleteNode(elemType num) {

	// initiates 2 helper nodes
	ListNode<elemType>* nodePtr, * previousNode = nullptr;

	// if no head, nothing to delete
	if (!head)
		return;

	// if value found, deletes it, else it loops through again, double checking, and deletes nodePtr
	if (head->value == num) {

		nodePtr = head->next;
		delete head;
		head = nodePtr;

	} else {

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
template<typename elemType>
void TemplateList<elemType>::reverse() {

	// initiates 4 nodes bc it has to reverse the entire list, which means it handles many nodes at a time
	ListNode<elemType>* nodePtr, * tempPtr, * newNode, * newHead = nullptr;

	nodePtr = head;

	// checks if linked list is empty, creates new head, and loops through list, reversing it
	while (nodePtr) {

		newNode = new ListNode<elemType>;
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
template<typename elemType>
void TemplateList<elemType>::destroy() {

	// intiates nodePtr and helper node
	ListNode<elemType>* nodePtr, * nextNode = nullptr;

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
template<typename elemType>
void TemplateList<elemType>::removeByPos(int pos) {

	// creates new head node
	ListNode<elemType>* p = head;

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

		ListNode<elemType>* trailer = head;

		while (trailer->next != p)
			trailer = trailer->next;

		trailer->next = p->next;
		delete p;

	}

}


// destructor
template<typename elemType>
TemplateList<elemType>::~TemplateList() {

	destroy();

}


#endif //TEMPLATELIST_H