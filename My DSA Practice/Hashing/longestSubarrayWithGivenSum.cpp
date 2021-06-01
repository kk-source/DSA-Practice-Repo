#include <bits/stdc++.h>
using namespace std;
int subarray(int arr[], int n, int sum){ // naive
    int ans=0;
    for (int i=0;i<n;i++){
        int psum=0;
        for (int j=i;j<n;j++){
            psum+=arr[j];
            if (psum==sum)
                ans=max(ans,j-i+1);
        }
    }
    return ans;
}
int subarray1(int arr[], int n, int sum){
    unordered_map <int, int> s;
    int psum=0, res=0;
    for (int i=0;i<n;i++){
        psum+=arr[i];
        if (psum==sum)
            res=i+1;
        if (s.find(psum)==s.end()) // inserting before to get s[psum-sum] in next step.
            s.insert({psum, i});
        if (s.find(psum-sum)!=s.end())
            res=max(res, i-s[psum-sum]);
    }
    return res;
}
int main(){
    int arr[]={8,3,1,5,-6,6,2,2};
    int n=sizeof(arr)/sizeof(int);
    cout << subarray1(arr, n, 4);
    return 0;
}