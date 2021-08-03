#include <bits/stdc++.h>
using namespace std;
int maxSumSubarray(int arr[], int n)
    {
        int fw[n], bw[n];
        fw[0]=arr[0];
        for (int i=1;i<n;i++){
            fw[i]=max(fw[i-1]+arr[i], arr[i]);
        }
        bw[n-1]=arr[n-1];
        for (int i=n-2;i>=0;i--){
            bw[i]=max(bw[i+1]+arr[i], arr[i]);
        }
        int ans=bw[0];
        for (int i=1;i<n-1;i++){
            ans=max(ans, fw[i-1]+bw[i+1]);
        }
        ans=max(ans, bw[n-1]);
        return ans;
    }
int main(){
    int arr[]={45, 81, 4, 92};
    int n=sizeof(arr)/sizeof(int);
    cout << maxSumSubarray(arr, n);

    return 0;
}