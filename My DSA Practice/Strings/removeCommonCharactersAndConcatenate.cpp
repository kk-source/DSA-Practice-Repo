#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256
void concatenatedString(string s1, string s2) 
    { 
        string ans;
        vector<int> v(256);
        for (int i=0;i<s2.size();i++){
            v[s2[i]]++;
        }
        for (int i=0;i<s1.size();i++){
            if (v[s1[i]]==0)
            ans.push_back(s1[i]);
        }
        vector<int> v1(256);
        for (int i=0;i<s1.size();i++){
            v1[s1[i]]++;
        }
        for (int i=0;i<s2.size();i++){
            if (v1[s2[i]]==0)
            ans.push_back(s2[i]);
        }
        cout << ans;
    }
int main(){
    string s1="aacdb";
    string s2="gafd";
    concatenatedString(s1, s2);
    return 0;
}