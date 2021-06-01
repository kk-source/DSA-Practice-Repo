#include <iostream>
#include <string>
using namespace std;
bool pairsum(int arr[], int n, int x){ // naive for unsorted array.
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]+arr[j]==x)
            return true;
        }
    }
    return false;
}
bool isPair(int arr[], int n, int x){ // using two pointer for sorted array.
    int start=0,end=n-1;
    while(start<end){
        int sum=arr[start]+arr[end];
        if (x==sum)
        return true;
        else if (x>sum)
        start++;
        else 
        end--;
    }
    return false;
}
bool isPair1(int arr[], int low, int high, int x){ // using two pointer for sorted array.
    int start=low,end=high;
    while(start<end){
        int sum=arr[start]+arr[end];
        if (x==sum)
        return true;
        else if (x>sum)
        start++;
        else 
        end--;
    }
    return false;
}
bool isTriplet(int arr[], int n, int x){
    for (int i=0;i<n;i++){
        if (isPair1(arr,i+1,n-1,x-arr[i]))
        return true;
    }
    return false;
}
int main(){
    // int arr[]={3,5,9,2,8,10,11};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout << pairsum(arr, n, 17);

    // int arr[]={2,3,5,8,9,10,11};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int k; cin >> k;
    // cout << isPair(arr, n, k);

    int arr[]={2,3,4,8,9,20,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k; cin >> k;
    cout << isTriplet(arr, n, k);
    return 0;
}