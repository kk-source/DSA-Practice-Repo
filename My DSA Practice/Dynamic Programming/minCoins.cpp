#include <bits/stdc++.h>
using namespace std;
// recursive.
    long long minimumNumberOfCoins1(int arr[],int n,int val)
    {
        if (val==0)
        return 0;
        long long res=LLONG_MAX;
        for (int i=0;i<n;i++){
            if (val>=arr[i]){
            long long temp=1+minimumNumberOfCoins1(arr, n, val-arr[i]);
            res=min(res, temp);
            }
        }
        if (res==LLONG_MAX)
        return res-1; 
        return res;
    }
    long long minimumNumberOfCoins(int arr[],int n,int val)
    {
        long long ans=minimumNumberOfCoins1(arr, n, val);
        if (ans==LLONG_MAX-1)
        return -1;
        return ans;
    }
// DP
long long fun(int arr[],int n,int val)
{
    long long dp[val+1];
    dp[0]=0;
    
    for (int i=1;i<=val;i++){
        dp[i]=LLONG_MAX-1;
        for (int j=0;j<n;j++){
            if (i>=arr[j])
            dp[i]=min(dp[i], 1+dp[i-arr[j]]);
        }
    }
    return dp[val];
}
long long minimumNumberOfCoins2(int arr[],int n,int val)
    {
        long long ans=fun(arr, n, val);
        if (ans==LLONG_MAX-1)
        return -1;
        return ans;
    }
int main(){
    int arr[]={3,6,3};
    int n=sizeof(arr)/sizeof(int);
    cout << minimumNumberOfCoins2(arr, n, 5);

    return 0;
}