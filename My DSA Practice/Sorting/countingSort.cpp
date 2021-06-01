#include <iostream>
using namespace std;
void countsort(int arr[],int n, int k){ //cannot be used as general purpose algo.
    int count[k];
    for (int i=0;i<k;i++){
        count[i]=0;
    }
    for (int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int index=0;
    for (int i=0;i<k;i++){
        while(count[i]!=0){
        arr[index++]=i;
        count[i]--;
        }
    }
}
void countsort1(int arr[],int n, int k){ // general purpose.
    int count[k];
    for (int i=0;i<k;i++){
        count[i]=0;
    }
    for (int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for (int i=1;i<k;i++){
        count[i]=count[i]+count[i-1];
    }
    // int index=0;
    int output[n];
    for (int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for (int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int main(){
    int arr[]={1,3,3,4,4,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    countsort1(arr, n, 5);
    for (int i: arr)
    cout << i << " ";
    return 0;
}