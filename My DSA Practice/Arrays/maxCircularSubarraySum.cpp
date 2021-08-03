#include <iostream>
#include <string>
using namespace std;
int maxCircular(int arr[], int n){
    int res=arr[0];
    for (int i=0;i<n;i++){
        // doing maxSubarraySum operation on each element.
        int prevSum=arr[i];
        for (int j=1;j<n;j++){
            int index=(i+j)%n;
            prevSum=max(prevSum+arr[index],arr[index]);
        }
        res=max(res, prevSum);
    }
    return res;
}
int maxCircularMost(int arr[], int n){
    int res=arr[0];
    int prevSum=arr[0];

    int total=arr[0];
    
    int tempmin=arr[0];
    int minval=arr[0];
    for (int i=1;i<n;i++){
        total+=arr[i];
        // for min subarray sum.
        tempmin=min(arr[i],tempmin+arr[i]);
        minval=min(minval,tempmin);
        // for max subarray sum.
        prevSum=max(arr[i]+prevSum,arr[i]);
        res=max(res,prevSum);
    }
    // cout << minval << endl;
    if(total==minval)
    return res; // to cover the cases when aint elements are -ve.
    return max(res,total-minval);
}
int main(){//5,-2,3,4
    int arr[]={-3,-4,-5,-6,-8,-7};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << maxCircularMost(arr, n);

    return 0;
}