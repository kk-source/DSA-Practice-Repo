#include <iostream>
#include <stack>
using namespace std;
bool matching(char a, char b){
    return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
}
bool paren(string &str){
    stack<char> s;
    for (int i=0;i<str.size();i++){
        if (str[i]=='(' || str[i]=='{' || str[i]=='[')
        s.push(str[i]);
        else{
            if (s.empty())
            return false;
            if (!matching(s.top(), str[i])){
            return false;
            }
            s.pop();
        }
    }
    return (s.empty()==true);
}
int main(){
    string str="(";
    cout << paren(str);
    return 0;
}