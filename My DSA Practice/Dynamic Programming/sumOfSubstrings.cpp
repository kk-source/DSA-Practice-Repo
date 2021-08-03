#include <bits/stdc++.h>
using namespace std;
int p=1e9+7;
    long long sumSubstrings(string s){
        long long ans=0;
        for (int i=0;i<s.size();i++){
            long long temp=0;
            for (int j=i;j<s.size();j++){
                temp=(temp*10)%p;
                temp=(temp+s[j]-'0')%p;
            ans+=temp;
            }
        }
        return ans;
    }
int main(){
    cout << sumSubstrings("1234");

    return 0;
}