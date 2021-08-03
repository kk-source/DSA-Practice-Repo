#include <bits/stdc++.h>
using namespace std;
int fun(int arr[], int n, int sum){
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);// O(n).
    int ans=0;
    while(sum-pq.top()>=0){ // O(ans*logn).
        ans++;
        sum-=pq.top();
        pq.pop();
    }
    return ans;
}
int main(){
    int arr[]={1,12, 5, 111, 200};
    int n=sizeof(arr)/sizeof(int);
    cout << fun(arr, n, 10);
    return 0;
}