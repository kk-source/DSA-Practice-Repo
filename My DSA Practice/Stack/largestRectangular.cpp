#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int area(int arr[], int n){
    int ans=0;
    for (int i=0;i<n;i++){
    int minval=arr[i];
        for (int j=i;j<n;j++){
            minval=min(minval, arr[j]);
            ans=max(ans, (j-i+1)*minval);
        }
    }
    return ans;
}
int area1(int arr[], int n){ // let ith index be the minimum height histogram.
    int ans=0;
    for (int i=0;i<n;i++){
    int curr=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>=curr){
            curr+=arr[i];
            j++;
        }
        j=i+1;
        while(j<n && arr[j]>=curr){
            curr+=arr[i];
            j++;
        }
        ans=max(ans, curr);
    }
    return ans;
}
int area2(int arr[], int n){ // three traversals.
    int ans=0;
    vector<int> ps(n, -1);
    stack<int> s;
    for (int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i])
        s.pop();
        if (s.empty()==false){
            ps[i]=s.top();
        }
        s.push(i);
    }

    while(s.empty()==false)
    s.pop();

    vector<int> ns(n, n);

    for (int i=n-1;i>=0;i--){
        while(s.empty()==false && arr[s.top()]>=arr[i])
        s.pop();
        if (s.empty()==false){
            ns[i]=s.top();
        }
        s.push(i);
    }

    for (int i=0;i<n;i++)
        ans=max(ans, (ns[i]-ps[i]-1)*arr[i]);

    return ans;
}
// maintain an ascending stack from bottom and if ith element is greater than previous one then it means this is next smainter
// and the previous smainter can be found by next element in the stack after it.
int area3(int arr[], int n){ // best.
    int ans=0; 
    stack<int> s;
    for (int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i]){
        int st=s.top();
        s.pop();
        int curr=arr[st]*(s.empty()? i:i-s.top()-1);
        ans=max(ans, curr);
        }
    s.push(i);
    }
    while(s.empty()==false){
        int temp=s.top();
        s.pop();
        int curr=arr[temp]*(s.empty()? n:n-s.top()-1);
        ans=max(ans, curr);
    }
    return ans;
}
int main(){
    int arr[]={6,2,5,4,1,5,6};
    int n=sizeof(arr)/sizeof(int);
    cout<< area3(arr, n);
    return 0;
}