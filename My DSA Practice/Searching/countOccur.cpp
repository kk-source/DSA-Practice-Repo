#include <iostream>
using namespace std;

int binlast(int arr[], int n, int key){ // iterative.
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
int binfirst(int arr[], int n, int key){ // iterative.
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if (arr[mid]>key)
        high=mid-1;

        else if (arr[mid]<key)
        low=mid+1;
        
        else {
        if (mid==0 || arr[mid-1]!=key)
        return mid;

        else 
        high=mid-1;
        }
    }
    return -1;
}
int count(int arr[], int n, int key){
    int first=binfirst(arr, n, key);
    if (first==-1)
    return 0;

    return binlast(arr, n, key)-first+1;
}
int main(){
    int arr[]={4,5,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;
    cout << count(arr, n, k);
    return 0;
}