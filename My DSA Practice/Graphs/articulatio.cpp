#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> parent[], int src, vector<int> adj[], unordered_set<int> &st, int &ind, int disc[], int low[], int &child, int p=-1, bool flag=true){
    low[src]=disc[src]=ind++;
    st.insert(src);
    for (auto i:adj[src]){
        if (p==i)
        continue; 
        if (st.find(i)==st.end()){
            if (flag)
            child++;
            parent[src].push_back(i);
            dfs(parent, i, adj, st, ind, disc, low, child, src, false);
            low[src]=min(low[src], low[i]);
        }
        else{
            low[src]=min(low[src], disc[i]);
        }
    }
}
int arti(vector<int> adj[], int n){
    int ind=1;
    unordered_set<int> st;
    int low[n], disc[n];
    vector<int> parent[n];
    int child=0;
    int source=0;
    dfs(parent, source, adj, st, ind, disc, low, child);
    int count=0;
    for (int i=0;i<n;i++){
        if (i==source){
            if (child>1){
            cout << i << " ";
            count++;
            }
        continue;
        }
        for (auto j:parent[i]){
            if (low[j]>=disc[i]){
                cout << i << " ";
                count++;
                break;
            }
        }
    }
    cout << endl;
    return count;
}
void insert(vector<int> adj[], int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
int main(){
    int n=7;
    vector<int> adj[n];
    insert(adj, 1, 0);
    insert(adj, 2, 1);
    insert(adj, 2, 0);
    insert(adj, 1, 3);
    insert(adj, 1, 4);
    insert(adj, 1, 6);
    insert(adj, 3, 5);
    insert(adj, 4, 5);
    cout << arti (adj, n);
    return 0;
}