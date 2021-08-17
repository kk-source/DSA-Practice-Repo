#include <iostream>
#include <string>
using namespace std;
const int CHAR=256;
LmostNon(string &str){ // two traversals.
    int count[CHAR]={0};
    for (int i=0;i<str.size();i++){
        count[str[i]]++;
    }
    for (int i=0;i<str.size();i++){
        if (count[str[i]]==1)
        return i;
    }
    return -1;
}
LmostNon1(string &str){ // one traversal.
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    
    for(int i=0;i<str.length();i++){
        if(fI[str[i]]==-1)
        fI[str[i]]=i;
        else
        fI[str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++)
        if(fI[i]>=0)res=min(res,fI[i]);
    
    return (res==INT_MAX)?-1:res;
}
int main(){
    string str="abcabc";
    // string str="geeksforgeeks";
    // string str="apple";
    cout << LmostNon1(str);
    return 0;
}