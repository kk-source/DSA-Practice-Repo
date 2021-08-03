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
bool fun1(vector<int> v[], int n){ // bfs only for connected ones.
    unordered_set<int> st;
    int p=-1;
    queue<int> q;
    int src=0;
    q.push(src);
    while(q.empty()==false){
        int front=q.front();
        q.pop();
        for (auto i:v[front]){
            if (i==p)
            continue;
            else if (st.find(i)!=st.end())
            return true;
            else{
                q.push(i);
                st.insert(i);
            }
        }
        p=front;
    }
    return false;
}
bool fun(vector<int> v[], unordered_set<int> &st, int s=0, int p=-1){ // using dfs.
    if (st.find(s)!=st.end())
    return true;
    st.insert(s);
    for (auto i:v[s]){
        if (i==p)
        continue;
        bool flag=fun(v, st, i, s);
        if (flag==true)
        return true;

    }
    return false;
}
bool loop(vector<int> v[], int n){
    unordered_set<int> st;
    for (int i=0;i<n;i++){ // for taking disconnected graphs also in account.
        if (st.find(i)==st.end()){
            if (fun(v, st, i))
            return true;
        }
    }
    return false;
}
int main(){
    int n=4;
    vector<int> v[n];
    insert(v, 0, 1);
    insert(v, 3, 2);
    // insert(v, 3, 1);
    insert(v, 1, 3);
    insert(v, 1, 2);
    // insert(v, 5, 5);
    // insert(v, 4, 1);
    // insert(v, 4, 5);
    // insert(v, 5, 6);
    // print(v, n);
    // printDFSdis(v, n);
    cout << loop(v, n);
    return 0;
}