#include <iostream>
using namespace std;


// Take median of three as pivot
// Swap function
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the median of three elements
int MedianOfThree(int array[], int low, int high){
    int mid = low + (high - low) / 2;

    // Sorting the three elements
    if(array[mid] < array[low])
        swap(&array[mid], &array[low]);
    if(array[high] < array[low])
        swap(&array[high], &array[low]);
    if(array[high] < array[mid])
        swap(&array[high], &array[mid]);

    return mid; // Return the index of the median element
}

// Partition function using median-of-three as pivot
int PartitionMedian(int array[], int low , int high){
    int pivotIndex = MedianOfThree(array, low, high); // Find median pivot
    int pivot = array[pivotIndex]; 
    swap(&array[pivotIndex], &array[high]); // Move pivot to end for partitioning
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(array[j] < pivot) {
            i++;  
            swap(&array[i], &array[j]);  
        }
    }

    swap(&array[i + 1], &array[high]); // Move pivot to correct position
    return i + 1; // Return pivot index
}

// Quick Sort function using median pivot
void QuickSortMedian(int array[], int low, int high){
    if(low < high){
        int pi = PartitionMedian(array, low, high);
        QuickSortMedian(array , low, pi - 1);
        QuickSortMedian(array , pi + 1, high);
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

    QuickSortMedian(array, 0, size - 1);

    cout << "Sorted Array: ";
    printarray(array, size);

    return 0;
}
