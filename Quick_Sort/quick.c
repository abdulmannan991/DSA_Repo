#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and place pivot at its correct position
int Partition(int array[], int low , int high){
    int pivot = array[high]; // Choosing the last element as pivot
    int i = low - 1; // Pointer for the smaller element

    // Traverse the array and rearrange elements
    for(int j = low; j < high; j++) {
        if(array[j] < pivot) {  // If current element is smaller than pivot
            i++;  
            swap(&array[i], &array[j]);  // Swap smaller element to the left
        }
    }

    // Swap pivot with the element at (i+1) position to place it correctly
    swap(&array[i + 1] , &array[high]);
    return i + 1; // Return the pivot index
}

// QuickSort function to recursively sort the array
void QuickSort(int array[], int low, int high){
    if(low < high){
        int pi = Partition(array, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        QuickSort(array , low, pi - 1);
        QuickSort(array , pi + 1, high);
    }
}

// Function to print the array
void printarray(int array[] , int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[] = {10, 7, 8, 9, 1, 5}; // Initial array
    int size = sizeof(array) / sizeof(array[0]); // Calculating array size

    cout << "Original Array: ";
    printarray(array, size); // Print original array

    QuickSort(array, 0, size - 1); // Apply QuickSort

    cout << "Sorted Array: ";
    printarray(array, size); // Print sorted array

    return 0;
}
