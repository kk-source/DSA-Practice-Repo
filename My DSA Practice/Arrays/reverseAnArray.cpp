#include <iostream>
#include <string>
using namespace std;
void swap(int arr[], int n){
    int low=0, high=n-1;
    while(low<high){
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
    }
}
int main(){
    int arr[]={1,23,4,5,6,45,30,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    swap(arr, n); 
    for (int i=0;i<n;i++)
    cout << arr[i] << " ";
    return 0;
}