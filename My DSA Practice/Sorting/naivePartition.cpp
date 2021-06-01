#include <iostream>
#include <string>
using namespace std;
void partition(int arr[], int l, int h, int k){
    int temp[h-l+1];
    int ind=0;
    for (int i=l;i<=h;i++){
        if (arr[i]<=arr[k]){
            temp[ind++]=arr[i];
        }
    }
    for (int i=l;i<=h;i++){
        if (arr[i]>arr[k]){
            temp[ind++]=arr[i];
        }
    }
    ind=0;
    for (int i=0;i<h-l+1;i++)
    cout << temp[i] << " ";
}
int main(){
    int arr[]={3,8,7,12,2,7};
    int n=6, k=5;
    partition(arr, 0, n-1, k);

    return 0;
}