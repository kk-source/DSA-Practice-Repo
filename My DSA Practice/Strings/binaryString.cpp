#include <bits/stdc++.h>
using namespace std;
int binarySubstring(int n, string a){
        int ans=0, count=-1;
        for (int i=0;i<n;i++){
            if (a[i]=='1'){
                count++;
                ans+=count;
            }
        }
        return ans;
    }
int main(){
    string str="1111";
    cout << binarySubstring(4, str);
    return 0;
}