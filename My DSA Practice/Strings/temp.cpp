#include <bits/stdc++.h>
using namespace std;
#define c 26
        int findRank(string S) 
    {
        int n=S.size();
        long long count[c]={0};
        long long mul=1;
        for (int i=n;i>=1;i--)
            mul=(mul*i);
        cout << mul << " ";
        for (int i=0;i<n;i++){
        count[S[i]-'a']++;
        if (count[S[i]-'a']>1)
        return 0;
        }
        for (int i=1;i<c;i++){
            count[i]+=count[i-1];
        }
        long long ans=1;
        for (int i=0;i<n-1;i++){
            mul/=(n-i);
            ans=(ans+count[S[i]-1-'a']*mul)%1000000007;
            for (int j=S[i]-'a';j<c;j++){
                count[j]--;
            }
        }
        return (ans<0)? ans+1000000007:ans;
    }
int main(){
    string str="tucmhpqzwrgeixkjnaslvyfdbo";
    cout << findRank(str);
    return 0;
}