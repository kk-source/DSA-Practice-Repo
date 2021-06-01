#include <iostream>
using namespace std;

int bin(int arr[], int n, int key){ // iterative.
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if (arr[mid]>key)
        high=mid-1;

        else if (arr[mid]<key)
        low=mid+1;
        
        else {
        if (mid==n-1 || arr[mid+1]!=key)
        return mid;

        else
        low=mid+1;
        }
    }
    return -1;
}
int bin1(int arr[], int low, int high, int key, int n){ // recursive.
    if (low>high)
    return -1;
        int mid=(low+high)/2;
        
        if (arr[mid]>key)
        return bin1(arr, low, mid-1, key, n);

        else if (arr[mid]<key)
        return bin1(arr, mid+1, high, key, n);

        else {
        if (mid==n-1 || arr[mid+1]!=key)
        return mid;

        else
        return bin1(arr, mid+1, high, key, n);
        
        }
}
int main(){
    int arr[]={4,5,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;
    cout << bin1(arr, 0, n-1, k, n);
    // cout << bin(arr, n, k);
    return 0;
}