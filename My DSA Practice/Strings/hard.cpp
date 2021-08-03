#include <bits/stdc++.h>
using namespace std;
string smallestWindow (string s, string p)
    {
        int mp[256]={0};
        int count=0;
        for (int i=0;i<p.size();i++){
            if (mp[p[i]]==0)
            count++;
            mp[p[i]]++;
        }
        int i=0, j=0;
        int len=INT_MAX;
        int start=0;
        while(j<s.size()){
            mp[s[j]]--;
            if (mp[s[j]]==0)
            count--;
            if (count==0){
                while(count==0){
                    if (j-i+1<len){
                        len=j-i+1;
                        start=i;
                    }
                    mp[s[i]]++;
                    if (mp[s[i]]>0)
                    count++;
                    i++;
                }
            }
            j++;
        }
        if (len==INT_MAX)
        return "-1";
        return s.substr(start, len);
    }
int main(){
    smallestWindow("timetopractice", "toc");
    return 0;
}