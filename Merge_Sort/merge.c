#include <iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2];

    // Copy data to temp arrays
    for(int i = 0; i < n1; i++){
        a[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++){
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;  // Corrected k initialization

    // Merge the temporary arrays back into arr[l..r]
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of a[], if any
    while (i < n1) {
        arr[k] = a[i];
        i++; k++;
    }

    // Copy remaining elements of b[], if any
    while (j < n2) {
        arr[k] = b[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

int main() {
    int arr[] = {8, 5, 9, 4, 3, 2, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0;
    int r = n - 1;
    
    mergeSort(arr, l, r);

    cout << "Sorted array: ";
    for (int a = 0; a < n; a++) {
        cout << arr[a] << " ";
    }
    cout << endl;

    return 0;
}
