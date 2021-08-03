#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> adj[], int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
struct edge{
    int wt, l, r;
    edge(int a, int b, int c){
        wt=a; l=b; r=c;
    }
};
struct mycmp{
    bool operator()(edge const &e1, edge const &e2){
        return e1.wt>e2.wt;
    }
}
int kruskal(vector<int> adj[], int n){
    vector<edge> temp;
    unordered_set<int> st;
    queue<int> q;
    st.insert(0);
    q.push(0);
    while(q.empty()==false){
        int front=q.front();
        q.pop();
        
        for (auto i:adj[front]){
            if (st.find(i)==st.end()){
                q.push(i);
                st.insert(i);
            }
        }
    }
}
int main(){
    

    return 0;
}