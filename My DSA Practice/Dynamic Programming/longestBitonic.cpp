#include <iostream>
#include <string>
using namespace std;
int findc(int l, int r, int x, int arr[]){
    int res;
    while(l<=r){
        int m=l+(r-l)/2;
        if (arr[m]>=x){
            res=m;
            r=m-1;
        }
        else
        l=m+1;
    }
    return res;
}
int findc1(int l, int r, int x, int arr[]){
    int res;
    while(l<=r){
        int m=l+(r-l)/2;
        if (arr[m]>=x){
            res=m;
            l=m+1;
        }
        else
        r=m-1;
    }
    return res;
}
int count(int arr[], int n){
    int llis[n], rlis[n];
    int ltail[n], rtail[n];
    ltail[0]=arr[0]; rtail[n-1]=arr[n-1];
    llis[0]=1; rlis[n-1]=1;
    int len=1;
    for (int i=1;i<n;i++){
        if (arr[i]>ltail[len-1]){
            ltail[len]=arr[i];
            len++;
        llis[i]=len;
        }
        else{
            int ind=findc(0, len-1, arr[i], ltail);
            ltail[ind]=arr[i];
            llis[i]=ind+1;
        }
    }
    len=n-2;
    for (int i=n-2;i>=0;i--){
        if (arr[i]>rtail[len+1]){
            rtail[len]=arr[i];
            len--;
            rlis[i]=n-len-1;
        }
        else{
            int ind=findc1(len+1, n-1, arr[i], rtail);
            rtail[ind]=arr[i];
            rlis[i]=n-ind;
        }
    }
    int res=0;
    for (int i=0;i<n;i++){
        res=max(res, llis[i]+rlis[i]-1);
    }
    return res;
}
int main(){
    int arr[]={1,11, 2, 10, 4, 5, 2, 1};
    int n=sizeof(arr)/sizeof(int);
    cout << count(arr, n);

    return 0;
}