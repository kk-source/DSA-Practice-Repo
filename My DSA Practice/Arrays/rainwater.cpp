#include <iostream>
#include <string>
using namespace std;
int rain(int arr[], int n){
    int ans=0;
    int s=0;
    int e=n-1;
    while(1<e-s){
    int minval=min(arr[s],arr[e]);
        if (arr[s+1]<minval && arr[e-1]<minval){
            int vol=0;
            for (int i=s+1;i<e;i++)
            vol+=minval-arr[i];
            // storing max vol of water in ans. 
            ans=max(ans,vol);
            if (arr[s+1]<arr[e-1])
            e--;
            else
            s++;
        }
        else if(arr[s+1]<arr[e-1])
            e--;
        else
            s++;
    }
    return ans;
}
int rain1(int arr[], int n){
    int ans=0;
    for (int i=1;i<n-1;i++){
        int lmax=arr[i];
        for (int j=0;j<i;j++)
            lmax=max(lmax,arr[j]);
        
        int rmax=arr[i];
        for (int j=i+1;j<n;j++)
            rmax=max(rmax,arr[j]);
        
        ans+=min(lmax,rmax)-arr[i];
    }
    return ans;
}
int rainMost(int arr[], int n){ // we calculate lmax and rmax for each index before hand so as to make time complexity theta(n) and theta(n) space.
    int res=0;
    int lmax[n],rmax[n];

    lmax[0]=arr[0];
    for (int i=1;i<n;i++)
    lmax[i]=max(lmax[i-1],arr[i]);

    rmax[n-1]=arr[n-1];
    for (int i=n-2;i>=0;i--)
    rmax[i]=max(rmax[i+1],arr[i]);

    for (int i=1;i<n-1;i++)
    res+=min(lmax[i],rmax[i])-arr[i];
    
    return res;
}
int main(){// 3,0,1,2,5
    int arr[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << rainMost(arr, n);

    return 0;
}