#include <iostream>
// #include <string>
using namespace std;
void mbonacci(int n, int m){ // optimised approach.
    int arr[m];
    int i;
    for (i=0;i<n-1;i++){
        arr[i]=0;
        cout << arr[i] << " ";
    }
    arr[i]=1;
        cout << arr[i] << " ";
    int sum=arr[i];

    for (i=n;i<m;i++){
        arr[i]=sum;
        cout << arr[i] << " ";
        sum+=arr[i];
        sum-=arr[i-n];
    }
    return;
}
int main(){
    mbonacci(4,12);
    return 0;
}