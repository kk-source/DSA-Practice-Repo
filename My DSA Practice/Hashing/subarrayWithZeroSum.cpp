#include <bits/stdc++.h>
using namespace std;
bool subarray(int arr[], int n){ // naive.
    for (int i=0;i<n;i++){ // to set starting position.
        int subarraysum=0;
        for (int j=i;j<n;j++){
            subarraysum+=arr[j];
            if (subarraysum==0)
            return true;
        }
    }
    return false;
}
bool subarray1(int arr[], int n){
    unordered_set<int> s;
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
        if (s.find(sum)!=s.end() || sum==0)
        return true;
        s.insert(sum);
    }
    return false;
}
int main(){
    int arr[]={-1,1};
    int n=sizeof(arr)/sizeof(int);
    cout << subarray(arr, n);  
    return 0;
}