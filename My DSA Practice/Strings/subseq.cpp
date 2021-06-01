#include <iostream>
#include <string>
using namespace std;
bool subseq(const string &s1, const string &s2){ // iterative.
    int j=0;
    for (int i=0;i<s1.size() && j<s2.size();i++)
    if(s1[i]==s2[j])
    j++;
    return (j==s2.size());
}
bool subseq1(const string &s1, const string &s2, int n, int m){ // recursive.
    if (m==0)
    return true;
    else if(n==0)
    return false;
    if (s1[n-1]==s2[m-1])
    return subseq1(s1, s2, n-1, m-1);
    return subseq1(s1, s2, n-1, m);
}
int main(){
    string s1="abcde", s2="ad";
    cout << subseq1(s1, s2, s1.size(), s2.size());
    return 0;
}