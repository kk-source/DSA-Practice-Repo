#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int aux(vector<int> arr){
    int ans=0;
    int n=arr.size();
    stack<int> s;
    for (int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i]){
            int temp=s.top();
            s.pop();
            int curr=arr[temp]*(s.empty()? i:i-s.top()-1);
            ans=max(ans, curr);
        }
        s.push(i);
    }
    while(s.empty()==false){
        int temp=s.top();
        s.pop();
        int curr=arr[temp]*(s.empty()? n:n-s.top()-1);
        ans=max(ans, curr);
    }
    return ans;
}
int maxmat(vector<vector<int>> v){
    int r=v.size(), c=v[0].size();
    int curr=aux(v[0]);
    for (int i=1;i<r;i++){
        for (int j=0;j<c;j++){
            if (v[i][j]==1){
                v[i][j]+=v[i-1][j];
            }
        }
        curr=max(curr, aux(v[i]));
    }
    return curr;
}
int main(){
    vector<vector<int>> v={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    cout << maxmat(v);
    return 0;
}