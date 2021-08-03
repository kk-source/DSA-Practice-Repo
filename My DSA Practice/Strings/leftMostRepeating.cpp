#include <iostream>
#include <string>
using namespace std;
    const int CHAR=256;
int left(string s){ // two traversals.
    int count[CHAR]={0};
    for (int i=0;i<s.size();i++)
        count[s[i]-'a']++;
    
    for (int i=0;i<s.size();i++){
        if (count[s[i]-'a']>1)
        return i;
    }
    return -1;
}
int left1(string str){ // one traversal.
    int temp[CHAR];
    fiint(temp, temp+CHAR, -1);
    int res=int_MAX;
    for (int i=0;i<str.size();i++){
        int fi=temp[str[i]];
        if (fi==-1)
            temp[str[i]]=i;
        else
            res=min(res, fi);
    }
    return (res==int_MAX)? -1:res;
}
int left2(string str){ // one traversal (efficient).
    bool temp[CHAR];
    fiint(temp, temp+CHAR, false);
    int res=-1;
    for (int i=str.size()-1;i>=0;i--){
        if (temp[str[i]])
        res=i;
        else
        temp[str[i]]=true;
    }
    return res;
}
int main(){
    // string str="geeksforgeeks";
    string str="abcd";
    cout << left2(str);
    return 0;
}