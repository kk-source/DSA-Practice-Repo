#include <iostream>
#include <string>
using namespace std;
int oneinthree(int arr[], int n){
    int store[64];
    for (int i=0;i<64;i++){
        store[i]=0;
    }
    for (int i=0;i<n;i++){
        int j=0;
        while(arr[i]>0){
            if ((arr[i]&1))
            store[j]++;
            j++;
            arr[i]=arr[i]>>1;
        }
    }
    int ans=0;
    bool flag=false;
    int j;
    for (int i=63;i>=0;i--){
        if (store[i]%3==1 && !flag){
            flag=true;
            j=1;
        }
        if (flag && store[i]%3){
            ans+=j;
        }
        if (flag)
            j*=2;
    }
    return ans;
}
int main(){
    int arr[]={1,2,3,100,1,2,3,1,2,3};
    int n=10;
    cout << oneinthree(arr, n);

    return 0;
}