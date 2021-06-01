#include <iostream>
#include <string>
using namespace std;
void move(int arr[], int n){ // O(n^2)
    for (int i=0;i<n;i++){
        if (arr[i]==0){
            for (int j=i+1;j<n;j++){
                if (arr[j]!=0){
                swap(arr[i],arr[j]);
                break;
                }
            }
        }
    }
}
void moveMost(int arr[], int n){ // O(n)
    int count=0;
    for (int i=0;i<n;i++){
        if (arr[i]!=0){
            swap(arr[count],arr[i]);
            count++;
        }
    }
}
int main(){
    int arr[]={1,0,4,0,0,45,0,3};
    // int arr[]={10,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    moveMost(arr, n);
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}