#include <iostream>
#include <string>
using namespace std;
bool palin(string s){
    int i=0, j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])
        return false;
        i++; j--;
    }
    return true;
}
int main(){
    string str="gfhg";
    cout << palin(str);
    return 0;
}