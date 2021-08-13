#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(n+2, 1), suf(n+2, 1);
        for (int i=0;i<n;i++){
            pre[i+1]=pre[i]*arr[i];
        }
        for (int i=n-1;i>=0;i--){
            suf[i+1]=suf[i+2]*arr[i];
        }
        vector<int> ans(n);
        for (int i=1;i<=n;i++){
            ans[i-1]=pre[i-1]*suf[i+1];
        }
        return ans;
    }
/*
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long> ans(n, 1);
       if (n==1)
       return ans;
        ans[n-1]=nums[n-1];
        for (int i=n-2;i>=0;i--){
            ans[i]=nums[i]*ans[i+1];
        }
        long long temp=1;
        for (int i=0;i<n;i++){
            if (i==n-1)
            ans[i]=temp;
            else{
                ans[i]=temp*ans[i+1];
            }
            temp*=nums[i];
        }
        return ans;
    }
*/
int main(){
    vector<int> nums={1,2,3,4};
    auto v=productExceptSelf(nums);
    for (auto i:v)
    cout << i << " ";

    return 0;
}