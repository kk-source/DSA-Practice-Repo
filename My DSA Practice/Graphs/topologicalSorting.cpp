#include <bits/stdc++.h>
using namespace std;
// for directed graphs.
void insert(vector<int> v[], int i, int j){
    v[i].push_back(j);
}
void print(vector<int> v[], int n){
    for (int i=0;i<n;i++){
        for (auto j:v[i])
        cout << j << " ";
        cout << endl;
    }
}
void topo(vector<int> v[], int n){ // BFS and Kahn's algo.
    unordered_map<int, int> mp;
    for (int i=0;i<n;i++){
        for (auto j:v[i]){
            mp[j]++;
        }
    }
    // for (auto i:mp)
    // cout << i.first << " " << i.second << endl;
    queue<int> q;
    for (int i=0;i<n;i++){
        if (mp[i]==0)
        q.push(i);
    }
    while(q.empty()==false){
        int front=q.front();
        q.pop();
        cout << front << " ";
        for (auto j:v[front]){
        mp[j]--;
        if (mp[j]==0)
        q.push(j);
        }
    }
}
void dfs(vector<int> v[], int src, unordered_set<int> &st, stack<int> &ans){
    if (st.find(src)!=st.end())
    return;
    st.insert(src);
    for (auto i:v[src]){
        dfs(v, i, st, ans);
    }
    ans.push(src);
}
void topo1(vector<int> v[], int n){
    unordered_set<int> st;
    stack<int> ans;
    for (int i=0;i<n;i++){
        if (st.find(i)==st.end()){
            dfs(v, i, st, ans);
        }
    }
    while(ans.empty()==false){
        cout << ans.top() << " ";
        ans.pop();
    }
}
bool loop(vector<int> v[], int n){
    unordered_map<int, int> mp;
    for (int i=0;i<n;i++){
        for (auto j:v[i])
        mp[j]++;
    }
    queue<int> q;
    int count=0;
    for (int i=0;i<n;i++){
        if (mp[i]==0)
        q.push(i);
    }
    while(q.empty()==false){
        int front=q.front();
        q.pop();
        count++;
        for (auto j:v[front]){
            mp[j]--;
            if (mp[j]==0)
            q.push(j);
        }
    }
    return (count!=n);
}
int main(){
    int n=5;
    vector<int> v[n];
    insert(v, 0, 1);
    insert(v, 1, 3);
    insert(v, 0, 2);
    insert(v, 3, 4);
    insert(v, 2, 4);
    // insert(v, 1, 4);
    // insert(v, 3, 4);
    // insert(v, 3, 5);
    // insert(v, 4, 1);
    // insert(v, 4, 5);
    // cout << loop(v, n);
    // print(v, n);
    // cout << loop(v, n);
    topo1(v, n);
    return 0;
}