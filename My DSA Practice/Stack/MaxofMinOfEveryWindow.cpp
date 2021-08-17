#include <bits/stdc++.h>
using namespace std;
// Naive.
vector <int> maxOfMin(int arr[], int n)
    { // (n-k)+2(n-k)+3(n-k)+....=O(n^3).
        vector<int> ans;
        for (int l=1;l<=n;l++){
            int maxval=INT_MIN;
        for (int i=0;i<=n-l;i++){
            int minval=INT_MAX;
            for (int j=0;j<l;j++){
                minval=min(minval, arr[i+j]);
            }
            maxval=max(maxval, minval);
        }
        ans.push_back(maxval);
    }
    return ans;
    }
// optimised.
void maxOfMin1(int arr[], int n){
    // finding previous smaller.
    vector<int> ps;
    stack<int> st;
    for (int i=0;i<n;i++){
        while(st.empty()==false && arr[st.top()]>=arr[i]){
            st.pop();
        }
        int temp=(st.empty())? -1:st.top();
        ps.push_back(temp);
        st.push(i);
    }

    while(st.empty()==false)
    st.pop();
    // finding next smaller.
    vector<int> ns;
    for (int i=n-1;i>=0;i--){
        while(st.empty()==false && arr[st.top()]>=arr[i])
        st.pop();
        int temp=st.empty()? n:st.top();
        ns.push_back(temp);
        st.push(i);
    }
    reverse(ns.begin(), ns.end());

    vector<int> ans(n, -1);
    for (int i=0;i<n;i++){
        int len=ns[i]-ps[i]-1;
        ans[(len)-1]=max(ans[(len)-1],arr[i]);
    }
    // next is always smaller than or equal to the current.
    for (int i=n-2;i>=0;i--)
    ans[i]=max(ans[i], ans[i+1]);
    return ans;
}
int main(){
    int arr[]={10,20,30,50,10,70,30};
    // int arr[]={10,20,30,40,50};
    maxOfMin1(arr, 7);
    return 0;
}