#include <iostream>
#include <string>
using namespace std;
void threeway(int arr[], int n, int pivot){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if (arr[mid]<pivot){
            swap(arr[mid],arr[low]);
            low++; mid++;
        }
        else if (arr[mid]==pivot)
            mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    int arr[]={2,1,2,20,20,10,20,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    threeway(arr, n, 20);
    for (int i:arr)
    cout << i << " ";
    return 0;
}