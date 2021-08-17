#include <bits/stdc++.h>
using namespace std;
// Longest Palin Subsequence
int fun(string &s1, string &s2, int i=0, int j=0){ // using lcs logic.
    if (i==s1.size() || j==s2.size())
        return 0;
    
    if (s1[i]==s2[j])
        return 1+fun(s1, s2, i+1, j+1);
    else
        return max(fun(s1, s2, i+1, j), fun(s1, s2, i, j+1));
}

int fun1(string &str, int i, int j){ // using start and end index.
    if (i==j)
    return 1;
    if (i>j)
    return 0;
    if (str[i]==str[j]){
        return 2+fun1(str, i+1, j-1);
    }
    else{
        return max(fun1(str, i, j-1), fun1(str, i+1, j));
    }
}
int longestPalindromeSubseq(string &str) { // dp based.
        int n = str.size();
        int dp[n][n];
        // traversing diagonally
        for (int i=0;i<n;i++){
            for (int j=0;j<n-i;j++){ // row
                int r=j, c=i+j;
                if (r==c)
                    dp[r][c]=1;
                else if (str[r]==str[c] && r+1>c-1)
                    dp[r][c]=2;
                else if (str[r]==str[c])
                    dp[r][c]=2+dp[r+1][c-1];
                else
                    dp[r][c]=max(dp[r][c-1], dp[r+1][c]);
            }
        }
        return dp[0][n-1];
    }
int main(){
    string str="aabbaaaa";

    return 0;
}