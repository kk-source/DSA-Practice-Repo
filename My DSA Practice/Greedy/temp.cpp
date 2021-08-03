#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
    void insert(vector<int> adj[], int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void fun(vector<int> adj[], long long &ans, int n, int src){
        // cout << "p";
        if (n==0 && src==0){
            ans++;
            return;
        }
        else if (n<=0)
        return;
        for (auto i:adj[src]){
            fun(adj, ans, n-1, i);
        }
    }
    int countPaths(int N){
        long long ans=0;
        vector<int> adj[4];
        insert(adj, 0, 1);
        insert(adj, 0, 2);
        insert(adj, 0, 3);
        insert(adj, 2, 3);
        insert(adj, 2, 1);
        insert(adj, 3, 1);
        fun(adj, ans, N, 0);
        int mod=1e9+7;
        return ans%(mod);
    }
};
int main(){
    Solution s1;
    cout << s1.countPaths(1);
    return 0;
}