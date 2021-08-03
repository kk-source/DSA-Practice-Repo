#include <bits/stdc++.h>
using namespace std;
int dis(string &s1, string &s2, int n, int m)
{   cout << "p"; 
    if (m==0)
    return n;
    if (n==0)
    return m;
    if (s1[n-1]==s2[m-1])
    return dis(s1, s2, n-1, m-1);
    int res=INT_MAX;
    // insert operation;
    res=min(res, dis(s1, s2, n, m-1));
    // delete operation;
    res=min(res, dis(s1, s2, n-1, m));
    // replace operation;
    res=min(res, dis(s1, s2, n-1, m-1));
    return res+1;
}
int main(){
    string s1="cat", s2="cut";
    cout << dis(s1, s2, s1.size(), s2.size());
    return 0;
}