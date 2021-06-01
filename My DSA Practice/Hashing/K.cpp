#include <bits/stdc++.h>
using namespace std;
void occ(int arr[], int n, int k){ // pure naive.
    int c=n/k;
    for (int i=0;i<n;i++){
        bool flag=false;
        for (int j=0;j<i;j++){
            if (arr[i]==arr[j]){
                flag=true;
                break;
            }
        }
            if (flag==false){
                int count=0;
                for (int j=i;j<n;j++){
                    if (arr[j]==arr[i])
                    count++;
                }
                if (count>c)
                cout << arr[i] << " ";
            }
        }
}
void occ1(int arr[], int n, int k){ // naive.
    sort(arr, arr+n);
    int i=1, count=1;
    while(i<n){
        while((i<n) && arr[i]==arr[i-1]){
            count++; 
            i++;
        }
        if (count>n/k)
            cout << arr[i-1] << " ";
        count=1; 
        i++;
    }
}
void occ2(int arr[], int n, int k){ // naive using map
    int c=n/k;
    unordered_map<int, int> s;
    for (int i=0;i<n;i++){
        s[arr[i]]++;
    }
    for (auto i:s)
    if (i.second>c)
    cout << i.first << " ";
}
void occ3(int arr[], int n, int k){ // moorey's voting algo.
    unordered_map<int, int> m;
    for (int i=0;i<n;i++){
        if (m.find(arr[i])!=m.end())
        m[arr[i]]++;
        else if (m.size()<=k-1)
        m.insert({arr[i], i});
        else{
            for (auto j:m){
                j.second--;
                if (j.second==0){
                    m.erase(j.first);
                }
            }
        }
    }
    for (auto j:m){
        int count=0;
        for (int i=0;i<n;i++){
            if (arr[i]==j.first)
            count++;
        }
        if (count>n/k)
        cout << j.first << " ";
    }
}
int main(){
    int arr[]={30,10,20,20,10,20,30,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    occ3(arr, n, 4);

    return 0;
}