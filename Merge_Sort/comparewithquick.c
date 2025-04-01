#include <iostream>
#include <chrono> // For time measurement
using namespace std;
using namespace std::chrono;

// Merge Sort Implementation
void Merge(int arr[], int l, int mid, int r ){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2];
    
    for(int i = 0; i < n1; i++) a[i] = arr[l + i];
    for(int i = 0; i < n2; i++) b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    while (i < n1) arr[k++] = a[i++];
    while (j < n2) arr[k++] = b[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

// Quick Sort Implementation
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int low , int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;  
            swap(&arr[i], &arr[j]);  
        }
    }
    swap(&arr[i + 1] , &arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

// Main Function to Compare Execution Time
int main() {
    int arr1[] = {8, 5, 9, 4, 3, 2, 0, 1};
    int arr2[] = {8, 5, 9, 4, 3, 2, 0, 1}; // Copy for QuickSort
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // Measure Merge Sort Execution Time
    auto start1 = high_resolution_clock::now();
    mergeSort(arr1, 0, n - 1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    // Measure Quick Sort Execution Time
    auto start2 = high_resolution_clock::now();
    QuickSort(arr2, 0, n - 1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    // Print Sorted Arrays
    cout << "Merge Sort Output: ";
    printArray(arr1, n);
    cout << "Execution Time: " << duration1.count() << " microseconds\n";

    cout << "Quick Sort Output: ";
    printArray(arr2, n);
    cout << "Execution Time: " << duration2.count() << " microseconds\n";

    return 0;
}
