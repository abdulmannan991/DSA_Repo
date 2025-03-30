#include <iostream>
using namespace std;

// Take first element as pivot
// Swap function
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using first element as pivot
int PartitionFirst(int array[], int low , int high){
    int pivot = array[low]; // First element as pivot
    int i = high + 1; // Start from the right side

    for(int j = high; j > low; j--) {
        if(array[j] > pivot) { // Move larger elements to the right
            i--;  
            swap(&array[i], &array[j]);  
        }
    }

    swap(&array[i - 1], &array[low]); // Place pivot in the correct position
    return i - 1; // Return pivot index
}

// QuickSort function
void QuickSortFirst(int array[], int low, int high){
    if(low < high){
        int pi = PartitionFirst(array, low, high);
        QuickSortFirst(array , low, pi - 1);
        QuickSortFirst(array , pi + 1, high);
    }
}

// Print function
void printarray(int array[], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int array[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Original Array: ";
    printarray(array, size);

    QuickSortFirst(array, 0, size - 1);

    cout << "Sorted Array: ";
    printarray(array, size);

    return 0;
}
