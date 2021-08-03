#include <bits/stdc++.h>
using namespace std;
int countWays(int n)
{
    if (n==1)
    return 0;
    long long dp[n][n+1];
    for (int i=0;i<=n-1;i++)
    dp[i][0]=1;
    for (int i=1;i<=n;i++)
    dp[0][i]=0;
    for (int i=1;i<=n-1;i++){
        for (int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if (j>=i)
            dp[i][j]=(dp[i][j]+dp[i][j-i])%1000000007;
        }
    }
    return dp[n-1][n];
}
int main(){
    cout << countWays(5);

    return 0;
}