#include <iostream>
#include <string>
using namespace std;
int fun(int arr[], int n, int val){
    if (val==0 || n==0)
    return 0;
    int res=0;
    int noninc=fun(arr, n-1, val);
    if (noninc!=0)
    res=noninc;
    if (val>arr[n-1]){
        int inc=fun(arr, n, val-arr[n-1]);
        if (noninc!=0){
            if (inc!=0)
            res=min(res, inc+1);
        }
    else
    res=inc+1;
    }
    return res;
}
int main(){
    int arr[]={25, 10, 5};
    int n=sizeof(arr)/sizeof(int);
    cout << fun(arr, n, 30);

    return 0;
}