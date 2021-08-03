#include <bits/stdc++.h>
using namespace std;
void rev(queue<int> &q){
    stack<int> st;
    while(q.empty()==false){
        st.push(q.front());
        q.pop();
    }
    while(st.empty()==false){
        q.push(st.top());
        st.pop();
    }
}
void rev1(queue<int> &q){
    if (q.empty())
    return;
    int c=q.front();
    q.pop();
    rev1(q);
    q.push(c);
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    rev1(q);
    while(q.empty()==false){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}