#include <bits/stdc++.h>
using namespace std;

void fun1(int arr[], int n, int k, int x){
    priority_queue<pair<int, int>> pq;
    for (int i=0;i<k;i++){ // klogk
        pq.push({abs(x-arr[i]), i});
    }
    for (int i=k;i<n;i++){ // (n-k)logk
        int diff=abs(arr[i]-x);
        if (pq.top().first>diff){
            pq.pop();
            pq.push({diff, i});
        }
    }
    while(k--){ // klogk
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}
int main(){
    int arr[]={10, 15, 7, 3, 4};
    int n=sizeof(arr)/sizeof(int);
    fun1(arr, n, 2, 8);
    return 0;
}