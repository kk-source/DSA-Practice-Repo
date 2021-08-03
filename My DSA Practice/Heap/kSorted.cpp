#include <bits/stdc++.h>
using namespace std;
void fun(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k+1); // O(k).
    int ind=0;
    for (int i=k+1;i<n;i++){
        arr[ind++]=pq.top(); // (n-k)log(k)
        pq.pop();
        pq.push(arr[i]);
    }
    // cout << pq.size() << endl;
    while(pq.empty()==false){
        arr[ind++]=pq.top(); // klog(k)
        pq.pop();
    }
}
int main(){
    int arr[]={9,8, 7, 18, 19, 17};
    int n=sizeof(arr)/sizeof(int);
    int k=2;
    fun(arr, n, k);
    for (auto i:arr)
    cout << i << " ";
    return 0;
}