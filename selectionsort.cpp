#include <iostream>
using namespace std;

int main() {
    int a[8] = {2, 4, 1, 5, 9, 4, 10, 3};

    for(int i=0;i<7;i++){
        int min = i;
        for(int j=i+1;j<8;j++){
            if(a[j] < a[min])
                min = j;
        }
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }

    for(int i=0;i<8;i++)
        cout << a[i] << " ";

    return 0;
}