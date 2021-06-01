#include <iostream>
#include <string>
using namespace std;
int odd(int arr[], int n){
    int a=arr[0];
    for (int i=1;i<n;i++){
        a=(arr[i]^a);
    }
    return a;
}
int missing(int arr[], int n){
    for (int i=0;i<n;i++)
        arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
    
    for (int i=0;i<n;i++){
        if (arr[i]>0)
        return i+1;
    }
    return n+1;
}
int missingxor(int arr[], int n){
    int a=arr[0];
    for (int i=1;i<n;i++)
        a=a^arr[i];
    for (int i=1;i<=n+1;i++)
        a=a^i;
    return a;
}
int main(){
    // int arr[]={1,1,2,3,3,2,4};
    int arr[]={1,4,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << missingxor(arr, n);
    return 0;
}