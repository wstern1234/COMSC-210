// Filename: IntList.h
// Description: header file for IntList class
// Author: Wills Stern

#ifndef INTLIST_H
#define INTLIST_H

struct ListNode
{
    int value;
    struct ListNode* next;
};


class IntList
{
private:
    ListNode* head;   // List head pointer
    // Destroy function
    void destroy();
public:
    // Constructor
    IntList()
    {
        head = nullptr;
    }
    // List operations
    void insertNode(int);
    void deleteNode(int);
    void print();
    void reverse();
    void removeByPos(int);
    // Destructor
    ~IntList();
};

#endif //INTLIST_H
