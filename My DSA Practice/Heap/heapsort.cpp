#include <iostream>
#include <string>
using namespace std;
void maxheapify(int arr[], int n, int i){
    int lt=(2*i+1), rt=(2*i+2);
    int largest=i;
    if (lt<n && arr[lt]>arr[largest])
    largest=lt;
    if (rt<n && arr[rt]>arr[largest])
    largest=rt;
    if (largest!=i){
        swap(arr[largest], arr[i]);
        maxheapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n){
    for (int i=(n-2)/2;i>=0;i--){
        maxheapify(arr, n, i);
    }
}
void heapsort(int arr[], int n){
    buildHeap(arr, n);
    for (int i=n-1;i>=1;i--){
        swap(arr[0], arr[i]);
        maxheapify(arr, i, 0);
    }
}
int main(){
    int arr[]={50, 20, 10, 4, 15};
    int n=sizeof(arr)/sizeof(int);
    heapsort(arr, n);
    for (auto i:arr)
    cout << i << " ";
    return 0;
}