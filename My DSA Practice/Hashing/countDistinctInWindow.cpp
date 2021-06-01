#include <bits/stdc++.h>
using namespace std;
void count(int arr[], int n, int k){ // pure naive.
    for (int i=0;i<=n-k;i++){
        int count=0;
        for (int j=0;j<k;j++){
            bool flag=false;
            for (int p=0;p<j;p++){
                if (arr[i+j]==arr[i+p]){
                    flag=true;
                    break;
                }
            }
            if (flag==false)
            count++;
        }
        cout << count << " ";
    }
}
void count1(int arr[], int n, int k){ // naive
    int l=0, r=k-1;
    while(r<n){
        unordered_set<int> s;
        for (int i=l;i<=r;i++)
            s.insert(arr[i]);
        cout << s.size() << " ";
        r++; l++;
    }
}
void count2(int arr[], int n, int k){
    unordered_map<int, int> s;
    for (int i=0;i<k;i++)
        s[arr[i]]++;
    cout << s.size() << " ";
    int l=0, r=k;
    while(r<n){
        s[arr[l]]--;
        if (s[arr[l]]==0)
            s.erase(arr[l]);
        s[arr[r]]++;
        cout << s.size() << " ";
        r++; l++;
    }
}
int main(){
    int arr[]={10,10,10,10};
    int n=sizeof(arr)/sizeof(int);
    count2(arr, n, 3);

    return 0;
}