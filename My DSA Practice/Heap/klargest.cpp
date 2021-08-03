#include <bits/stdc++.h>
using namespace std;
void fun(int arr[], int n, int k){
    priority_queue<int> pq(arr, arr+n);// O(n).
    while(k--){ // O(ans*logn).
        cout << pq.top() << " ";
        pq.pop();
    }
}
void fun1(int arr[], int n, int k){ // efficient.
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k);// O(k).
    for (int i=k;i<n;i++){
        if (arr[i]>pq.top()){ // O((n-k)*logk)
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(pq.empty()==false){ // O(klogk).
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main(){
    int arr[]={5, 15, 10, 20, 8, 25, 18};
    int n=sizeof(arr)/sizeof(int);
    fun(arr, n, 3);
    cout << endl;
    fun1(arr, n, 3);
    return 0;
}