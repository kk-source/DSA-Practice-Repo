#include <iostream>
#include <limits>
using namespace std;
int maxInArray(int arr[], int n){
    int m=arr[0];
    int ind;
    for (int i=1;i<n;i++){
        m=max(arr[i],m);
        if (arr[i]==m)
        ind=i;
    }
    return m;
}
int secondLargest(int arr[], int n){ // two times the loop is run.
    int r=arr[0];
    int l=-1;
    for(int i=1;i<n;i++){
        r=max(r,arr[i]);
    }
    for (int i=0;i<n;i++){
        int temp=max(l,arr[i]);
        if (temp!=r)
        l=temp;
    }
    return l;
}
int secondLargestMost(int arr[], int n){ // only one time the loop is run.
    int res=-1, largest=0;
    for (int i=1;i<n;i++){
        if (arr[i]>arr[largest]){
            res=largest;
            largest=i;
        }
        else if (arr[i]<arr[largest]){
            if (res==-1 || arr[i]>arr[res])
            res=i;
        }
    }
    return arr[res];
}
int main(){ //5,20,12,20,8
    int arr[]={1,1,1,1,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << maxInArray(arr, n);
    return 0;
}