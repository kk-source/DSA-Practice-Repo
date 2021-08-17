#include <iostream>
#include <string>
using namespace std;
int sliding(int arr[], int n, int k){
    int ans=INT_MIN;
    // int curr_sum=0;
    for (int i=0;i<n-k+1;i++)
    {   int curr_sum=0;
        for (int j=i;j<i+k;j++){
            curr_sum+=arr[j];
        }
        ans=max(ans,curr_sum);
        // cout << ans << " ";
    }
    return ans;
}
int slidingMost(int arr[], int n, int k){
    int ans;
    int curr_sum=0;
    for (int i=0;i<k;i++){
        curr_sum+=arr[i];
    }
    ans=curr_sum;

    for (int i=k;i<n;i++){
        curr_sum+=arr[i]-arr[i-k];
        ans=max(ans,curr_sum);
    }
    return ans;
}
// we are given sum and we have to find if there exists a subarray of length k whose sum is equal to given sum.
int slidingMostques1(int arr[], int n, int k, int sum){ 
    int curr_sum=0;
    for (int i=0;i<k;i++)
        curr_sum+=arr[i];
    
    for (int i=k;i<n;i++){
        curr_sum+=arr[i]-arr[i-k];
        if (sum==curr_sum)
        return true;
    }
    return false;
}
bool slidingMostques2(int arr[], int n, int sum){ 
    int res=0,start=0;
    for (int i=0;i<n;i++){
        cout << res << " ";
        if (res+arr[i]<=sum){
            res+=arr[i];
        }
        else
        {
            res+=arr[i];
            while(res>sum)
            {
                res-=arr[start];
                start++;
            }
        }
        if (res==sum){
            // cout << start+1 << " " << i+1;
            return true;
        }
    }
    return false;
}
bool temp(int arr[], int n, int sum){ // above code and this code are similar.
    int res=0;
    int start=0;
    for (int i=0;i<n;i++){
        res+=arr[i];
        if (res>sum){
            while(res>sum){
                res-=arr[start];
                start++;
            }
        }
        if (res==sum){
        cout << start+1 << " " << i+1; // return start+1 and i+1
        return true;
        }
    }
    cout << "sorry";
    return false;
}
int main(){
    int arr[]={1,4,20,3,10,5};
    // int arr[]={4,7,-3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    // cout << slidingMostques1(arr, n, 3, 54);
    cout << "enter num " << endl;
    int sum;
    cin>>sum;
    temp(arr, n, sum);

    return 0;
}