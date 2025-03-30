#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int array[], int low , int high){
    int pivot = array[high];
    int i = low - 1;


for(int j = low; j < high; j++) {
    if(array[j] < pivot) {
        i++;  
        swap(&array[i], &array[j]);  
    }
}

swap(&array[i + 1] , &array[high]);
return i + 1;

}

void QuickSort(int array[], int low, int high){
    if(low < high){
        int pi = Partition(array,low,high);
        QuickSort(array , low, pi - 1);
        QuickSort(array , pi + 1, high);
        
    }
}



void printarray(int array[] , int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}


int main() {

int array[] = {10, 7, 8, 9, 1, 5};
 int n = sizeof(array) / sizeof(array[0]);
 
 cout << "Original Array: ";
   printarray(array, n); 
 QuickSort(array,0,n - 1);
 
 cout << "Sorted Array: ";
 
 printarray(array,n);
 
    return 0;
}






