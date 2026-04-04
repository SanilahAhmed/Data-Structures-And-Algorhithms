#include <iostream>
using namespace std;

int main() {
    int a[8] = {2, 4, 1, 5, 9, 4, 10, 3}; //array of 8 integers

    for(int i=0;i<8;i++){  //outer loop to traverse the array
        for(int j=0;j<7;j++){
            if(a[j] > a[j+1]){ //if the current element is greater than the next element, swap them
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    for(int i=0;i<8;i++) // print the sorted array!
        cout << a[i] << " ";

    return 0;
}