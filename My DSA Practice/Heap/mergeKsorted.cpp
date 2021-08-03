#include <bits/stdc++.h>
using namespace std;
class myclass{
    public:
    int val, pos, ind;
    myclass(int a, int b, int c){
        val=a;
        pos=b;
        ind=c;
    }
};
struct mycmp{
    bool operator()(myclass& m1, myclass& m2){
        return (m1.val>m2.val);
    }
};
vector<int> fun1(vector<vector<int>> &v){
    priority_queue<myclass, vector<myclass>, mycmp> pq;
    int k=v.size();
    for (int i=0;i<k;i++){
        pq.push(myclass(v[i][0], i, 0));
    }
    vector<int> ans;
    while(pq.empty()==false){
        auto temp=pq.top();
        pq.pop();
        cout << temp.val << " ";
        ans.push_back(temp.val);
        if (temp.ind<v[temp.pos].size()-1){
            // cout << "p";
            pq.push(myclass(v[temp.pos][temp.ind+1], temp.pos, temp.ind+1));
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> v={{10, 20}, 
                            {5, 15},
                            {4,9,11}};
    vector<int> ans=fun1(v);
    // for (auto i:ans)
    // cout << i << " ";
    return 0;
}