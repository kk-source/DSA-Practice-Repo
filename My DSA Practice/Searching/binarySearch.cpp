#include <iostream>
using namespace std;

int bin(int arr[], int n, int key){ // iterative
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (arr[mid]==key)
        return mid;
        else if (arr[mid]>key)
        high=mid-1;
        else
        low=mid+1;
    }
    return -1;
}

int bin1(int arr[], int low, int high, int key){ // recursive
    if (low>high)
    return -1;

    int mid=(low+high)/2;
    if (arr[mid]==key)
    return mid;
    else if (arr[mid]>key)
    return bin1(arr, low, mid-1, key);
    else
    return bin1(arr, mid+1, high, key);
    
}

int main(){
    int arr[]={10, 10, 10, 40, 50, 60};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;
    cout << bin1(arr, 0, n-1, k);

    return 0;
}