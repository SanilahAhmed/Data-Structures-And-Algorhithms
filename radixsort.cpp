#include <iostream>
using namespace std;

int getMax(int a[], int n){  // n=8
    int m = a[0];            //m=170
    for(int i=1;i<n;i++) 
        if(a[i] > m)
            m = a[i];
    return m;
}

void countSort(int a[], int n, int exp){ // exp=1(units),10(tens),100(hundreds)
    int output[8];
    int count[10] = {0};

    for(int i=0;i<n;i++) 
        count[(a[i]/exp)%10]++; // 170/1%10=0,  count[0]=1, 45/1%10=5, count[5]=1 ,75/1%10=5, count[5]=2,
                                // 90/1%10=0, count[0]=2, 802/1%10=2, count[2]=1, 24/1%10=4, count[4]=1, 
                                // 2/1%10=2, count[2]=2, 66/1%10=6, count[6]=1,  
                                
                                // [2,0,2,0,1,2,1,0,0,0] normal  count

    for(int i=1;i<10;i++) // comulative count
        count[i] += count[i-1]; // count[0]=2, count[1]=0+2=2, count[2]=2+2=4, count[3]=0+4=4, count[4]=1+4=5, count[5]=2+5=7, count[6]=1+7=8, count[7]=0+8=8, count[8]=0+8=8, count[9]=0+8=8
        // arr[1]=arr[0]+arr[1] -->  [2,2,4,4,5,7,8,8,8,8]

    for(int i=n-1;i>=0;i--){
        output[count[(a[i]/exp)%10]-1] = a[i]; // output[count[a[7]/1%10]-1] = count[66/1%10]-1 = count[6]-1 = 8-1=7, output[7] = 66
        count[(a[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
        a[i] = output[i];
}

int main(){
    int a[8] = {170,45,75,90,802,24,2,66};
    int n = 8;
    int m = getMax(a, n);

    for(int exp=1; m/exp>0; exp*=10)
        countSort(a, n, exp);

    for(int i=0;i<n;i++)
        cout << a[i] << " ";

    return 0;
}