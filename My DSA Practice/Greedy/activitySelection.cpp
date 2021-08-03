#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int output(vector<pair<int, int>> &adj){
    sort(adj.begin(), adj.end(), [&](pair<int, int> p1, pair<int, int> p2){
        if (p1.second==p2.second)
        return p1.first<p2.first;
        else
        return p1.second<p2.second;
    });
    int res=1, ind=0;
    for (int i=1;i<adj.size();i++){
        if (adj[i].first>=adj[res].second){
            res++;
            ind=i;
        }
    }
    return res;
}
int main(){
    vector<pair<int, int>> v={make_pair(2, 3), make_pair(1, 4), make_pair(5, 8), make_pair(6,10)};
    cout << output(v);

    return 0;
}