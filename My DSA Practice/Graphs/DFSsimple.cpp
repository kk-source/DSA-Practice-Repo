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
void adjacent(vector<int> v[], int n, int src, unordered_set<int> &st){
    if (st.find(src)==st.end()){
        cout << src << " ";
        st.insert(src);
    }
    else
    return;
    for (auto i:v[src]){
        adjacent(v, n, i, st);
    }
}
int main(){
    int n=6;
    vector<int> v[n];
    insert(v, 0, 1);
    insert(v, 0, 2);
    insert(v, 3, 1);
    insert(v, 2, 3);
    insert(v, 4, 1);
    insert(v, 4, 5);
    // insert(v, 5, 6);
    // print(v, n);
    unordered_set<int> st;
    adjacent(v, n, 0, st);
    return 0;
}