#include <iostream>
using namespace std;

// Merge two sorted parts
void merge(int arr[], int start, int mid, int end) { // arr original array
    int temp[100];  // temporary array

    int left = start;      
    int right = mid + 1;    
    int index = 0;

    // Compare and store smaller value   arr[4 9 3 8 10 2 5]-->[4 9 3 8] [10 2 5]
                                     //   [4 9] [3 8] [10] [2 5]   
    while (left <= mid && right <= end) {
        if (arr[left] < arr[right]) { // if 4 < 3 temp[0] = 4 else temp[0] = 3
            temp[index] = arr[left]; // 
            left++;
        } else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    // Remaining left side
    while (left <= mid) {
        temp[index] = arr[left];
        left++;
        index++;
    }

    // Remaining right side
    while (right <= end) {
        temp[index] = arr[right];
        right++;
        index++;
    }

    // Copy back to original array
    for (int i = 0; i < index; i++) {
        arr[start + i] = temp[i];
    }
}

// Main merge sort function
void mergeSort(int arr[], int start, int end) {
    // Stop when only one element
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    // Sort left half
    mergeSort(arr, start, mid);

    // Sort right half
    mergeSort(arr, mid + 1, end);

    // Merge both halves
    merge(arr, start, mid, end);
}

int main() {
    int arr[] = {5, 2, 4, 1};
    int size = 4;

    mergeSort(arr, 0, size - 1);

    cout << "Sorted: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}