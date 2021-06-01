#include <iostream>
#include <string>
using namespace std;
int missingNumber(int arr[], int n) 
    { 
        int res=0;
        for (int i=0;i<n;i++){
            if (arr[i]<=0){
                swap(arr[i],arr[res]);
                res++;
            }
        }
        for (int i=res;i<n;i++){
            if (res-1+abs(arr[i])<n){
                arr[res-1+abs(arr[i])]=-arr[res-1+abs(arr[i])];
            }
        }
        for (int i=res;i<n;i++){
            if (arr[i]>0){
                return i-res+1;
            }
        }
        return n-res+1;
    }
int main(){
    int arr[]={-1,3,5,1,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << missingNumber(arr, n);
    return 0;
}