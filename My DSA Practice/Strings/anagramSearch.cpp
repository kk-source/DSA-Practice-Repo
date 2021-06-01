#include <bits/stdc++.h>
using namespace std;
const int CHAR=256;
bool anagram(string &txt, string &pat, int i){
    int count[CHAR]={0};
    for (int j=0;j<pat.size();j++){
        count[pat[j]]++;
        count[txt[i+j]]--;
    }
    for (int j=0;j<CHAR;j++){
        if (count[j]!=0)
        return false;
    }
    return true;
}
bool anaSearch(string &txt, string &pat){ // naive.
    int n=txt.size(), m=pat.size();
    for (int i=0;i<=n-m;i++){
        if (anagram(txt, pat, i))
        return true;
    }
    return false;
}
bool arrayCheck(int arr1[], int arr2[]){
    for (int i=0;i<CHAR;i++){
        if (arr1[i]!=arr2[i])
        return false;
    }
    return true;
}
bool anaSearch1(string &txt, string &pat){ // efficient O(n).
    int CT[CHAR]={0}, CP[CHAR]={0};
    int m=pat.size();
    for (int i=0;i<m;i++){
        CT[txt[i]]++;
        CP[pat[i]]++;
    }
    for (int i=0;i<=txt.size()-m;i++){
        if (arrayCheck(CT, CP))
        return true;
        CT[txt[i]]--;
        CT[txt[i+m]]++;
    }
    return false;
}
int main(){
    string txt="geeksforgeeks";
    string pat="frog";
    cout << anaSearch1(txt, pat);
    return 0;
}