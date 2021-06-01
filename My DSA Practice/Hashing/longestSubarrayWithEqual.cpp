#include <bits/stdc++.h>
using namespace std;
int longest(int arr[], int n){ // naive.
    int res=0;
    for (int i=0;i<n;i++){
        int sum=0, curr=0;
        for (int j=i;j<n;j++){
            sum+=arr[j];
                if (sum*2==(j-i+1)){
                    curr=(j-i+1);
                    res=max(curr,res);
                }
        }
    }
    return res;
}
int longest1(int arr[], int n){
    int ans=0, psum=0;
    unordered_map<int, int> s;
    for (int i=0;i<n;i++){
        if (arr[i]==0)
        arr[i]=-1;
    }
    for (int i=0;i<n;i++){
        psum+=arr[i];
        if (psum==0)
        ans=i+1;
        if (s.find(psum)==s.end())
        s.insert({psum,i});
        if (s.find(psum)!=s.end())
        ans=max(ans, i-s[psum]);
    }
    return ans;
}
int main(){
    int arr[]={0,1};
    int n=sizeof(arr)/sizeof(int);
    cout << longest1(arr, n);

    return 0;
}