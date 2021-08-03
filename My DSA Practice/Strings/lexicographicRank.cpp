#include <bits/stdc++.h>
using namespace std;
const int CHAR = 256;
int fact(int n){
    int ans=1;
    for (int i=n;i>=1;i--)
    ans*=i;
    return ans;
}
// only for distinct elements.
int s(string &str){
    int ans=1;
    int n=str.size();
    int mul=fact(n);
    int count[CHAR]={0};
    for (int i=0;i<n;i++)
        count[str[i]]++;
    for (int i=1;i<CHAR;i++)
        count[i]+=count[i-1];
    for (int i=0;i<n-1;i++){
        mul/=(n-i);
        ans+=count[str[i]-1]*mul; // count[str[i]-1] gives no. of elements smainter than str[i].
        for(int j=str[i];j<CHAR;j++)
            count[j]--;
    }
    return ans;
}
int main(){
    string str="aaaa";
    cout << s(str);
    return 0;
}