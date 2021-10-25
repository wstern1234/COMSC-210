#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;



int a1[10000], a2[20000], a3[30000], a4[40000], a5[50000];

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
double heaptime(int array[], int size);
void printArray(int arr[], int n);
double bubble(int array[], int size);
int partition(int numbers[], int i, int k);
void quicksort(int numbers[], int i, int k);
double quicktime(int array[], int size);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
double mergetime(int array[], int size);


int main() {

    // random number generator for arrays
    srand(time(0));
    for (int i = 0; i < 10000; i++)
        a1[i] = rand();
    for (int i = 0; i < 20000; i++)
        a2[i] = rand();
    for (int i = 0; i < 30000; i++)
        a3[i] = rand();
    for (int i = 0; i < 40000; i++)
        a4[i] = rand();
    for (int i = 0; i < 50000; i++)
        a5[i] = rand();


    cout << "All measurements are in seconds.\n";
    cout << left << setw(15) << "Data Size" << setw(15) << "Bubble" << setw(15) << "Heap" << setw(15) << "Quick Sort" << setw(15) << "Merge Sort" << endl;

    cout << setw(15) << 10000;
    cout << setw(15) << bubble(a1, 10000);
    int n = sizeof(a1) / sizeof(a1[0]);
    cout << setw(15) << heaptime(a1, 10000);
    cout << setw(15) << quicktime(a1, 10000);
    cout << setw(15) << mergetime(a1, 10000) << endl;


    cout << setw(15) << 20000;
    cout << setw(15) << bubble(a2, 20000);
    n = sizeof(a2) / sizeof(a2[0]);
    cout << setw(15) << heaptime(a2, 20000);
    cout << setw(15) << quicktime(a2, 20000);
    cout << setw(15) << mergetime(a2, 20000) << endl;


    cout << setw(15) << 30000;
    cout << setw(15) << bubble(a3, 30000);
    n = sizeof(a3) / sizeof(a1[0]);
    cout << setw(15) << heaptime(a3, 30000);
    cout << setw(15) << quicktime(a3, 30000);
    cout << setw(15) << mergetime(a3, 30000) << endl;


    cout << setw(15) << 40000;
    cout << setw(15) << bubble(a4, 40000);
    n = sizeof(a4) / sizeof(a1[0]);
    cout << setw(15) << heaptime(a4, 40000);
    cout << setw(15) << quicktime(a4, 40000);
    cout << setw(15) << mergetime(a4, 40000) << endl;


    cout << setw(15) << 50000;
    cout << setw(15) << bubble(a5, 50000);
    n = sizeof(a5) / sizeof(a1[0]);
    cout << setw(15) << heaptime(a5, 50000);
    cout << setw(15) << quicktime(a5, 50000);
    cout << setw(15) << mergetime(a5, 50000) << endl;

}




// bubble sorts entire array
double bubble(int array[], int size) {

    // creates dynamic array
    int* arr = new int[size];
    
    for (int i = 0; i < size; i++)
        arr[i] = array[i];

    clock_t start, finish;

    // starts clock
    start = (double) clock();

    int pass = 1, temp;

    bool swap = true;

    // sorts in-place
    while (pass < size && swap == true) {
        swap = false;
        
        for (int i = 0; i < size - 1; i++)
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
            }

        pass++;

    }

    // ends clock
    finish = (double) clock();

    // finds total time, returns seconds
    clock_t totalTime = (finish - start);
    return (double)(totalTime / 1000.0);

    delete[] arr;

}




// partitions array for quicksort
int partition(int numbers[], int i, int k) {

    int temp = 0;
    bool done = false;

    // calculates midpoints and finds pivot value
    int midpoint = i + (k - i) / 2;
    int pivot = numbers[midpoint];


    // until done, keeps partitioning array
    while (!done) {

        while (numbers[i] < pivot)
            ++i;

        while (pivot < numbers[k]) {
            --k;
        }

        if (i >= k)
            done = true;
        else {

            temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            ++i;
            --k;

        }

    }

    return k;
}




// utilizes partitioning to sort array in recursive manner
void quicksort(int numbers[], int i, int k) {

    int j = 0;

    // base case
    if (i >= k)
        return;

    j = partition(numbers, i, k);

    quicksort(numbers, i, j);
    quicksort(numbers, j + 1, k);

    return;

}




// calculates time it takes for quicksort to run
double quicktime(int array[], int size) {

    // dynamic array to copy old arr
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = array[i];

    clock_t start, finish;

    // starts time
    start = (double)clock();
    quicksort(arr, 0, size - 1);

    //finishes time
    finish = (double)clock();

    // calculates and returns time in seconds
    clock_t totalTime = (finish - start);
    return (double)(totalTime / 1000.0);

    delete[] arr;

}




// uses merge sort to sort array
void merge(int arr[], int l, int m, int r) {

    int i = 0, j = 0, k = 0;
    int n1 = m - l + i;
    int n2 = r - m;


    int* left = new int[n1];
    int* right = new int[n2];

    // uses left and right arrays to sort array
    for (i = 0; i < n1; i++)
        left[i] = arr[1 + i];
    for (i = 0; i < n1; i++)
        right[i] = arr[m + i + j];

    while (i < n1 && j < n2) {

        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }

        k++;
    }
    

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;

}



// utilizes merge recursively
void mergeSort(int arr[], int l, int r) {

    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);

    }

}



// finds time it takes to merge sort
double mergetime(int array[], int size) {

    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = array[i];
    clock_t start, finish;

    // starts time
    start = (double)clock();
    mergeSort(arr, 0, size - 1);
    // finishes time
    finish = (double)clock();

    clock_t totalTime = (finish - start);
    return (double)(totalTime / 1000.0);

    delete[] arr;

}




// To heapify a subtree rooted with node i which is
// an index in arr[] n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}




double heaptime(int array[], int size) {

    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = array[i];
    clock_t start, finish;
    start = (double)clock();
    heapSort(arr, size - 1);
    finish = (double)clock();

    clock_t totalTime = (finish - start);
    return (double)(totalTime / 1000.0);

    delete[] arr;

}