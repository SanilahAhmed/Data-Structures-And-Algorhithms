#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];  // ✅ dynamic array

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = linearSearch(arr, n, key);

    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;

    delete[] arr; // ✅ free memory
    return 0;
}