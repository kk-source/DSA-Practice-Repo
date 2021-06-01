#include <bits/stdc++.h>
using namespace std;
int unionOfArrays(int a[], int b[], int m, int n){ // naive
    int index=0, arr[m+n];
    for (int i=0;i<m;i++){
        bool flag=false;
        for (int j=0;j<index;j++){
            if (arr[j]==a[i]){
                flag=true;
                break;
            }
        }
        if (flag)
        continue;
        arr[index++]=a[i];
    }
    for (int i=0;i<n;i++){
        bool flag=false;
        for (int j=0;j<index;j++){
            if (arr[j]==b[i]){
                flag=true;
                break;
            }
        }
        if (flag)
        continue;
        arr[index++]=b[i];
    }
    return index;
}
int unionOfArrays1(int a[], int b[], int m, int n){
    unordered_set<int> s(a, a+m);
    s.insert(b,b+n);
    return s.size();
}
int main(){
    int a[]={1,2,3,4,5,1,2,};
    int n=sizeof(a)/sizeof(a[0]);
    int b[]={5,1,2,3,74};
    int m=sizeof(b)/sizeof(b[0]);
    cout << unionOfArrays1(a, b, n, m);
    return 0;
}