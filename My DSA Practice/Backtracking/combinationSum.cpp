#include <bits/stdc++.h>
using namespace std;
void fun(vector<vector<int>> &ans, int sum, vector<int> temp, int arr[], int n){
    if (sum==0){
        ans.push_back(temp);
        return;
    }
    for (int i=0;i<n;i++){
        if (sum>=arr[i]){
            if (temp.empty()==false && temp.back()>arr[i])
            continue;
            temp.push_back(arr[i]);
            fun(ans, sum-arr[i], temp, arr, n);
            temp.pop_back();
        }
    }
}
vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        set<int> st(A.begin(), A.end());
        int arr[st.size()];
        int ind=0;
        for(auto i:st){
            arr[ind++]=i;
        }
        vector<int> v;
        fun(ans, B, v, arr, st.size());
        return ans;
    }
int main(){
    vector<int> arr={6,5,7,1,8,2,9,9,7,7,9};
    vector<vector<int>> v= combinationSum(arr, 6);
    for (auto i:v){
        for (auto j:i)
        cout << j << " ";
    cout << endl;
    }
    return 0;
}