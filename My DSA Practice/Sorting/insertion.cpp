#include <iostream>
#include <string>
using namespace std;
void insertion(int arr[], int n){
    for (int i=1;i<n;i++){
        int prev=i-1;
        int e=arr[i];
            while(prev>=0 && e<arr[prev]){
                arr[prev+1]=arr[prev];
                prev--;
            }
            arr[prev+1]=e;
    }
}
int main(){
    int arr[]={2,10,8,7};
    int n=4;
    insertion(arr, n);
    for (int i:arr)
    cout << i << " ";

    return 0;
}