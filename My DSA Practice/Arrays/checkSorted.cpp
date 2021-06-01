#include <iostream>
#include <string>
using namespace std;
bool isSorted1(int arr[], int n){
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[i])
            return false;
        }
    }
    return true;
}
bool isSortedMost(int arr[], int n){
    for (int i=1;i<n;i++){
        if (arr[i-1]>arr[i])
            return false;
    }
    return true;
}
int main(){
    //5,20,12,20,8
    int arr[]={1,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << isSortedMost(arr, n);
    return 0;
}