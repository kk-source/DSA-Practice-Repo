#include <bits/stdc++.h>
using namespace std;
bool safe(int i, int j, int N, int M)
{
    return (i>=0 && i<N && j>=0 && j<M);
}
void fun(int i, int j, int N, int M, long long &ans){
    int count=0;
    if (safe(i-1, j+2, N, M))
    count++;
    if (safe(i+1, j+2, N, M))
    count++;
    if (safe(i-1, j-2, N, M))
    count++;
    if (safe(i+1, j-2, N, M))
    count++;
    if (safe(i-2, j-1, N, M))
    count++;
    if (safe(i-2, j+1, N, M))
    count++;
    if (safe(i+2, j-1, N, M))
    count++;
    if (safe(i+2, j+1, N, M))
    count++;
    ans=ans+(N*M-count-1);
    int mod=1e9+7;
    ans%=mod;
}
long long solve(int N, int M)
{
    long long ans=0;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            fun(i, j, N, M, ans);
        }
    }
    return ans;
}
int main(){
    cout << solve(2, 2);
    return 0;
}