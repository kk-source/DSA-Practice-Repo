#include <bits/stdc++.h>
using namespace std;
int value(string &str){
    int n=str.size();
    stack <int> s;
    int i=0;
    while(i<n){
        if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            cout << "a " << a << " b " << b << endl;
            if (str[i]=='+')
            s.push(b+a);
            else if (str[i]=='-')
            s.push(b-a);
            else if (str[i]=='*')
            s.push(b*a);
            else if (str[i]=='/')
            s.push(b/a);
            else if (str[i]=='^')
            s.push(pow(b,a));
            i++;
            // cout << s.top() << " ";
        }
        else{
            string c;
            bool flag=false;
            while(str[i]!=' ' && i<n){
                flag=true;
                c.push_back(str[i]);
                i++;
            }
            if (flag){
                // cout << c << " ";
            int temp=stoi(c);
            s.push(temp);
            // i++;
            }
            if (i!=n)
            i++; 
        }
    }
    cout << endl;
    return s.top();
}

int main(){
    string ans="10 2 * 3 5 * + 9";
    cout << value(ans);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int evaluatePostfix(string S)
    {
        stack<int> st;
        for (int i=0;i<S.size();i++){
            if (S[i]>='0' && S[i]<='9'){
            st.push(S[i]-'0');
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                    int temp;
                switch(S[i]){
                    case '+':
                    temp=a+b;
                    break;
                    case '-':
                    temp=b-a;
                    break;
                    case '*':
                    temp=b*a;
                    break;
                    case '/':
                    temp=b/a;
                    break;
                }
                    st.push(temp);
            }
        }
        return st.top();
    }
int main(){
    string str="231*+9-";
    cout << evaluatePostfix(str);

    return 0;
}
*/