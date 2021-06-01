#include <iostream>
#include <string>
using namespace std;
void merge(int a[], int b[], int n, int m){
    int i=0, j=0;
    while(i<n && j<m){
        if (a[i]<=b[j]){
        cout << a[i] << " ";
        i++;
        }
        else{
        cout << b[j] << " ";
        j++;
        }
    }
    while(i<n){
    cout << a[i] << " ";
    i++;
    }
    while(j<m){
    cout << b[j] << " ";
    j++;
    }
}
void merge1(int arr[], int low, int mid, int high){
    int l[mid-low+1], r[high-mid];
    int ind=0;
    for (int i=low;i<=mid;i++){
        l[ind++]=arr[i];
    }
    ind=0;
    for (int i=mid+1;i<=high;i++){
        r[ind++]=arr[i];
    }
    int i=0, j=0; 
    ind=0;
    while(i<mid-low+1 && j<high-mid){
        // cout << "p";
        if (l[i]<=r[j]){
            arr[ind++]=l[i];
            i++;
        }
        else{
            arr[ind++]=r[j];
            j++;
        }
    }
    while(i<mid-low+1){
        arr[ind++]=l[i];
        i++;
    }
    while(j<high-mid){
        arr[ind++]=r[j];
        j++;
    }
}
int main(){
    // int a[]={10, 15, 20};
    int a[]={10, 15, 20, 11, 30};
    // int b[]={5,6,6,15};
    // int b[]={3};
    int n=sizeof(a)/sizeof(int);
    // int m=sizeof(b)/sizeof(int);
    merge1(a, 0, 2, 4);
    for (int i:a)
    cout << i << " ";
    return 0;
}