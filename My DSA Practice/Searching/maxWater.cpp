#include <iostream>
#include <string>
using namespace std;
int maxWater(int arr[], int n) 
    { 
        if (n==1 || n==2)
        return 0;
        int low=0, high=n-1, ans=0;
        while(low<high){
            ans=max(ans, min(arr[low],arr[high])*(high-low-1));
            if (arr[high]>arr[low])
            low++;
            else
            high--;
        }
        return ans;
    } 

int main(){
    int arr[]={2,1,3,4,6,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << maxWater(arr, n);
    return 0;
}