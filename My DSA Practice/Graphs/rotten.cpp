#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
    int n, m;
    bool **visited;
    public:
    //Function to find minimum time required to rot all oranges. 
    bool fun(int i, int j, vector<vector<int>>& grid){
        if (i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j]==0 || grid[i][j]==2)
        return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited=new bool*[n];
        for (int i=0;i<n;i++)
        visited[i]=new bool[m];
        
        queue<pair<pair<int, int>, int>> q;
        int count=0;
        for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            visited[i][j]=false;
            if (grid[i][j]==2)
            q.push({{i, j}, 0});
            if (grid[i][j]==1)
            count++;
        }    
        }
        int ans=0;
        while(q.empty()==false){
            auto curr=q.front();
            q.pop();
            int first=curr.first.first, second=curr.first.second;
            int prev=curr.second;
            ans=max(ans, prev);
            if (fun(first-1, second, grid)){
                count--;
                visited[first-1][second]=true;
            q.push({{first-1, second}, prev+1});
            }
            
            if (fun(first, second-1, grid)){
                count--;
                visited[first][second-1]=true;
            q.push({{first, second-1}, prev+1});
            }
            
            if (fun(first+1, second, grid)){
                count--;
                visited[first+1][second]=true;
            q.push({{first+1, second}, prev+1});
            }
            
            if (fun(first, second+1, grid)){
                count--;
                visited[first][second+1]=true;
            q.push({{first, second+1}, prev+1});
            }
            
        }
        if (count==0)
        return ans;
        return -1;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid={
        {0, 1, 2},
        {0 ,1, 2},
        {2, 1, 1}
    };
    cout << s.orangesRotting(grid);
    return 0;
}