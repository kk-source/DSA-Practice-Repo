#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// vector<pair<int, int>> =deadline, profit.
int output(vector<pair<int, int>> &adj){
    sort(adj.begin(), adj.end(), [&](pair<int, int> p1, pair<int, int> p2){
        if (p1.second==p2.second)
        return p1.first<p2.first;
        else
        return p1.second>p2.second;
    });
    int res=0;
    int maxval=0;
    for (int i=0;i<adj.size();i++){
        maxval=max(maxval, adj[i].first);
    }
    int temp[maxval];
    for (int i=0;i<maxval;i++)
    temp[i]=-1;

    for (int i=0;i<adj.size();i++){
        int j=adj[i].first-1;
        while(j>=0 && temp[j]!=-1)
        j--;
        if (j==-1)
        continue;
        else{
        temp[j]=adj[i].second;
        res+=adj[i].second;
        }
    }
    return res;
}
int main(){
    vector<pair<int, int>> v={make_pair(1, 1), make_pair(2, 1000), make_pair(2, 1000), make_pair(3, 500)};
    cout << output(v);

    return 0;
}