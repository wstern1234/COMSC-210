#include <iostream>
#include <string>
#include <iostream>
#include "HashTable.h"

using namespace std;




int main() {

    ifstream fin; // File input
    int sid;
    struct RecType item;
    StudentHT studentHTobj(113); // Creating hash table with size
    struct RecType studentRec;

    // Starting statistics
    studentHTobj.startStatistics();

    fin.open("Add.txt");
    if (!fin)
    {
        cerr << "Not able to open Add.txt file" << endl;
        return 1;
    }

    while (fin >> sid)
    { // Reading student id from file.
        // Populate the structure with data
        item.id = sid;
        // Insert the item in hash table
        studentHTobj.insert(item);
    }
    fin.close(); // close the Add.txt file

    fin.open("Search.txt"); // Open Search file
    if (!fin) {
        cerr << "Not able to Search.txt file" << endl;
        return 1;
    }

    cout << "========================= Searching =========================" << endl;

    while (fin >> sid) { // Reading student id from file.
      // Create RecType Obj
      ///struct RecType item;

      // Populate the structure with data
        item.id = sid;

        // Search the item in hash table
        studentRec = studentHTobj.search(item);

        if (studentRec.id == -1) {
            cout << "Record not found for Student ID: " << sid << endl;
        }
        else {
            cout << "The Student Record found is: " << endl;
            cout << "Student ID: " << studentRec.id << endl;
        }
    }
    fin.close(); //Closing Search.txt file

    //End statistics to calculate Avg Of Searches.
    studentHTobj.endStatistics();

    //Printing statistics;
    studentHTobj.displayStatistics();

    return 0;
}