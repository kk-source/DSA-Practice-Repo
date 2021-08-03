#include <bits/stdc++.h>
using namespace std;
bool f(int i, int j, int a, int b){
        return (i<a && j<b);
    }
    int NumberOfPath(int a, int b)
    {
        int dp[a][b];
        dp[a-1][b-1]=1;
        for (int i=b-2;i>=0;i--){
            int c=i;
            for (int j=a-1;j>=0 && c<b;j--, c++){
                dp[j][c]=0;
                if (f(j+1, c, a, b))
                dp[j][c]+=dp[j+1][c];
                if (f(j, c+1, a, b))
                dp[j][c]+=dp[j][c+1];
            }
        }
        for (int r=a-2;r>=0;r--){
            int row=r;
            for (int c=0;c<b && row>=0;c++, row--){
                dp[row][c]=0;
                if (f(row+1, c, a, b))
                dp[row][c]+=dp[row+1][c];
                if (f(row, c+1, a, b))
                dp[row][c]+=dp[row][c+1];
            }
        }
        return dp[0][0];
    }
int main(){
    cout << NumberOfPath(3, 4);

    return 0;
}