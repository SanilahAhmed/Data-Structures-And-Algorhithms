#include <iostream>
using namespace std;

int main() {
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j;

        // Shift elements using a for loop instead of while
        for (j = i - 1; j >= 0 && arr[j] > key; j--) { // 64 > 34, 34 > 25, 25 > 12, 12 > 22 (false)
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = key;
    }

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}