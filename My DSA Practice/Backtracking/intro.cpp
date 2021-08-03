#include <iostream>
#include <string>
using namespace std;
bool safe(string str, int l, int i){
    if (l!=0 && str[l-1]=='a' && str[i]=='b')
    return false;
    return true;
}
void perm(string str, int i=0){
    if (i==str.size()){
        cout << str << endl;
        return;
    }
    for (int j=i;j<str.size();j++){
        if (safe(str, i, j)){
        swap(str[i], str[j]);
        perm(str, i+1);
        swap(str[i], str[j]);
        }
    }
}
int main(){
    string str="abc";
    perm(str);

    return 0;
}