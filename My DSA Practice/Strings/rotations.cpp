#include <iostream>
#include <string>
using namespace std;
bool rot(string &s1, string &s2){ // O(n^2).
    if (s1==s2)
    return true;
    for (int i=0;i<s2.size()-1;i++){
        char temp=s2[0];
        int j;
        for (j=0;j<s2.size()-1;j++){
            s2[j]=s2[j+1];
        }
        s2[j]=temp;
        // cout << s2 << " ";
        if (s1==s2)
        return true;
    }
    return false;
}
bool rot1(string &s1, string &s2){ // O(n).
    if (s1.size() != s2.size()) return false;
    return ((s1+s1).find(s2)!=string :: npos);
}
int main(){
    string s1="abab", s2="abba";
    cout << rot1(s1, s2);
    return 0;
}