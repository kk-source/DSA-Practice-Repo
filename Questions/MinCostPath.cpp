#include<bits/stdc++.h>
using namespace std;

int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>> v(grid.size(), vector<int>(grid.size(), INT_MAX));
        v[0][0]=grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        while(pq.empty()==false){
            auto temp=pq.top(); pq.pop();
            int dist=temp.first, i=temp.second.first, j=temp.second.second;
            if (j-1>=0){
                if (v[i][j-1]>grid[i][j-1]+dist){
                    v[i][j-1]=grid[i][j-1]+dist;
                    pq.push({v[i][j-1], {i, j-1}});
                }
            }
            if (j+1<n){
                if (v[i][j+1]>grid[i][j+1]+dist){
                    v[i][j+1]=grid[i][j+1]+dist;
                    pq.push({v[i][j+1], {i, j+1}});
                }
            }
            if (i-1>=0){
                if (v[i-1][j]>grid[i-1][j]+dist){
                    v[i-1][j]=grid[i-1][j]+dist;
                    pq.push({v[i-1][j], {i-1, j}});
                }
            }
            if (i+1<n){
                if (v[i+1][j]>grid[i+1][j]+dist){
                    v[i+1][j]=grid[i+1][j]+dist;
                    pq.push({v[i+1][j], {i+1, j}});
                }
            }
        }
        return v[n-1][n-1];
    }

int main(){
	vector<vector<int>> v={{9,4,9,9},{6,7,6,4},
                        {8,3,3,7},{7,4,9,10}};
    cout << minimumCostPath(v);
	return 0;
}