#include <iostream>
#include <string>
using namespace std;
int maxIndexDiff(int arr[], int n){
    int Lmin[n],Rmax[n];
    Lmin[0]=arr[0];
    Rmax[n-1]=arr[n-1];
    for (int i=1;i<n;i++){
        Lmin[i]=min(arr[i],Lmin[i-1]);
    }
    for (int i=n-2;i>=0;i--){
        Rmax[i]=max(arr[i],Rmax[i+1]);
    }
    int i=0,j=0,ans=0;
    while(i<n && j<n){
        if (Lmin[i]<Rmax[j]){
            ans=max(ans,j-i);
            j++;
        }
        else
        i++;
    }
    return ans;
}
int main(){
    int arr[]={34, 8, 10, 3, 2, 80, 30, 33};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << maxIndexDiff(arr, n);

    return 0;
}