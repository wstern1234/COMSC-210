#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include <fstream>

// standard library
using namespace std;

// Record Type Structure
struct RecType
{
    int id;
    string fname;
    string lname;
};

class StudentHT
{
public:
    struct NodeType
    {
        int id;
        string fname;
        string lname;
        NodeType* nextNode;
    };

    struct NodeType** hashTablePtr;

    int hashTableSize; //Hash table size

    int numberOfNodesSearches;

    int numberOfIDSearched;

    double avgNumberOfSearches;

    StudentHT(int htSize); // initializes the hash table

    int hashFunction(int studentID)
    {
        /// hash Algorithm
        int hashValue = studentID % hashTableSize;
        return hashValue;
    }

    void insert(RecType item); // Insert node into hash table

    RecType search(RecType item); // Search for node in hash table

    void startStatistics() {
        numberOfIDSearched = 0;
        numberOfNodesSearches = 0;
        avgNumberOfSearches = 0;
    }

    void endStatistics() {
        // calculate avg searches
        avgNumberOfSearches = (double)numberOfNodesSearches / numberOfIDSearched;
    }

    void displayStatistics();
};

#endif //HASHTABLE_H