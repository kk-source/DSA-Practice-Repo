#include <iostream>
#include <string>
using namespace std;
int maxConsecutive(bool arr[], int n){
    int ans=0;
    int curr_sum1count=0;
    for (int i=0;i<n;i++){
        if (arr[i]){
        curr_sum1count++;
        ans=max(ans,curr_sum1count);
        }
        else
        curr_sum1count=0;
    }
    // ans=max(ans,curr_sum1count);
    return ans;
}
int maxConsecutive1(bool arr[], int n){
    int ans=0;
    int i=0;
    int curr_sum1count=0;
    while(i<n){
        while(arr[i] && i<n){
        curr_sum1count++;
        ans=max(ans,curr_sum1count);
        i++;
        }
        curr_sum1count=0;
        i++;
    }
    return ans;
}
int main(){
    bool arr[]={1,0,1,1,1,1,1,1,1};
    // bool arr[]={1,1,1,1,0,0,1,0,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << maxConsecutive(arr, n);

    return 0;
}