#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> v[], int i, int j){
    v[i].push_back(j);
    v[j].push_back(i);
}
void print(vector<int> v[], int n){
    // cout << v.size();
    for (int i=0;i<n;i++){
        for (auto j:v[i])
        cout << j << " ";
        cout << endl;
    }
}
void adjacent(vector<int> v[], int n, int src){
    unordered_set<int> st;
    queue<int> q;
    q.push(src);
    st.insert(src);
    while(q.empty()==false){
        int front=q.front();
        q.pop();
            cout << front << " ";
            // st.insert(front);
        for (auto i:v[front]){
            if (st.find(i)==st.end()){
            q.push(i);
            st.insert(i);
            }
        }
    }
}
int main(){
    int n=6;
    vector<int> v[n];
    insert(v, 0, 1);
    insert(v, 0, 2);
    insert(v, 0, 5);
    insert(v, 2, 4);
    insert(v, 1, 3);
    insert(v, 5, 3);
    insert(v, 4, 5);
    // print(v, 5);
    adjacent(v, n, 0);
    return 0;
}