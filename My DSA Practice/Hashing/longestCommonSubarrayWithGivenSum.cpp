#include <bits/stdc++.h>
using namespace std;
int longest(int arr[], int brr[], int n){ // naive
    int ans=0;
    for (int i=0;i<n;i++){
        int sum1=0, sum2=0;
        for (int j=i;j<n;j++){
            sum1+=arr[j];
            sum2+=brr[j];
            if (sum1==sum2)
                ans=max(j-i+1,ans);
        }
    }
    return ans;
}
int longest1(int arr[], int brr[], int n){
    int temp[n];
    for (int i=0;i<n;i++){
        temp[i]=arr[i]=brr[i];
    }
    int ans=0, psum=0;
    unordered_map<int, int> s;
    for (int i=0;i<n;i++){
        psum+=temp[i];
        if (psum==0)
        ans=i+1;
        if (s.find(psum)==s.end())
        s.insert({psum, i});
        if (s.find(psum)!=s.end())
        ans=max(ans, s[psum]);
    }
    return ans;
}
int main(){
    int arr[]={0,1,0,1,1,1,1};
    int brr[]={1,1,1,1,1,0,1};
    int n=sizeof(arr)/sizeof(int);  
    cout << longest1(arr, brr, n);
    return 0;
}