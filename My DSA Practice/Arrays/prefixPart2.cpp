#include <iostream>
#include <vector>
using namespace std;
int prefixPart2(int L[], int R[], int n){// naive approach.
    vector<int>arr(1000,0);
    int ans=0;
    int ind=0;
    for (int i=0;i<n;i++){
        for (int j=L[i];j<=R[i];j++){
            arr[j]++;
            if (arr[j]>ans){
                ind=j;
                ans=arr[j];
            }
        }
    }
    return ind;
}
int prefixPart2Most(int L[], int R[], int n){// optimised approach.
    vector<int>arr(1000,0);
    for (int i=0;i<n;i++){
        arr[L[i]]++;
        arr[R[i]+1]--;
    }
    int curr=arr[0],res=0;
    for (int i=1;i<1000;i++){
        arr[i]+=arr[i-1];
        if (curr<arr[i]){
            curr=arr[i];
            res=i;
        }
    }
    return res;
}
bool prefixPart2ques1(int arr[], int n){// optimised approach
        int sum[n];
        sum[0]=arr[0];
        for (int i=1;i<n;i++){
            sum[i]=sum[i-1]+arr[i];
        }
        if (sum[n-1]==0 || sum[n-1]%3!=0)
            return false;
        bool f1=false,f2=false;
        for (int i=0;i<n-1;i++){
            if (sum[i]==sum[n-1]/3)
                f1=true;
            if (sum[i]==sum[n-1]*2/3 && f1)
                f2=true;
        }
        return (f1 && f2);
    }

int main(){
    // int L[]={1,2,5,6};
    // int R[]={4,8,7,18};
    int L[]={1,2,5,15};
    int R[]={5,8,7,18};
    int n=sizeof(L)/sizeof(L[0]);
    // cout << prefixPart2Most(L, R, n);
    // int arr[]={5,2,6,1,1,1,5};
    // int arr[]={0,2,1,-6,6,-7,9,1,2,0,1};
    int arr[]={1,-1,1,-1};
    n=sizeof(arr)/sizeof(arr[0]);
    cout << prefixPart2ques1(arr, n);
    return 0;
}

