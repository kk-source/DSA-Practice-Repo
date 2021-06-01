#include <bits/stdc++.h>
using namespace std;
int countDistinct(int arr[], int n){ // naive
    int res=1;
    for (int i=1;i<n;i++){
        bool flag=false;
        for (int j=0;j<i;j++){
            if (arr[j]==arr[i]){
                flag=true;
                break;
            }
        }
        if (flag==false)
        res++;
    }
    return res;
}
int countDistinct1(int arr[], int n){
    unordered_set<int> s(arr, arr+n);
    return s.size();
}
int main(){
    int arr[]={1,2,3,4,5,0,1,2,3,76};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << countDistinct1(arr, n);

    return 0;
}