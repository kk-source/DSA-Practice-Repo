#include <iostream>
#include <string>
using namespace std;
int longest(int arr[], int n){ // theta(n^2)
    int res=1;
    for (int i=0;i<n-1;i++){
        int curr_sum=1;
        for (int j=i+1;j<n;j++){
            if (arr[j]%2!=arr[j-1]%2)
            curr_sum++;
            else 
            break;
        }
        res=max(res,curr_sum);
    }
    return res;
}
int longestMost(int arr[], int n){ // theta(n)
    int res=1;
    int curr_sum=1;
    for (int i=1;i<n;i++){
        if (arr[i]%2!=arr[i-1]%2){
            curr_sum++;
            res=max(res,curr_sum);
        }
        else
            curr_sum=1;
    }
    return res;
}
int main(){//5,10,20,6,3,8
// 7,10,13,14
    int arr[]={10,12,14,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << longestMost(arr, n);

    return 0;
}