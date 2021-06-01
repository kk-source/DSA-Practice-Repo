#include <iostream>
#include <string>
using namespace std;
int subsetSum(int arr[], int n, int sum, int curr=0){
    if (n==0){
    if (curr==sum)
    return 1;
    return 0;
    }
    return subsetSum(arr+1, n-1, sum, curr) + subsetSum(arr+1, n-1, sum, curr+arr[0]);
}
int subsetSum1(int arr[], int n, int sum, int curr=0){
    if (n==0){
    if (curr==sum)
    return 1;
    return 0;
    }
    return subsetSum(arr, n-1, sum, curr) + subsetSum(arr, n-1, sum, curr+arr[n-1]);
}
int subsetSum2(int arr[], int n, int sum){
    if (n==0){
        if (sum==0)
        return 1;
        return 0;
    }
    return subsetSum2(arr, n-1,sum)+subsetSum2(arr, n-1,sum-arr[n-1]);
}
int main(){
    int arr[]={10,5,2,6,-6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << subsetSum2(arr, n, 0);

    return 0;
}