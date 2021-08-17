#include <iostream>
#include <climits>
using namespace std;
int sum(int arr[], int b, int e){
    int ans=0;
    for (int i=b;i<=e;i++)
        ans+=arr[i];
    return ans;
}
int minpages(int arr[], int n, int k){ // naive.
    if (k==1)
        return sum(arr, 0, n-1);
    
    if (n==1)
        return arr[0];

    int res=INT_MAX;
    for (int i=1;i<n;i++){
        // res=min(res,max(minpages(arr,i,k-1),sum(arr,i,n-1)));
        res=min(res,max(sum(arr,0,i-1),minpages(arr+i,n-i,k-1)));
    }
    return res;
}
int minpages1(int arr[], int n, int k){
    int low=0;
    int high=0;
    for (int i=0;i<n;i++){
        high+=arr[i];
        low=max(low,arr[i]);
    }
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        int count=1, sum=0;
        for (int i=0;i<n;i++){
            if (sum+arr[i]>mid){
            sum=arr[i];
            count++;
            }
            else
            sum+=arr[i];
        }
        if (count>k)
        low=mid+1;
        else{
        high=mid-1;
        ans=mid;
        }
    }
    return ans;
}
int main(){
    // int arr[]={10,20,10,30};
    int arr[]={12,34,67,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    // 4
// 12 34 67 90
// 2
    cout << minpages1(arr, n, k);

    return 0;
}