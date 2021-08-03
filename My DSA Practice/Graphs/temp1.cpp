#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int n;
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool fun(int i, int j){
	    return (i>=0 && j>=0 && i<n && j<n);
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        n=grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        int ans[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
            ans[i][j]=INT_MAX;
        }
        int dx[]={1,-1,0,0};
        int ex[]={0, 0, 1, -1};
        while(pq.empty()==false){
            int ti=pq.top().second.first;
            int tj=pq.top().second.second;
            int dist=pq.top().first;
            ans[ti][tj]=dist;
            pq.pop();

            while(pq.empty()==false && ans[pq.top().second.first][pq.top().second.second]<pq.top().first)
            pq.pop();
            
            for (int i=0;i<4;i++){
                if (fun(ti+dx[i], tj+ex[i]) && ans[ti+dx[i]][tj+ex[i]]>dist+grid[ti+dx[i]][tj+ex[i]]){
                    pq.push({dist+grid[ti+dx[i]][tj+ex[i]], {ti+dx[i], tj+ex[i]}});
                }
            }
        }
        return ans[n-1][n-1];
    }
};
int main(){
    Solution s1;
    vector<vector<int>> grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}};
    cout << s1.minimumCostPath(grid);
    return 0;
}