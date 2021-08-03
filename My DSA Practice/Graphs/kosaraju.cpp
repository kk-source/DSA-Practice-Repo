#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> adj[], int a, int b){
    adj[a].push_back(b);
}
void bfs(unordered_set<int> &st, stack<int> &s, int src, vector<int> adj[]){
	    // cout << src << " ";
        st.insert(src);
	    for (auto i:adj[src]){
            if (st.find(i)==st.end())
	        bfs(st, s, i, adj);
	    }
	    s.push(src);
	}
	void bfs1(unordered_set<int> &st, int src, vector<int> adj[]){
	    if (st.find(src)!=st.end())
	    return;
        cout << src << " ";
	    st.insert(src);
	    for (auto i:adj[src])
	    bfs1(st, i, adj);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s;
        unordered_set<int> st;
        for (int i=0;i<V;i++){
            if (st.find(i)==st.end())
            bfs(st, s, i, adj);
        }
        vector<int> temp[V];
        for (int i=0;i<V;i++){
            for (auto j:adj[i])
            temp[j].push_back(i);
        }
        unordered_set<int> st1;
        int ans=0;
        while(s.empty()==false){
            if (st1.find(s.top())==st1.end()){
            bfs1(st1, s.top(), temp);
            cout << endl;
            }
            s.pop();
        }
        return ans;
    }
int main(){
    int n=5;
    vector<int> adj[n];
    insert(adj, 0, 1);
    insert(adj, 1, 2);
    insert(adj, 2, 0);
    insert(adj, 1, 3);
    insert(adj, 3, 4);
    kosaraju(n, adj);
    return 0;
}