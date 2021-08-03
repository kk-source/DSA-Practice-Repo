#include <bits/stdc++.h>
using namespace std;
bool findPartition(int arr[], int n)
    {
        int sum=0;
        for (int i=0;i<n;i++)
        sum+=arr[i];
        int dp[n+1][sum+1];
        for (int i=0;i<=n;i++)
        dp[i][0]=1;
        for (int i=1;i<=sum;i++)
        dp[0][i]=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if (j>=arr[i-1])
                dp[i][j]+=dp[i-1][j-arr[i-1]];
            }
        }
        for (int i=0;i<=sum;i++){
            for (int j=0;j<=n;j++){
            // if (dp[i][j]>1)
            // return true;
            }
            cout << endl;
        }
        return false;
    }
int main(){
    int arr[]={1,3,5};
    int n=3;
    findPartition(arr, n);
    return 0;
}