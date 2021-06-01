#include <iostream>
#include <string>
using namespace std;
//my way
int partition(int arr[], int l, int h){ 
    int pivot=arr[l];
    int i=l+1, j=h;
    while(true){
        while(arr[i]<pivot && i<=j)
            i++;
        
        while(arr[j]>pivot && j>=i)
            j--;
        
        if (i>=j) // equal to is included to take the case when array is sorted.
        return j;
        swap(arr[i],arr[j]);
        i++; j--;
    }
}
int partition1(int arr[], int l, int h)
{   
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;
        swap(arr[i],arr[j]);
    }
}
int main(){
    // int arr[]={5,3,8,4,2,7,1,10};
    // int arr[]={-12,18,-10,15};
    int arr[]={24, 18, 38, 43, 14,14, 40, 1, 54};
    // int arr[]={5,1,2,5};
    // int arr[]={12,10,5,9};
    // int arr[]={5,5,5,5};
    // int arr[]={1,2,3,4,5,6};
    // int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << partition1(arr, 0, n-1) << " ";
    // partition(arr, 0, n-1);
    for (int i : arr)
    cout << i << " ";
    return 0;
}