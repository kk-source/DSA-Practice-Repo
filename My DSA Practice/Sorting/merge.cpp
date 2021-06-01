#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int n1=mid-low+1, n2=high-mid;
    int l[n1], r[n2];
    int ind=0;
    for (int i=low;i<=mid;i++){
        l[ind++]=arr[i];
    }
    ind=0;
    for (int i=mid+1;i<=high;i++){
        r[ind++]=arr[i];
    }
    int i=0, j=0; 
    ind=low;
    while(i<n1 && j<n2){
        if (l[i]<=r[j]){
            arr[ind++]=l[i];
            i++;
        }
        else{
            arr[ind++]=r[j];
            j++;
        }
    }
    while(i<n1){
        arr[ind++]=l[i++];
    }
    while(j<n2){
        arr[ind++]=r[j++];
    }
}
void mergeSort(int arr[], int l, int r){
    if (r>l){
        int m=l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main(){
    int a[]={4,3,2,1};
    // int b[]={5,6,6,15};
    // int b[]={3};
    int n=sizeof(a)/sizeof(int);
    mergeSort(a, 0, n-1);
    for (int i:a)
    cout << i << " ";
    return 0;
}