#include <iostream>
#include <string>
using namespace std;
int invert(int arr[], int n){ // naive.
    int count=0;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}
int mergesort(int arr[], int low, int mid, int high){
    int n=mid-low+1;
    int m=high-mid;
    int a[n], b[m];
    int ind=0;
    for (int i=low;i<=mid;i++){
        a[ind++]=arr[i];
    }
    ind=0;
    for (int i=mid+1;i<=high;i++){
        b[ind++]=arr[i];
    }
    int ans=0;
    int i=0,j=0;
    ind=low;
    while(i<n && j<m){
        if (a[i]<=b[j]){
            arr[ind++]=a[i];
            i++;
        }
        else{
            // cout << "p";
            arr[ind++]=b[j];
            j++;
            ans+=(n-i);
        }
    }
    while(i<n){
        arr[ind++]=a[i];
        i++;
    }
    while(j<m){
        arr[ind++]=b[j];
        j++;
    }
    // cout << ans << " ";
    return ans;
}
int merge(int arr[], int low, int high){
    int res=0;
    if (low<high){
        int m=(low+high)/2;
    res+=merge(arr, low, m);
    res+=merge(arr, m+1, high);
    res+=mergesort(arr, low, m, high);
    }
    return res;
}
int main(){
    int arr[]={2,4,1,3,5};//4,3,2,1
    int n=sizeof(arr)/sizeof(arr[0]);
    // cout << invert(arr, n);
    cout << merge(arr, 0, n-1);
    for (auto i:arr)
    cout << i << " ";
    return 0;
}