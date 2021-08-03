#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> v[], int i, int j){
    v[i].push_back(j);
    v[j].push_back(i);
}
void adjacent(vector<int> v[], int n, int src, unordered_set<int> &st){
    // unordered_set<int> st;
    queue<int> q;
    q.push(src);
    st.insert(src);
    while(q.empty()==false){
        int front=q.front();
        q.pop();
            // cout << front << " ";
        for (auto i:v[front]){
            if (st.find(i)==st.end()){
            q.push(i);
            st.insert(i);
            }
        }
    }
}
void BSTdis(vector<int> v[], int n){
    unordered_set<int> st;
    for (int i=0;i<n;i++){
        if (st.find(i)==st.end())
        adjacent(v, n, i, st);
    }
}
int count(vector<int> v[], int n){
    unordered_set<int> st;
    int ans=0;
    for (int i=0;i<n;i++){
        if (st.find(i)==st.end()){
            ans++;
        adjacent(v, n, i, st);
        }
    }
    return ans;
}
int main(){
    int n=9;
    vector<int> v[n];
    // insert(v, 0, 1);
    // insert(v, 0, 2);
    // insert(v, 3, 2);
    // insert(v, 1, 3);
    // insert(v, 4, 5);
    // insert(v, 4, 6);
    // insert(v, 5, 6);
    
    insert(v, 0, 1);
    insert(v, 0, 2);
    insert(v, 1, 2);
    insert(v, 4, 3);
    insert(v, 6, 5);
    insert(v, 5, 7);
    insert(v, 8, 7);

    // BSTdis(v, n);
    cout << count(v, n);
    return 0;
}