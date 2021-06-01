#include <iostream>
#include <string>
using namespace std;
// naive.
int longPropPreSuff(string &str, int n){ // O(n^3)
    for(int len=n-1;len>0;len--){
        bool flag=true;
        for(int i=0;i<len;i++)
            if(str[i]!=str[n-len+i]){
                flag=false;
                break;
            }
                
        if(flag==true)
            return len;
    }
    return 0;
}

void fillLPS(string &str, int *lps){
    for(int i=0;i<str.length();i++){
        lps[i]=longPropPreSuff(str,i+1);
    }
}

void LPS(string str, int *lps){ // O(n^2)
    int index=0;
    for (int i=0;i<str.size();i++){
        int start=i-1, end=i;
        int count=0;
        while(true){
        while(str[start]!=str[end] && start>=0)
            start--;
        while(str[start]==str[end]){
            count++;
            start--;
            end--;
        }
        if (start>0){
            count=0;
            end=i;
        }
        else 
            break;
        }
        lps[index++]=count;
    }
}
//Efficient.
void fillLPS1(string &str, int *lps){ // O(n)
    int n=str.length(),len=0;
    lps[0]=0;
    int i=1;
    while(i<n){
        if(str[i]==str[len])
        {len++;lps[i]=len;i++;}
        else
        {if(len==0){lps[i]=0;i++;}
            else{len=lps[len-1];}
        }
    }
}
void KMP(string &txt, string &pat){
    int n=txt.size(), m=pat.size();
    int lps[m];
    fillLPS1(pat, lps);
    int i=0, j=0;
    while(i<n){
        if (txt[i]==pat[j]){
            i++; j++;
        }
        if (j==m){
            cout << i-m << " ";
            j=lps[j-1];
        }
        else if (i<n && txt[i]!=pat[j]){
            if (j==0)
                i++;
            else
            j=lps[j-1];
        }
    }
}
int main(){
    string str="adsgwadsxdsgwadsgz";
    string pat="dsgwadsgz";
    int lps[str.size()];
    KMP(str, pat);
    return 0;
}