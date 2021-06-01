#include <bits/stdc++.h>
using namespace std;
bool pairSum(int arr[], int n, int sum){ // naive
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            if (arr[i]+arr[j]==sum)
            return true;
        }
    }
    return false;
}
bool pairSum1(int arr[], int n, int sum){
    unordered_set <int> s;
    for (int i=0;i<n;i++){
        if (s.find(sum-arr[i])!=s.end())
        return true;
        s.insert(arr[i]);
    }
    return false;
}
int main(){
    int arr[]={2,3,8,15,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=9;
    cout << pairSum1(arr, n, sum);

    return 0;
}