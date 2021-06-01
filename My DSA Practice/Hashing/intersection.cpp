#include <bits/stdc++.h>
using namespace std;
int intersection(int a[], int b[], int m, int n){ // naive
    int res=0;
    for (int i=0;i<m;i++){
        bool flag=false;
        for (int j=0;j<i;j++){
            if (a[j]==a[i]){
                flag=true;
                break;
            }
        }
            if (flag)
            continue;
            for (int j=0;j<n;j++){
                if (b[j]==a[i]){
                    res++;
                    break;
                }
            }
    }
    return res;
}
int intersection1(int a[], int b[], int m, int n){
    int res=0;
    unordered_set<int> s(a, a+m);
    for (int i=0;i<n;i++){
        if (s.find(b[i])!=s.end()){
        res++;
        s.erase(b[i]);
        }
    }
    return res;
}
int main(){
    int a[]={1,2,3,4,5,1,2,3,6,6,6,74};
    int n=sizeof(a)/sizeof(a[0]);
    int b[]={5,1,2,3,74};
    int m=sizeof(b)/sizeof(b[0]);
    cout << intersection1(a, b, n, m);
    return 0;
}