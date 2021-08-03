#include <bits/stdc++.h>
using namespace std;
bool ispar(string x)
    {
        int n=x.size();
        stack<char> s;
        for (int i=0;i<n;i++){
            if (x[i]=='(' || x[i]=='[' || x[i]=='{'){
                s.push(x[i]);
            }
            else{
                if (s.empty()==true)
                return false;
                else if ((s.top()=='(' && x[i]==')') || (s.top()=='{' && x[i]=='}') || (s.top()=='[' && x[i]==']'))
                s.pop();
                else
                return false;
            }
        }
        return (s.empty()==true);
    }
int main(){
    string str="{([])}";
    cout << ispar(str);
    return 0;
}