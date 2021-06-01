#include <bits/stdc++.h>
using namespace std;
// function to count subarrays with 1s and 0s.
int count(int arr[], int n){
    int psum=0, ans=0;
    unordered_map<int, int> m;
    for (int i=0;i<n;i++){
        if (arr[i]==0)
        arr[i]=-1;
        psum+=arr[i];
        if (psum==0)
        ans++;
        if (m.find(psum)!=m.end())
        ans+=m[psum];
        m[psum]++;
    }
    return ans;
}
// function to count subarrays which adds to given sum.
int count1(int arr[], int n, int sum){
    int psum=0, ans=0;
    unordered_map<int, int> m;
    for (int i=0;i<n;i++){
        psum+=arr[i];
        if (psum==sum)
        ans++;
        if (m.find(psum-sum)!=m.end())
        ans+=m[psum-sum];
        m[psum]++;
    }
    return ans;
}
int main(){
    int arr[]={10,2,-2,-20,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << count1(arr, n, -10);
    return 0;
}