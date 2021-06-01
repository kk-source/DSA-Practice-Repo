#include <iostream>
#include <algorithm>
using namespace std;

int guests(int arr[], int dep[], int n){
    sort(arr,arr+n); sort(dep,dep+n);
    int i=1,j=0; // i=1 because we consider first guest has arrived.
    int curr=1,ans=1;
    while(i<n && j<n){
        if (arr[i]<=dep[j]){
            curr++;
            ans=max(curr, ans);
            i++;
        }
        else if (dep[j]<arr[i]){
            curr--;
            j++;
        }
        // cout << curr << " ";
    }
    return ans;
}
int main(){
    int arr[]={900,940,950,1100,1500,1800};
    int dep[]={910,1200,1120,1130,1900,2000};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << guests(arr, dep, n);
    return 0;
}