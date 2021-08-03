#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> v[], int i, int j){
    v[i].push_back(j);
    v[j].push_back(i);
}
void print(vector<int> v[], int n){
    for (int i=0;i<n;i++){
        for (auto j:v[i])
        cout << j << " ";
        cout << endl;
    }
}
void adjacent(vector<int> v[], int n, int src, unordered_set<int> &st){
    if (st.find(src)==st.end()){ // element not found.
        // cout << src << " ";
        st.insert(src);
    }
    else
    return;
    for (auto i:v[src]){
        adjacent(v, n, i, st);
    }
}
void printDFSdis(vector<int> v[], int n){
    unordered_set<int> st;
    for (int i=0;i<n;i++){
        if (st.find(i)==st.end()){
            adjacent(v, n, i, st);
        }
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
    int n=6;
    vector<int> v[n];
    insert(v, 0, 1);
    insert(v, 3, 2);
    insert(v, 2, 4);
    insert(v, 4, 3);
    insert(v, 5, 5);
    // insert(v, 4, 1);
    // insert(v, 4, 5);
    // insert(v, 5, 6);
    // print(v, n);
    // printDFSdis(v, n);
    cout << count(v, n);
    return 0;
}