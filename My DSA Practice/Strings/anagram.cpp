#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool anagram(string &s1, string &s2, int n, int m){
    if (m!=n)
    return false;
    for (int i=0;i<n;i++){
        int ind=s2.find(s1[i]);
        if (ind==string::npos)
        return false;
        swap(s2[m-1], s2[ind]);
        s2[m-1]='\0';
    }
    return true;
}
bool anagram1(string &s1, string &s2){
    if (s1.size()!=s2.size())
    return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1==s2);
}
bool anagram2(string &s1, string &s2){
    if (s1.size()!=s2.size())
    return false;
    int count1[26]={0};
    int count2[26]={0};
    for (int i=0;i<s1.size();i++){
        count1[s1[i]-'a']++;
        count2[s2[i]-'a']++;
    }
    for (int i=0;i<26;i++){
        if (count1[i]!=count2[i])
        return false;
    }
    return true;
}
int main(){
    string s1="aaacb", s2="cabaa";
    cout << anagram2(s1, s2);

    return 0;
}