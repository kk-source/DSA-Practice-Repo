#include <bits/stdc++.h>
using namespace std;
int longest(int arr[], int n){ // naive
    sort(arr, arr+n);
    int ans=1, curr=1;
    for (int i=1;i<n;i++){
        if (arr[i]==arr[i-1]+1)
            curr++;
        else if (arr[i]!=arr[i-1]){
            ans=max(curr, ans);
            curr=1;
        }
    }
    return max(curr, ans);
}
int longest1(int arr[], int n){
    int res=0;
    unordered_set<int> h(arr, arr+n);
    for (auto x:h){
        if (h.find(x-1)==h.end()){
            int curr=1;
            while(h.find(x+curr)!=h.end())
            curr++;
            res=max(res, curr);
        }
    }
    return res;
}
int main(){
    int arr[]={1,3,9,2,8,2};
    int n=sizeof(arr)/4;
    cout << longest1(arr, n); 

    return 0;
}