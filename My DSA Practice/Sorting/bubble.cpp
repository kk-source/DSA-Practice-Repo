#include <iostream>
#include <string>
using namespace std;
void bubble(int arr[], int n){
    for (int j=n-1;j>0;j--){
        for (int i=0;i<j;i++){
        if (arr[i]>arr[i+1])
        swap(arr[i], arr[i+1]);
    }
    }
}
int main(){
    int arr[]={2,10,8,7};
    int n=4;
    bubble(arr, n);
    for (int i:arr)
    cout << i << " ";
    return 0;
}