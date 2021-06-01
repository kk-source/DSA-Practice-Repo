#include <iostream>
using namespace std;

void subset(string i, string j){
    if (i.size()==0){
    cout << j << endl;
    return;
    }
    subset(i.substr(1), j);
    subset(i.substr(1), j+i[0]);
}
void subset1(string s, string curr="", int i=0){
    if (s.size()==i){
    cout << curr << endl;
    return;
    }
    subset1(s,curr,i+1);
    subset1(s,curr+s[i],i+1);
}
int main(){
    subset("abc", "");
    subset1("abc");
    return 0;
}