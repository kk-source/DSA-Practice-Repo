#include <iostream>
#include <string>
using namespace std;
int sum(int arr[], int l, int r){  // naive
    int sum=0;
    for (int i=l;i<=r;i++){
        sum+=arr[i];
    }
    return sum;
}
int sumMost(int prefixSum[], int l, int r){
    if (l!=0)
    return prefixSum[r]-prefixSum[l-1];
    else
    return prefixSum[r];
}
void equilibirium(int arr[], int n){ //O(n^2)
    for (int i=0;i<n;i++){
        int lsum=0,rsum=0;
        for (int j=0;j<i;j++)
        lsum+=arr[j];
        for (int j=i+1;j<n;j++)
        rsum+=arr[j];
        if (lsum==rsum){
           cout << "yes " << arr[i];
        return; 
        }
    }
    cout << "no";
}
void equilibiriumMost(int arr[], int n){//O(n) space.
    int prefixSum[n];
    prefixSum[0]=arr[0];
    for (int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    for (int i=0;i<n;i++){
        if (i!=0 || i!=n-1){
            if (prefixSum[i-1]==prefixSum[n-1]-prefixSum[i]){
            cout << "yes" << " "<< arr[i];
            return;
        }
        }
        else {
            if (prefixSum[n-1]-arr[i]==0){
            cout << "yes" << " "<< arr[i];
            return;
            }
        }
    }
    cout << "no";
}
void equilibiriumMostMost(int arr[], int n){//O(1) space.
    int currSum=arr[0];
    for(int i=1;i<n;i++){
        currSum+=arr[i];
    }
    int lSum=0;
    for (int i=0;i<n;i++){
        if (currSum-arr[i]==lSum){
            cout << "yes" << " " << arr[i];
            return;
        }
        currSum-=arr[i];
        lSum+=arr[i];
    }
    cout << "no" << endl;
}
int main(){
    int arr[]={3,4,8,-9,20,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int prefixSum[n];
    prefixSum[0]=arr[0];
    for (int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    // cout << sum(arr, 1, 1);
    // cout << endl << sumMost(prefixSum, 1, 1);
    equilibiriumMostMost(arr, n);
    equilibiriumMost(arr, n);
    return 0;
}