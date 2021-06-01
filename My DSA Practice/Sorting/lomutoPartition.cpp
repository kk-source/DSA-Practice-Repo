#include <bits/stdc++.h>
using namespace std;

int lomutoPartition(int arr[], int l, int h)
{   
    int pivot=arr[h];
    int i=l;
    for(int j=l;j<h;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[h]);
    return i;
}
 
int main() {
	
    // int arr[]={10,80,30,90,40,50,70};
	// int arr[]={70, 60, 80, 40, 30};
    // int arr[]={30,40,20,50,80};
    // int arr[]={10, 7, 8, 5};
    int arr[]={-12,18,-10,15};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout << lomutoPartition(arr,0,n-1);
	
	for(int x: arr)
	    cout<<x<<" ";
}