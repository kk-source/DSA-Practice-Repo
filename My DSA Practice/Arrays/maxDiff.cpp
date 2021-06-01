#include <iostream>
#include <climits>
using namespace std;
int maxDiff(int arr[], int n){
    int res=INT_MIN;
    for (int i=0;i<n;i++){// max of (arr[j]-arr[i]) where j>i.
        for (int j=i+1;j<n;j++)
            res=max(res,arr[j]-arr[i]);
    }
    return res;
}
int maxDiffMost(int arr[], int n){
    int res=arr[1]-arr[0];
    int minvalue=arr[0];
    for (int i=1;i<n;i++){
        res=max(res, arr[i]-minvalue);
        minvalue=min(minvalue,arr[i]);
    }
    return res;
}
int maxDiffMost1(int arr[], int n){ // above implementation in reverse order.
    int maxvalue=arr[n-1];
    int res=arr[n-1]-arr[n-2];
    for (int i=n-2;i>=0;i--){
        res=max(res, maxvalue-arr[i]);
        maxvalue=max(maxvalue, arr[i]);
    }
    return res;
}
int main(){
    int arr[]={2,3,10,6,4,8,1};
    // int arr[]={30,20,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << maxDiffMost1(arr, n);
    return 0;
}