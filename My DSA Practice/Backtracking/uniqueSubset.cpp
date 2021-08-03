#include <bits/stdc++.h>
using namespace std;
void fun(vector<int> &temp, int ind, set<vector<int>> &ans, vector<int> &arr){
            if (ind==arr.size()){
                ans.insert(temp);
                return;
            }
        fun(temp, ind+1, ans, arr);
        temp.push_back(arr[ind]);
        fun(temp, ind+1, ans, arr);
        temp.pop_back();
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        set<vector<int>> ans;
        vector<int> temp;
        fun(temp, 0, ans, arr);
        for (auto i:ans)
        res.push_back(i);
        return res;
    }
int main(){
    
    return 0;
}