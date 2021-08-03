#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> adj[], int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void dfs(vector<int> adj[], int &ind, unordered_set<int> &st, int src, int disc[], int low[], vector<int> ans[], int p=-1){
    disc[src]=low[src]=ind++;
    st.insert(src);
    for (auto i:adj[src]){
        if (i==p)
        continue;
        if (st.find(i)==st.end()){
            ans[src].push_back(i);
            dfs(adj, ind, st, i, disc, low, ans, src);
            low[src]=min(low[src], low[i]);
        }
        else{
            low[src]=min(low[src], disc[i]);
        }
    }
}
int bridges(vector<int> adj[], int n){
    int ind=1;
    unordered_set<int> st;
    int disc[n], low[n];
    vector<int> ans[n];
    dfs(adj, ind, st, 0, disc, low, ans);
    int count=0;
    for (int i=0;i<n;i++){
        for (auto j:ans[i]){
            if (low[j]>disc[i]){
                cout << i << " " << j << endl;
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n=5;
    vector<int> adj[n];
    insert(adj, 0, 2);
    insert(adj, 0, 1);
    insert(adj, 1, 2);
    insert(adj, 1, 3);
    insert(adj, 4, 3);
    cout << bridges(adj,n);
    return 0;
}