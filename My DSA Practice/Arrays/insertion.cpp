#include <iostream>
#include <string>
using namespace std;
int insert(int arr[], int n, int cap, int key, int pos){
    if (n==cap)
    return -1;
    int ind=pos-1;
    for (int i=n;i>=ind;i--)
        arr[i+1]=arr[i];
    arr[ind]=key;
    return 1;
}
int main(){
    int arr[10]={1,23,4,5,6,45,7,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    // cout <<n;
    insert(arr, 8, 10, 12, 2);
    for (int i=0;i<n-1;i++){
        cout << arr[i] << " ";
    }
    return 0;
}