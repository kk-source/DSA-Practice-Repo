#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1; // for taking brakcets into account.
}
string infixToPostfix(string s)
    {
        stack<char> st;
    
    int l = s.length();
    
    string ns;
    
    for(int i = 0; i < l; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z')||
                (s[i] >= 'A' && s[i] <= 'Z'))
            ns.push_back(s[i]);
            
        else if(s[i] == '(')
        st.push('(');
        
        else if(s[i] == ')')
        {
            while(st.empty()==false && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                ns.push_back(c);
            }
                st.pop();
        }
        
        else{
            while(st.empty()==false && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns.push_back(c);
            }
            
            st.push(s[i]);
        }
    }
    
    while(st.empty()==false)
    {
        char c = st.top();
        st.pop();
        ns.push_back(c);
    }
    return ns;
    }

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    cout << infixToPostfix(exp);
    
    return 0;
}
