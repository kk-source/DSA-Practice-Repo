#include <iostream>
#include <string>
using namespace std;
void segonestwosthrees(int arr[], int n){
    int low=0,mid=0,hi=n-1;
    while(mid<=hi){
        if (arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid]==1)
            mid++;
        else{
            swap(arr[hi],arr[mid]);
            hi--;
        }
    }
}
int main(){
    int arr[]={0,1,0,2,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    segonestwosthrees(arr, n);
    for (int i:arr)
    cout << i << " ";
    return 0;
}