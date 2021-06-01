#include <iostream>
#include <string>
using namespace std;
void selection(int arr[], int n){
    for (int i=0;i<n-1;i++){
        int ind = i;
        int j;
        for (j=i+1;j<n;j++){
            if (arr[j]<arr[ind])
                ind=j;
        }
        swap(arr[ind],arr[i]);
    }
}
int main(){
    int arr[]={2,10,8,7};
    int n=4;
    selection(arr, n);
    for (int i:arr)
    cout << i << " ";

    return 0;
}