#include <iostream>
#include <string>
using namespace std;
void segPosNeg(int arr[], int n){ // lomuto
    int j=0,i=0;
    while(i<n){
        if (arr[i]<0){
            swap(arr[i],arr[j]);
            j++;
        }
        i++;
    }
}
void segPosNeg1(int arr[], int n){ // hoare's
    int i=0,j=n-1;
    while(true){
        while(arr[i]<0 && i<=j) i++;
        
        while(arr[j]>0 && j>=i) j--;
        if (i>j)
            return;
        swap(arr[i],arr[j]);
    }
    
}
int main(){
    int arr[]={-12,18,10,-15};
    int n=sizeof(arr)/sizeof(arr[0]);
    segPosNeg1(arr, n);
    for (int i:arr)
    cout << i << " ";
    return 0;
}