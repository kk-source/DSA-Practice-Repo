#include <bits/stdc++.h>
using namespace std;
int longest(int arr[], int n, int prev=INT_MAX)
{
    if (n==0)
    return 0;
    int res=0;
    // including.
    if (prev>arr[n-1]){
        res=max(res, longest(arr, n-1, arr[n-1])+1);
    }
    // not including.
    res=max(res, longest(arr, n-1, prev));
    return res;
}
int result(int arr[], int n)
    {
        int lis[n];
        lis[0]=1;
        for (int i=1;i<n;i++){
            lis[i]=0;
            for (int j=0;j<i;j++){
                if (arr[j]<arr[i] && lis[j]+1>lis[i])
                lis[i]=lis[j]+1;
            }
        }

        int res=lis[0];
        for (int i=1;i<n;i++)
        res=max(res, lis[i]);
        // cout << lis[i] << ' ';
        return res;
    }
int main(){
    int arr[]={0,8,4,12,2,10,6,14,1,9,5,
     13,3,11,7,15};
    int n=sizeof(arr)/sizeof(int);
    cout << result(arr, n);

    return 0;
}