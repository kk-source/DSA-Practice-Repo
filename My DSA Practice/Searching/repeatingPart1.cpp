#include <iostream>
#include <string>
using namespace std;
int repeat(int arr[], int n){// array is changed.
    int ans;
    int m=n-1;
    for (int i=0;i<n;i++){
        arr[arr[i]%m]+=m;
    }
    for (int i=0;i<n;i++){
        if (arr[i]/m>1)
        ans = i;
    }
    for (int i=0;i<n;i++){
        arr[i]=arr[i]%m;
    }
    return ans;
}
int repeat1(int arr[], int n){ // must not contain 0.
    int slow=arr[0], fast=arr[0];
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    }
    while(slow!=fast);
    slow=arr[0];
    while(slow!=fast){
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
}
int repeat2(int arr[], int n){ // main solution.
    int slow=arr[0]+1, fast=arr[0]+1;
    do{
        slow=arr[slow]+1;
        fast=arr[arr[fast]+1]+1;
    }
    while(slow!=fast);
    slow=arr[0]+1;
    while(slow!=fast){
        slow=arr[slow]+1;
        fast=arr[fast]+1;
    }
    return slow-1;
}
int main(){
    int arr[]={0,2,1,3,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << repeat2(arr, n);
    
    return 0;
}