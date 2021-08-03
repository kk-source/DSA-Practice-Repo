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
void fun(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &st){
        int n=grid.size(), m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m|| st[i][j]==true || grid[i][j]=='0')
        return;
        st[i][j]=true;
        fun(i, j+1, grid, st);

        fun(i+1, j+1, grid, st);

        fun(i+1, j, grid, st);

        fun(i+1, j-1, grid, st);

        fun(i, j-1, grid, st);

        fun(i-1, j-1, grid, st);
        
        fun(i-1, j, grid, st);

        fun(i-1, j+1, grid, st);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        vector<vector<bool>> st;
        int m=grid[0].size(), n=grid.size();
        for (int i=0;i<n;i++){
            vector<bool> temp;
            for (int j=0;j<m;j++)
            temp.push_back(false);
            st.push_back(temp);
        }
        int ans=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
            if (grid[i][j]=='0')
            continue;
            else{
                if (st[i][j]==false){
                    ans++;
                fun(i, j, grid, st);
                }
            }
            }
        }
        return ans;
    }
int main(){

    vector<vector<char>> grid={{'1','0','0','0','0','1','0','0','0','1'}, 
                                {'1','0','1','1','1','1','1','0','0','1'}, 
                                {'1','1','1','1','1','0','0','0','1','0'},
                                {'1','1','1','0','1','0','0','1','0','1'},
                                {'0', '1', '0', '1' ,'0', '0', '0', '1', '0', '0'},
{'0' ,'0' ,'0' ,'0' ,'0' ,'1' ,'1' ,'1' ,'1', '0'},
{'0', '0', '1', '1', '0', '0', '0', '1', '0', '0'}};
    cout << numIslands(grid);
    return 0;
}