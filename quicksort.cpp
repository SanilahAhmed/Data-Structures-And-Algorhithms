#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low >= high) // Base case: low == high → array mein sirf 1 element hai
            return;  // if (low > high) → array mein koi element nahi
                    
       

    int pivot = arr[high];
    int i = low - 1;      //i ka kaam hai pivot se chote numbers ki position track karna.

    for (int j = low; j < high; j++) { // j ka loop "0-6" tk chalega 
        if (arr[j] < pivot) {          // agar current element pivot se chota hai, toh i ko increment karo aur swap karo
            i++;
            swap(arr[i], arr[j]); // swap karne se chote elements pivot ke left side mein aa jayenge
        }
    }
    swap(arr[i + 1], arr[high]); // arr[0] swapped by arr[6] 
    int p = i + 1;  // p = 0 + 1 = 1, p = 1 + 1 = 2, p = 2 + 1 = 3, p = 3 + 1 = 4, p = 4 + 1 = 5, p = 5 + 1 = 6

    quickSort(arr, low, p - 1); // Recursive call for left subarray
    quickSort(arr, p + 1, high); // Recursive call for right subarray
}

int main() {
    int arr[] = {2,5, 9, 6, 7, 3, 1};
    int n = 7;

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
