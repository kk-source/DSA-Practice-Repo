#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[W+1][n+1];
        for (int i=0;i<=W;i++){
            for (int j=0;j<=n;j++){
                if (i==0 || j==0)
                dp[i][j]=0;
                else{
                    dp[i][j]=dp[i][j-1];
                    if (i>=wt[j-1])
                    dp[i][j]=max(dp[i][j], dp[i-wt[j-1]][j-1]+val[j-1]);
                }
            }
        }
        return dp[W][n];
    }
int main(){
    int n=3, w=3;
    int val[]={1, 2, 3};
    int wt[]={4, 5, 6};
    cout << knapSack(w, wt, val, n);

    return 0;
}