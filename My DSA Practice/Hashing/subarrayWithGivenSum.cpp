#include <bits/stdc++.h>
using namespace std;
bool subarray(int arr[], int n, int sum){ // naive.
    for (int i=0;i<n;i++){ // to set starting position.
        int subarraysum=0;
        for (int j=i;j<n;j++){
            subarraysum+=arr[j];
            if (subarraysum==sum)
            return true;
        }
    }
    return false;
}
bool subarray1(int arr[], int n, int sum){
    unordered_set<int> s;
    int psum=0;
    for (int i=0;i<n;i++){
        psum+=arr[i];
        if (s.find(psum-sum)!=s.end() || psum==sum)
        return true;
        s.insert(psum);
    }
    return false;
}
int main(){
    int arr[]={5,8,6,13,3,-1};
    int n=sizeof(arr)/sizeof(int);
    int sum=2;
    cout << subarray1(arr, n, sum);  
    return 0;
}