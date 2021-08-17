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
// int fun1(string &s1, int i, int j){ // Longest Palin substring using recursion.
//     if (i>j)
//     return 0;
//     if (i==j)
//     return 1;
//     if (s1[i]==s1[j]){
//         int temp=fun1(s1, i+1, j-1);
//         if (temp==j-i-1)
//             return temp+2;
//         else    
//             return max(temp, max(fun1(s1, i+1, j), fun1(s1, i, j-1)));
//     }
//     else
//         return max(fun1(s1, i+1, j), fun1(s1, i, j-1));
// }
int main(){
    string S="aabbaaaa";
    cout << longestPalin(S);
    return 0;
}