#include <iostream>
#include <string>
using namespace std;
int deletion(int arr[], int n, int key){
    if (arr[n-1]==key)
    return n-1;
    int ind;
    int i;
    for (i=0;i<n;i++){
        if (arr[i]==key){
        ind=i;
        break;
        }
    }
    if (i==n)
    return n;
    for (i=ind;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    return n-1;
}
int main(){
    int arr[]={1,23,4,5,6,45,7,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    deletion(arr, n, 0);
    for (int i=0;i<n-1;i++)
    cout << arr[i]<<" ";
    return 0;
}