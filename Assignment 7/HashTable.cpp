#include "HashTable.h"

StudentHT::StudentHT(int htSize) {
    hashTableSize = htSize;
    // Create Array of NodeType of pointers
    hashTablePtr = new NodeType * [hashTableSize];

    //Initialize pointer with NULL values
    for (int i = 0; i < hashTableSize; i++) {
        hashTablePtr[i] = NULL;
    }
}

void StudentHT::insert(RecType item) {

    //calculate hash
    int hashValue = hashFunction(item.id);

    // store the item in hash table
    struct NodeType* newItem = new struct NodeType;

    // Copy item to NodeType item
    newItem->id = item.id;
    newItem->fname = item.fname;
    newItem->lname = item.lname;
    newItem->nextNode = NULL;

    //If it is first entry in the hash table position
    if (hashTablePtr[hashValue] == NULL) {
        hashTablePtr[hashValue] = newItem;
    }
    else { // Insert node in the linked list
        struct NodeType* temp = hashTablePtr[hashValue];

        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = newItem;
    }
}

RecType StudentHT::search(RecType item) {
    numberOfIDSearched++; // Increment search IDs

    //calculate hash
    int hashValue = hashFunction(item.id);

    // search the item
    RecType* itemSearch = new RecType;

    if (hashTablePtr[hashValue] != NULL) {
        struct NodeType* temp = hashTablePtr[hashValue];
        temp = hashTablePtr[hashValue];

        while (temp != NULL) { // item found
            numberOfNodesSearches++; //Increment number of node searches

            if (temp->id == item.id) {
                itemSearch->id = temp->id;
                itemSearch->fname = temp->fname;
                itemSearch->lname = temp->lname;
                return *itemSearch;
            }
            temp = temp->nextNode;
        }
    }

    // return item with id -1
    itemSearch->id = -1;

    return *itemSearch;
}

void StudentHT::displayStatistics() {
    cout << "=============================================================" << endl;
    cout << "Total number if IDs searched : " << numberOfIDSearched << endl;
    cout << "Total number of nodes searched : " << numberOfNodesSearches << endl;
    cout << "Average number of nodes search per ID searched : " << avgNumberOfSearches << endl;
    cout << "=============================================================" << endl;
}