#include <iostream>
#include <climits>
using namespace std;
int maxSubarraySum(int arr[], int n){
    // int res=0;
    int ans=arr[0];
    for (int i=0;i<n;i++){
        int res=0;
        for (int j=i;j<n;j++){
            res+=arr[j];
            ans=max(ans,res);
        }
    }
    return ans;
}
int maxSubarraySumMost(int arr[], int n){
    int prevSum=arr[0];
    int ans=arr[0];
    for (int i=1;i<n;i++){
        // if (prevSum+arr[i]>arr[i]){
        //     prevSum+=arr[i];
        // }
        // else {
        //     prevSum=arr[i];
        // }
        prevSum=max(prevSum+arr[i],arr[i]);// above code in simple lines.
        ans=max(ans,prevSum);
    }
    return ans;
}

int main(){ 
    // int arr[]={-5,1,-2,3,-1,2,-2};
    int arr[]={3,-4,5,6,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << maxSubarraySumMost(arr, n);

    return 0;
}