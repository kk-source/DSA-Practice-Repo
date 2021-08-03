#include <bits/stdc++.h>
using namespace std;
int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        dp[0]=0;
        for (int i=1;i<=n;i++){
            dp[i]=-1;
            if (i>=x)
            dp[i]=max(dp[i], dp[i-x]);
            if (i>=y)
            dp[i]=max(dp[i], dp[i-y]);
            if (i>=z)
            dp[i]=max(dp[i], dp[i-z]);
            if (dp[i]!=-1)
            dp[i]++;
        }
        for (auto i:dp)
        cout << i << " ";
        return dp[n];
    }   
int main(){
    maximizeTheCuts(100, 23, 15, 50);

    return 0;
}