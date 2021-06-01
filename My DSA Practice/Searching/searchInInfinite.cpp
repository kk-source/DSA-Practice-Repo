#include <iostream>
#include <string>
using namespace std;
int search(int arr[], int key){
    int i=0;
    while(true){
        if (arr[i]==key)
        return i;
        else if (arr[i]>key)
        return -1;
        i++;
    }
}
int searchbin(int arr[], int key){
    if (key==arr[0]) return 0;

    int i=1;
    int low;
    while(key>arr[i]){
        low=i+1;
        i*=2;
    }
    if (arr[i]==key) return i;
    
    int high=i-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (arr[mid]<key)
        low=mid+1;
        else if (arr[mid]>key)
        high=mid-1;
        else
        return mid;
    }
    return -1;
}
int main(){
    int arr[]={1,10,15,20,40,60,80,100,200,500,1000};
    // int n=sizeof(arr)/sizeof(arr[0]);
    int k; cin >> k;
    // cout << search(arr, k);
    cout << searchbin(arr, k);
    return 0;
}