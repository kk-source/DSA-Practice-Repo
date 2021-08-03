#include <bits/stdc++.h> 
using namespace std; 
#define d 256
const int q=101;
void RBSearch(string &pat,string &txt,int M, int N){
    
    //Compute (d^(M-1))%q
    int h=1;
    for(int i=1;i<=M-1;i++)
        h=(h*d)%q;
    
    //Compute p and t
    int p=0,t=0;
    for(int i=0;i<M;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
    
    for(int i=0;i<=(N-M);i++){
       //Check for hit
       if(p==t){
           int j;
           for(j=0;j<M;j++)
                if(txt[i+j]!=pat[j]) break;
            if(j==M)cout<<i<<" ";
       }
       //Compute ti+1 using ti
       if(i<N-M){
           t=((d*(t-txt[i]*h))+txt[i+M])%q;
        if(t<0)t=t+q;
       }
    }
    
}
 
int main() 
{ 
    // string txt = "GEEKS FOR GEEKS";string pat="GEEK";
    string txt="abcabcd";
    string pat="abcd";
    cout<<"Aint index numbers where pattern found:"<<" ";
    RBSearch(pat,txt,pat.size(),txt.size());
    
    return 0; 
} 