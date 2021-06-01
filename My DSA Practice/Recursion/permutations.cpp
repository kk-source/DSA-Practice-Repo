#include <iostream>
#include <string>
using namespace std;
void perm(string s, string ans=""){
    if (s.size()==0){
        cout << ans << endl;
        return;
    }
    for (int i=0;i<s.size();i++){
        string tempstr=s;
        perm(tempstr.erase(i,1),ans+s[i]);
    }
}
void perm1(string s, int i=0){
    if (i==s.size()-1){ 
        cout << s << endl;
        return;
    }
    for (int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        perm1(s,i+1);
        swap(s[i],s[j]);
    }
}
int main(){
    string str="abc";
    perm1(str);
    return 0;
}