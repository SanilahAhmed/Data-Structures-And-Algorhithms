// #include <iostream>
// #include <vector>
// using namespace std;

// int binarySearch(vector<int> arr, int key)
// {
//     int low = 0;
//     int high = arr.size() - 1;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         if (arr[mid] == key)
//             return mid;
//         else if (arr[mid] < key)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }

//     return -1;
// }

// int main()
// {
//     int n, key;
//     cout << "Enter size of array: ";
//     cin >> n;

//     vector<int> arr(n);

//     cout << "Enter sorted array elements:\n";
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     cout << "Enter element to search: ";
//     cin >> key;

//     int result = binarySearch(arr, key);

//     if (result == -1)
//         cout << "Element not found";
//     else
//         cout << "Element found at index " << result;

//     return 0;
// }
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];  //  dynamic array

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;

    delete[] arr; // free memory
    return 0;
}
