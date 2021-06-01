#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i){
        int largest=i, l=2*i+1, r=2*i+2;
        if (l<n && arr[largest]<arr[l])
        largest=l;
        if (r<n && arr[largest]<arr[r])
        largest=r;
        if (largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr, n, largest);
        }
}
void buildHeap(int arr[], int n){
    for (int i=(n-2)/2;i>=0;i--){
        heapify(arr, n, i);
    }
}
void heapsort(int arr[], int n){
    buildHeap(arr, n);
    for (int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main(){
    int arr[]={50,50,40,40,30,30,20,20,10,10,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr, n);
    for (int i: arr)
    cout << i << " ";
    return 0;
}