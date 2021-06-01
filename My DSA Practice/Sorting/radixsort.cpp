#include <iostream>
#include <string>
using namespace std;
void countsort(int arr[],int n, int k){
    int count[10];
    for (int i=0;i<10;i++){
        count[i]=0;
    }
    for (int i=0;i<n;i++){
        count[(arr[i]/k)%10]++;
    }
    for (int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for (int i=n-1;i>=0;i--){
        output[count[(arr[i]/k)%10]-1]=arr[i];
        count[(arr[i]/k)%10]--;
    }
    for (int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
void radixsort(int arr[], int n){
    int mx=arr[0];
    for (int i=1;i<n;i++){
        mx=max(mx,arr[i]);
    }
    for (int i=1;mx/i>0;i*=10){
        countsort(arr, n, i);
    }

}
int main(){
    int arr[]={319,212,6,8,100,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    for (int i: arr)
    cout << i << " ";

    return 0;
}