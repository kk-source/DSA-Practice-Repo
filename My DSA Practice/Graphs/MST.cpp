int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        unordered_set<int> st;
        st.insert(0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int s=0;
        while(st.size()!=V){
            for (int i=0;i<adj[s].size();i++){
                if (st.find(adj[s][i][0])==st.end())
                pq.push({adj[s][i][1], adj[s][i][0]});
            }
            while(st.find(pq.top().second)!=st.end())
            pq.pop();
            ans+=pq.top().first;
            st.insert(pq.top().second);
            s=pq.top().second;
            pq.pop();
        }
        return ans;
    }