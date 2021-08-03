#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(vector<vector<int>> &v, stack<int> &s, vector<int> adj[], int src, int &ind, int low[], int disc[], unordered_set<int> &st, unordered_set<int> st1){
        low[src]=disc[src]=ind++;
        st.insert(src);
        st1.insert(src);
        s.push(src);
        for (auto i:adj[src]){
            if (st.find(i)==st.end()){
            dfs(v, s, adj, i, ind, low, disc, st, st1);
                low[src]=min(low[src], low[i]);
            }
            else if (st1.find(i)!=st1.end()){
                low[src]=min(low[src], disc[i]);
            }
        }
        if (low[src]==disc[src]){
            vector<int> temp;
            while(s.top()!=src){
                temp.push_back(s.top());
                s.pop();
            }
            temp.push_back(s.top());
            s.pop();
            sort(temp.begin(), temp.end());
            v.push_back(temp);
        }
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        unordered_set<int> st, st1;
        int low[V], disc[V];
        stack<int> s;
        int ind=1;
        vector<vector<int>> ans;
        for (int i=0;i<V;i++){
            if (st.find(i)==st.end())
            dfs(ans, s, adj, i, ind, low, disc, st, st1);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    vector<vector<int>> v={{8,7,6}, {4,5}, {1,2,3}};
    sort(v.begin(), v.end());
    for (auto i:v){
        for (auto j:i)
        cout << j << " ";
        cout << endl;
    }
    return 0;
}