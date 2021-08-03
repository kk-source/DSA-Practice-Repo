#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    bool **visited;
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool fun(int i, int j, int n){
        if (i<0 || j<0 || i>=n || j>=n || visited[i][j])
        return false;
        visited[i][j]=true;
        return true;
    }
	int minStepToReachTarget(vector<int>&Kpos,vector<int>&Tpos,int n)
	{
        Kpos[0]--; Kpos[1]--;
        Tpos[0]--; Tpos[1]--;
	    visited=new bool* [n];
	    for (int i=0;i<n;i++)
	    visited[i]=new bool[n];
	    for (int i=0;i<n;i++){
	        for (int j=0;j<n;j++){
	            visited[i][j]=false;
	        }
	    }
	    queue<pair<pair<int, int>, int>> q;
	    q.push({{Kpos[0],Kpos[1]}, 0});
	    visited[Kpos[0]][Kpos[1]]=true;
	    int ans=INT_MAX;
	    while(q.empty()==false){
	        int x=q.front().first.first, y=q.front().first.second;
	        int dist=q.front().second;
	        q.pop();
	        if (x==Tpos[0] && y==Tpos[1]){
                return dist;
	        }
	        
	        if (fun(x+2, y+1, n))
	            q.push({{x+2, y+1}, dist+1});
	            
	        if (fun(x-2, y+1, n))
	            q.push({{x-2, y+1}, dist+1});
	            
	        if (fun(x+1, y+2, n))
	            q.push({{x+1, y+2}, dist+1});
	            
	        if (fun(x+1, y-2, n))
	            q.push({{x+1, y-2}, dist+1});
	            
	        if (fun(x+2, y-1, n))
	            q.push({{x+2, y-1}, dist+1});
	            
	        if (fun(x-2, y-1, n))
	            q.push({{x-2, y-1}, dist+1});
	            
	        if (fun(x-1, y+2, n))
	            q.push({{x-1, y+2}, dist+1});
	            
	        if (fun(x-1, y-2, n))
	            q.push({{x-1, y-2}, dist+1});
	            
	    }
	}
};
int main(){
    int n=6;
    vector<int> a1={4,5};
    vector<int> a2={1,1};
    Solution s1;
    cout << s1.minStepToReachTarget(a1, a2, n);
    return 0;
}