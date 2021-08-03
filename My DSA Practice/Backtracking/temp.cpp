#include <bits/stdc++.h>
using namespace std;
bool safe(int i, int j, vector<int> maze[]){
    int n=maze[0].size();
    return (i<n && j<n && maze[i][j]!=0);
}
void print(vector<vector<int>> arr){
    for (int i=0;i<arr.size();i++)
    {
        for (int j=0;j<arr.size();j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool fun(int i, int j, vector<int> maze[], vector<vector<int>> &ans, int n){
    // cout << "p";
    if (i==n-1 && j==n-1){
        ans[i][j]=1;
        return true;
    }
    int steps=maze[i][j];
    ans[i][j]=1;
    for(int col=j+1;col < n && col<=j+steps;col++){
        if (safe(i, col, maze))
        {
            if (fun(i, col, maze, ans, n))
            return true;
        }
    }
    for (int row=i+1;row<n && row<=i+steps;row++)
    {
        if (safe(row, j, maze))
        {
            if (fun(row, j, maze, ans, n))
            return true;
        }
    }
    ans[i][j]=0;
    return false;
}
void solve(int N, vector<int> maze[]) 
{
    vector<vector<int>> ans;
    for (int i=0;i<N;i++){
        vector<int> temp;
        for (int j=0;j<N;j++)
        temp.push_back(0);
        ans.push_back(temp);
    }
    if (maze[0][0]==0)
    {
        cout << "-1";
        return;
    }
    bool flag=fun(0, 0, maze, ans, N);
    if (!flag){
        cout << "-1";
        return;
    }
    print(ans);
}
int main(){
    vector<int> maze[]={ { 2, 1, 0, 0 },
					{ 2, 0, 0, 1 },
					{ 0, 1, 0, 1 },
					{ 0, 0, 0, 1 } };
    solve(4, maze);
    return 0;
}