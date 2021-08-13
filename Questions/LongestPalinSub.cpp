#include <bits/stdc++.h>
using namespace std;
string longestPalin (string S) {
        int n=S.size();
        int len=0;
        int start;
        for (int i=0;i<n;i++){
            for (int x=0;i-x>=0 && i+x<n;x++){
                if (S[i-x]!=S[i+x])
                break;
                int clen=2*x+1;
                if (clen>len){
                    len=clen;
                    start=i-x;
                }
            }
            for (int x=0;i-x>=0 && i+x+1<n;x++){
                if (S[i-x]!=S[i+x+1])
                break;
                int clen=2*(x+1);
                if (clen>len){
                    len=clen;
                    start=i-x;
                }
            }
        }
        return S.substr(start, len);
    }
int main(){
    string S="aabbaaaa";
    cout << longestPalin(S);
    return 0;
}