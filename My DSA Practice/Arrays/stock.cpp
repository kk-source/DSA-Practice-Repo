#include <iostream>
#include <vector>
using namespace std;
int stock(int arr[], int n){
    int profit=0;
    for (int i=1;i<n;i++){
        if (arr[i-1]<arr[i])
            profit+=arr[i]-arr[i-1];
    }
    return profit;
}
vector<vector<int>> stockBuySell(vector<int> arr, int n){
        vector<vector<int>> temp;
        int minval=arr[0];
        int l=0,r=0;
        for (int i=1;i<n;i++){
            if(arr[i]>=minval){
                r++;
            }
            else if(arr[i]<minval){
                if (r>l){
                    temp.push_back({l,r});
                }
                r=i;
                l=i;
            }
                minval=arr[i];
        }
        if (r>l){
                    temp.push_back({l,r});
                }
        if (temp.empty())
        return {};
        else
        return temp;
    }
int main(){
    int arr[]={1,5,3,8,12};
    // int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << stock(arr, n);
    return 0;
}