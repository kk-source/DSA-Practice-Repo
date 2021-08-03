#include <bits/stdc++.h>
using namespace std;
#define c 26
int longestUniqueSubsttr(string str){
        vector<int> temp(26, -1);
        int n=str.size();
        int res=0;
        int i=0;
        for (int j=0;j<n;j++){
            i=max(i, temp[str[j]-'a']+1);
            res=max(res, j-i+1);
            temp[str[j]-'a']=j;
        }
        return res;
    }
int main(){
    string str="geeksforgeeks";
    cout << longestUniqueSubsttr(str);
    return 0;
}