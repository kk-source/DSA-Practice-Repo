#include <bits//stdc++.h>
using namespace std;
string print(string &str){
    int n=str.size();
    stack<char> s;
    string ans;
    for (int i=n-1;i>=0;i--){
        char c=str[i];
        if ((c<='z' && c>='a')){
        ans.push_back(c);
        }
        else if (c==')'){
        cout << "p";
        s.push(c);
        }
        else if (c=='('){
            while(s.top()!=')'){
                ans.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else{
            if (s.empty())
            s.push(c);
            else if (c=='+' || c=='-'){ // string's current character.
                    while (s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/' || s.top()=='^'){
                    ans.push_back(s.top());
                    s.pop();
                    }
            s.push(c);
            }
            else if (c=='*' || c=='/'){
                while(s.top()=='*' || s.top()=='/' || s.top()=='^'){
                    ans.push_back(s.top());
                    s.pop();
                }
            s.push(c);
            }
            else
                s.push(c);
        }
    }
    while(s.empty()==false){
        ans.push_back(s.top());
        // cout << s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    string str="x+y/z-w*u";
    cout << print(str);

    return 0;
}