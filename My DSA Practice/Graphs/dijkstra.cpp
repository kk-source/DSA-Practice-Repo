#include <bits/stdc++.h>
using namespace std;
// vector<int> dij(vector<vector<int>> adj, int s){
//     vector<int> ans(adj.size(), INT_MAX);
//     ans[s]=0;
//     vector<bool> found(adj.size(), false);
//     for (int count=0;count<adj.size();count++){
//         int u=-1;
//         for (int i=0;i<adj.size();i++){
//             if (!found[i] && (u==-1 || ans[u]>ans[i]))
//             u=i;
//         }
//         found[u]=true;
//         for (int i=0;i<adj.size();i++){
//             if (adj[u][i]!=0 && ans[i]>adj[u][i]+ans[u])
//             ans[i]=adj[u][i]+ans[u];
//         }
//     }
//     return ans;
// }

// /*
vector <int> dij(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V, INT_MAX);
        // ans[S]=0;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, S));
        while(pq.empty()==false){
            int dist=pq.top().first;
            int e=pq.top().second;
            ans[e]=dist;
            pq.pop();

            while(pq.empty()==false && ans[pq.top().second]<pq.top().first) // for removing duplicates.
            pq.pop();

            for (int i=0;i<adj[e].size();i++){
                if (ans[adj[e][i][0]]>dist+adj[e][i][1]){
                    // ans[adj[e][i][0]]=dist+adj[e][i][1];
                pq.push({dist+adj[e][i][1], adj[e][i][0]});
                }
            }
        }
        return ans;
    }
// */
vector <int> dij1(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V, INT_MAX);
        ans[S]=0;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, S));
        while(pq.empty()==false){
            int dist=pq.top().first;
            int s=pq.top().second;
            pq.pop();
            for (int i=0;i<adj[s].size();i++){
                if (ans[adj[s][i][0]]>dist+adj[s][i][1]){
                ans[adj[s][i][0]]=dist+adj[s][i][1];
                pq.push(make_pair(dist+adj[s][i][1], adj[s][i][0]));
                }
            }
        }
        return ans;
    }
int main(){
    int n=9;
    vector<vector<int>> adj[n];
    adj[0]={{1,4}, {2, 8}};
    adj[1]={{0,4}, {2,11}, {3, 8}};
    adj[2]={{0,8}, {1,11}, {4, 7}, {5,1}};
    adj[3]={{1,8}, {4, 2}, {7, 4}, {6, 7}};
    adj[4]={{2,7}, {3, 2}, {5, 6}};
    adj[5]={{2,1}, {4, 6}, {7, 2}};
    adj[6]={{3,7}, {7, 14}, {8, 9}};
    adj[7]={{3,4}, {5, 2}, {6, 14}, {8, 10}};
    adj[8]={{7,10}, {6, 9}};
    vector<int> tmp=dij(n, adj, 0);
    for (auto i: tmp)
    cout << i << ' ';
    return 0;
}